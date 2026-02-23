import errno
from adafruit_wiznet5k.adafruit_wiznet5k_socket import socket, SOCK_STREAM
import adafruit_wiznet5k.adafruit_wiznet5k_socket as _socket
from micropython import const

the_interface = None # pylint: disable=invalid-name

def _is_ipv4_string(ipv4_address: str) -> bool:
        """Check for a valid IPv4 address in dotted-quad string format
        (for example, "123.45.67.89").

        :param: str ipv4_address: The string to test.

        :return bool: True if a valid IPv4 address, False otherwise.
        """
        octets = ipv4_address.split(".", 3)
        if len(octets) == 4 and "".join(octets).isdigit():
            if all((0 <= int(octet) <= 255 for octet in octets)):
                return True
        return False

def gethostbyname(hostname: str) -> str:
    """
    Translate a host name to IPv4 address format. The IPv4 address is returned as a string, such
    as '100.50.200.5'. If the host name is an IPv4 address itself it is returned unchanged.

    :param str hostname: Hostname to lookup.

    :return str: IPv4 address (a string of the form '0.0.0.0').
    """
    if _is_ipv4_string(hostname):
        return hostname
    address = _the_interface.get_host_by_name(hostname)
    address = "{}.{}.{}.{}".format(address[0], address[1], address[2], address[3])
    return address

class Purpose:
    """SSLContext purpose flags with X509v3 Extended Key Usage objects
    """
    SERVER_AUTH = '1.3.6.1.5.5.7.3.1'
    CLIENT_AUTH = '1.3.6.1.5.5.7.3.2'

class SSLObject:
    """This class implements an interface on top of a low-level SSL object as
    implemented by OpenSSL. This object captures the state of an SSL connection
    but does not provide any network IO itself. IO needs to be performed
    through separate "BIO" objects which are OpenSSL's IO abstraction layer.

    This class does not have a public constructor. Instances are returned by
    ``SSLContext.wrap_bio``. This class is typically used by framework authors
    that want to implement asynchronous IO for SSL through memory buffers.

    When compared to ``SSLSocket``, this object lacks the following features:

     * Any form of network IO, including methods such as ``recv`` and ``send``.
     * The ``do_handshake_on_connect`` and ``suppress_ragged_eofs`` machinery.
    """
    def __init__(self, *args, **kwargs):
        raise TypeError("Instances are returned by SSLContext.wrap_bio().")

    @classmethod
    def _create(cls, incoming, outgoing, server_side=False,
                 server_hostname=None, session=None, context=None):
        self = cls.__new__(cls)
        sslobj = context._wrap_bio(
            incoming, outgoing, server_side=server_side,
            server_hostname=server_hostname,
            owner=self, session=session
        )
        self._sslobj = sslobj
        return self

    @property
    def context(self):
        """The SSLContext that is currently in use."""
        return self._sslobj.context

    @context.setter
    def context(self, ctx):
        self._sslobj.context = ctx

    @property
    def session(self):
        """The SSLSession for client socket."""
        return self._sslobj.session

    @session.setter
    def session(self, session):
        self._sslobj.session = session

    @property
    def session_reused(self):
        """Was the client session reused during handshake"""
        return self._sslobj.session_reused

    @property
    def server_side(self):
        """Whether this is a server-side socket."""
        return self._sslobj.server_side

    @property
    def server_hostname(self):
        """The currently set server hostname (for SNI), or ``None`` if no
        server hostname is set."""
        return self._sslobj.server_hostname

    def read(self, len=1024, buffer=None):
        """Read up to 'len' bytes from the SSL object and return them.

        If 'buffer' is provided, read into this buffer and return the number of
        bytes read.
        """
        if buffer is not None:
            v = self._sslobj.read(len, buffer)
        else:
            v = self._sslobj.read(len)
        return v

    def write(self, data):
        """Write 'data' to the SSL object and return the number of bytes
        written.

        The 'data' argument must support the buffer interface.
        """
        pass
        #return self._sslobj.write(self, data)

    def getpeercert(self, binary_form=False):
        """Returns a formatted version of the data in the certificate provided
        by the other end of the SSL channel.

        Return None if no certificate was provided, {} if a certificate was
        provided, but not validated.
        """
        return self._sslobj.getpeercert(binary_form)

    def get_verified_chain(self):
        """Returns verified certificate chain provided by the other
        end of the SSL channel as a list of DER-encoded bytes.

        If certificate verification was disabled method acts the same as
        ``SSLSocket.get_unverified_chain``.
        """
        chain = self._sslobj.get_verified_chain()

        if chain is None:
            return []

        return [cert.public_bytes(_ssl.ENCODING_DER) for cert in chain]

    def get_unverified_chain(self):
        """Returns raw certificate chain provided by the other
        end of the SSL channel as a list of DER-encoded bytes.
        """
        chain = self._sslobj.get_unverified_chain()

        if chain is None:
            return []

        return [cert.public_bytes(_ssl.ENCODING_DER) for cert in chain]

    def selected_npn_protocol(self):
        """Return the currently selected NPN protocol as a string, or ``None``
        if a next protocol was not negotiated or if NPN is not supported by one
        of the peers."""
        warnings.warn(
            "ssl NPN is deprecated, use ALPN instead",
            DeprecationWarning,
            stacklevel=2
        )

    def selected_alpn_protocol(self):
        """Return the currently selected ALPN protocol as a string, or ``None``
        if a next protocol was not negotiated or if ALPN is not supported by one
        of the peers."""
        return self._sslobj.selected_alpn_protocol()

    def cipher(self):
        """Return the currently selected cipher as a 3-tuple ``(name,
        ssl_version, secret_bits)``."""
        return self._sslobj.cipher()

    def shared_ciphers(self):
        """Return a list of ciphers shared by the client during the handshake or
        None if this is not a valid server connection.
        """
        return self._sslobj.shared_ciphers()

    def compression(self):
        """Return the current compression algorithm in use, or ``None`` if
        compression was not negotiated or not supported by one of the peers."""
        return self._sslobj.compression()

    def pending(self):
        """Return the number of bytes that can be read immediately."""
        return self._sslobj.pending()

    def do_handshake(self):
        """Start the SSL/TLS handshake."""
        pass
        #self._sslobj.do_handshake(self)

    def unwrap(self):
        """Start the SSL shutdown handshake."""
        return self._sslobj.shutdown()

    def get_channel_binding(self, cb_type="tls-unique"):
        """Get channel binding data for current connection.  Raise ValueError
        if the requested `cb_type` is not supported.  Return bytes of the data
        or None if the data is not available (e.g. before the handshake)."""
        return self._sslobj.get_channel_binding(cb_type)

    def version(self):
        """Return a string identifying the protocol version used by the
        current SSL channel. """
        return self._sslobj.version()

    def verify_client_post_handshake(self):
        return self._sslobj.verify_client_post_handshake()

sslobject_class = SSLObject

class SSLSocket(socket):
    """This class implements a subtype of socket.socket that wraps
    the underlying OS socket in an SSL context when necessary, and
    provides read and write methods over that channel. """

    SOCK_STREAM = const(0x21)  # TCP
    AF_INET = const(3)

    def __init__(self, *args, **kwargs):
        raise TypeError("Instances are returned by SSLContext.wrap_socket().")

    @classmethod
    def _create(cls, sock, server_side=False, do_handshake_on_connect=True,
                suppress_ragged_eofs=True, server_hostname=None,
                context=None, session=None):
        if server_side:
            if server_hostname:
                raise ValueError("server_hostname can only be specified "
                                 "in client mode")
            if session is not None:
                raise ValueError("session can only be specified in "
                                 "client mode")

        sock_timeout = sock.gettimeout()
        kwargs = dict(
            family=sock.family, type=sock.type, proto=sock.proto,
            fileno=None
        )
        #self = cls.__new__(cls, **kwargs)
        self = SSLSocket
        super(SSLSocket, self).__init__(**kwargs)
        #sock.detach()
        # Now SSLSocket is responsible for closing the file descriptor.
        try:
            self._context = context
            self._session = session
            self._closed = False
            self._sslobj = None
            self.server_side = server_side
            self.server_hostname = context._encode_hostname(SSLContext, server_hostname)
            self.do_handshake_on_connect = do_handshake_on_connect
            self.suppress_ragged_eofs = suppress_ragged_eofs

            # See if we are connected
            try:
                self.getpeername(sock)
            except OSError as e:
                if e.errno != errno.ENOTCONN:
                    raise
                connected = False
                blocking = self.getblocking()
                self.setblocking(False)
                try:
                    # We are not connected so this is not supposed to block, but
                    # testing revealed otherwise on macOS and Windows so we do
                    # the non-blocking dance regardless. Our raise when any data
                    # is found means consuming the data is harmless.
                    notconn_pre_handshake_data = self.recv(1)
                except OSError as e:
                    # EINVAL occurs for recv(1) on non-connected on unix sockets.
                    if e.errno not in (errno.ENOTCONN, errno.EINVAL):
                        raise
                    notconn_pre_handshake_data = b''
                self.setblocking(blocking)
                if notconn_pre_handshake_data:
                    # This prevents pending data sent to the socket before it was
                    # closed from escaping to the caller who could otherwise
                    # presume it came through a successful TLS connection.
                    reason = "Closed before TLS handshake with data in recv buffer."
                    notconn_pre_handshake_data_error = SSLError(e.errno, reason)
                    # Add the SSLError attributes that _ssl.c always adds.
                    notconn_pre_handshake_data_error.reason = reason
                    notconn_pre_handshake_data_error.library = None
                    try:
                        raise notconn_pre_handshake_data_error
                    finally:
                        # Explicitly break the reference cycle.
                        notconn_pre_handshake_data_error = None
            else:
                connected = True

            self.settimeout(sock, sock_timeout)  # Must come after setblocking() calls.
            self._isconnected = connected
            if connected:
                # create the SSL object
                '''
                self._sslobj = self._context.wrap_socket(
                    self, server_side = server_side, server_hostname = self.server_hostname,
                    session=self._session,
                )
                '''
                self._sslobj = sslobject_class
                if do_handshake_on_connect:
                    timeout = self.gettimeout(sock)
                    if timeout == 0.0:
                        # non-blocking
                        raise ValueError("do_handshake_on_connect should not be specified for non-blocking sockets")
                    self.do_handshake(sock)
        except:
            '''
            try:
                self.close(sock)
            except OSError:
                pass
            raise
            '''
            pass
        return self

    def set_interface(self, iface) -> None:
        """
        Helper to set the global internet interface.

        :param wiznet5k.adafruit_wiznet5k.WIZNET5K iface: The ethernet interface.
        """
        global _the_interface  # pylint: disable=global-statement, invalid-name
        _the_interface = iface

    # pylint: disable=too-many-arguments, unused-argument
    def getaddrinfo(
        self,
        _host: str,
        _port: int,
        _family: int = 0,
        _type: int = 0,
        _proto: int = 0,
        _flags: int = 0,
    ) -> List[Tuple[int, int, int, str, Tuple[str, int]]]:
        """
        Translate the host/port argument into a sequence of 5-tuples that contain all the necessary
        arguments for creating a socket connected to that service.

        :param str host: a domain name, a string representation of an IPv4 address or
            None.
        :param int port: Port number to connect to (0 - 65536).
        :param int family: Ignored and hardcoded as 0x03 (the only family implemented) by the function.
        :param int type: The type of socket, either SOCK_STREAM (0x21) for TCP or SOCK_DGRAM (0x02)
            for UDP, defaults to 0.
        :param int proto: Unused in this implementation of socket.
        :param int flags: Unused in this implementation of socket.

        :return List[Tuple[int, int, int, str, Tuple[str, int]]]: Address info entries in the form
            (family, type, proto, canonname, sockaddr). In these tuples, family, type, proto are meant
            to be passed to the socket() function. canonname will always be an empty string, sockaddr
            is a tuple describing a socket address, whose format is (address, port), and is meant to be
            passed to the socket.connect() method.
        """
        #port = 8883
        if not isinstance(_port, int):
            raise ValueError("Port must be an integer")
        if not _is_ipv4_string(_host):
            _host = gethostbyname(_host)
        return [(AF_INET, _type, _proto, "", (_host, _port))]

    @property
    def context(self):
        return self._context

    @context.setter
    def context(self, ctx):
        self._context = ctx
        self._sslobj.context = ctx

    @property
    def session(self):
        if self._sslobj is not None:
            return self._sslobj.session

    @session.setter
    def session(self, session):
        self._session = session
        if self._sslobj is not None:
            self._sslobj.session = session

    @property
    def session_reused(self):
        if self._sslobj is not None:
            return self._sslobj.session_reused

    def dup(self):
        raise NotImplementedError("Can't dup() %s instances" %
                                  self.__class__.__name__)

    def _checkClosed(self, msg=None):
        # raise an exception here if you wish to check for spurious closes
        pass

    def _check_connected(self):
        if not self._isconnected:
            # getpeername() will raise ENOTCONN if the socket is really
            # not connected; note that we can be connected even without
            # _connected being set, e.g. if connect() first returned
            # EAGAIN.
            self.getpeername()

    def read(self, len=1024, buffer=None):
        """Read up to LEN bytes and return them.
        Return zero-length string on EOF."""

        self._checkClosed(self)
        if self._sslobj is None:
            raise ValueError("Read on closed or unwrapped SSL socket.")
        try:
            if buffer is not None:
                return self._sslobj.read(len, buffer)
            else:
                return self._sslobj.read(len)
        except :
            if buffer is not None:
                return 0
            else:
                return b''

    def write(self, data):
        """Write DATA to the underlying SSL channel.  Returns
        number of bytes of DATA actually transmitted."""

        self._checkClosed()
        if self._sslobj is None:
            raise ValueError("Write on closed or unwrapped SSL socket.")
        return self._sslobj.write(data)

    def getpeercert(self, binary_form=False):
        self._checkClosed()
        self._check_connected()
        return self._sslobj.getpeercert(binary_form)

    def get_verified_chain(self):
        return self._sslobj.get_verified_chain()

    def get_unverified_chain(self):
        return self._sslobj.get_unverified_chain()

    def selected_npn_protocol(self):
        self._checkClosed()
        warnings.warn(
            "ssl NPN is deprecated, use ALPN instead",
            DeprecationWarning,
            stacklevel=2
        )
        return None

    def selected_alpn_protocol(self):
        self._checkClosed()
        if self._sslobj is None or not _ssl.HAS_ALPN:
            return None
        else:
            return self._sslobj.selected_alpn_protocol()

    def cipher(self):
        self._checkClosed()
        if self._sslobj is None:
            return None
        else:
            return self._sslobj.cipher()

    def shared_ciphers(self):
        self._checkClosed()
        if self._sslobj is None:
            return None
        else:
            return self._sslobj.shared_ciphers()

    def compression(self):
        self._checkClosed()
        if self._sslobj is None:
            return None
        else:
            return self._sslobj.compression()

    def send(self, data, flags=0):
        self._socket_pool._checkClosed(self._socket_pool)
        if self._socket_pool._sslobj is not None:
            if flags != 0:
                raise ValueError(
                    "non-zero flags not allowed in calls to send() on %s" %
                    self._socket_pool.__class__)
            return self._socket_pool._sslobj.write(self._socket_pool, data)
        else:
            return super().send(data, flags)

    def sendto(self, data, flags_or_addr, addr=None):
        self._checkClosed()
        if self._sslobj is not None:
            raise ValueError("sendto not allowed on instances of %s" %
                             self.__class__)
        elif addr is None:
            return super().sendto(data, flags_or_addr)
        else:
            return super().sendto(data, flags_or_addr, addr)

    def sendmsg(self, *args, **kwargs):
        # Ensure programs don't send data unencrypted if they try to
        # use this method.
        raise NotImplementedError("sendmsg not allowed on instances of %s" %
                                  self.__class__)

    def sendall(self, data, flags=0):
        self._checkClosed()
        if self._sslobj is not None:
            if flags != 0:
                raise ValueError(
                    "non-zero flags not allowed in calls to sendall() on %s" %
                    self.__class__)
            count = 0
            with memoryview(data) as view, view.cast("B") as byte_view:
                amount = len(byte_view)
                while count < amount:
                    v = self.send(byte_view[count:])
                    count += v
        else:
            return super().sendall(data, flags)

    def sendfile(self, file, offset=0, count=None):
        """Send a file, possibly by using os.sendfile() if this is a
        clear-text socket.  Return the total number of bytes sent.
        """
        if self._sslobj is not None:
            return self._sendfile_use_send(file, offset, count)
        else:
            # os.sendfile() works with plain sockets only
            return super().sendfile(file, offset, count)

    def recv(self, buflen=1024, flags=0):
        self._checkClosed()
        if self._sslobj is not None:
            if flags != 0:
                raise ValueError(
                    "non-zero flags not allowed in calls to recv() on %s" %
                    self.__class__)
            return self.read(buflen)
        else:
            return super().recv(buflen, flags)

    def recv_into(self, buffer, nbytes=None, flags=0):
        self._checkClosed(self)
        if nbytes is None:
            if buffer is not None:
                with memoryview(buffer) as view:
                    nbytes = view.nbytes
                if not nbytes:
                    nbytes = 1024
            else:
                nbytes = 1024
        if self._sslobj is not None:
            if flags != 0:
                raise ValueError(
                  "non-zero flags not allowed in calls to recv_into() on %s" %
                  self.__class__)
            return self.read(self, nbytes, buffer)
        else:
            return super().recv_into(buffer, nbytes, flags)

    def recvfrom(self, buflen=1024, flags=0):
        self._checkClosed()
        if self._sslobj is not None:
            raise ValueError("recvfrom not allowed on instances of %s" %
                             self.__class__)
        else:
            return super().recvfrom(buflen, flags)

    def recvfrom_into(self, buffer, nbytes=None, flags=0):
        self._checkClosed()
        if self._sslobj is not None:
            raise ValueError("recvfrom_into not allowed on instances of %s" %
                             self.__class__)
        else:
            return super().recvfrom_into(buffer, nbytes, flags)

    def recvmsg(self, *args, **kwargs):
        raise NotImplementedError("recvmsg not allowed on instances of %s" %
                                  self.__class__)

    def recvmsg_into(self, *args, **kwargs):
        raise NotImplementedError("recvmsg_into not allowed on instances of "
                                  "%s" % self.__class__)

    def pending(self):
        self._checkClosed()
        if self._sslobj is not None:
            return self._sslobj.pending()
        else:
            return 0

    def shutdown(self, how):
        self._checkClosed()
        self._sslobj = None
        super().shutdown(how)

    def unwrap(self):
        if self._sslobj:
            s = self._sslobj.shutdown()
            self._sslobj = None
            return s
        else:
            raise ValueError("No SSL wrapper around " + str(self))

    def verify_client_post_handshake(self):
        if self._sslobj:
            return self._sslobj.verify_client_post_handshake()
        else:
            raise ValueError("No SSL wrapper around " + str(self))

    def close(self):
        self._sslobj = None
        super().close()

    def do_handshake(self, block=False):
        self._check_connected(self)
        timeout = self.gettimeout(self)
        try:
            if timeout == 0.0 and block:
                self.settimeout(self, None)
            self._sslobj.do_handshake(self)
        finally:
            self.settimeout(self, timeout)

    def _real_connect(self, addr, connect_ex):
        if self.server_side:
            raise ValueError("can't connect in server-side mode")
        # Here we assume that the socket is client-side, and not
        # connected at the time of the call.  We connect it, then wrap it.
        #if self._connected or self._sslobj is not None:
            #pass
            #raise ValueError("attempt to connect already-connected SSLSocket!")
        '''    
        self._sslobj = self.context.wrap_socket(
            self, server_side = False, server_hostname = self.server_hostname,
            session=self._session
        )
        '''
        self._sslobj = sslobject_class
        try:
            if connect_ex:
                rc = super().connect_ex(addr)
            else:
                rc = None
                super().connect(addr)
            if not rc:
                self._isconnected = True
                if self.do_handshake_on_connect:
                    self.do_handshake(self)
            return rc
        except (OSError, ValueError):
            self._sslobj = None
            raise

    def connect(self, addr):
        """Connects to remote ADDR, and then wraps the connection in
        an SSL channel."""
        self._real_connect(self, addr, False)

    def connect_ex(self, addr):
        """Connects to remote ADDR, and then wraps the connection in
        an SSL channel."""
        return self._real_connect(addr, True)

    def accept(self):
        """Accepts a new connection from a remote client, and returns
        a tuple containing that new connection wrapped with a server-side
        SSL channel, and the address of the remote client."""

        newsock, addr = super().accept()
        newsock = self.context.wrap_socket(newsock,
                    do_handshake_on_connect=self.do_handshake_on_connect,
                    suppress_ragged_eofs=self.suppress_ragged_eofs,
                    server_side=True)
        return newsock, addr

    def get_channel_binding(self, cb_type="tls-unique"):
        if self._sslobj is not None:
            return self._sslobj.get_channel_binding(cb_type)
        else:
            if cb_type not in CHANNEL_BINDING_TYPES:
                raise ValueError(
                    "{0} channel binding type not implemented".format(cb_type)
                )
            return None

    def version(self):
        if self._sslobj is not None:
            return self._sslobj.version()
        else:
            return None


# Python does not support forward declaration of types.
sslsocket_class = SSLSocket

class SSLContext:
    """An SSLContext holds various SSL-related configuration options and
    data, such as certificates and possibly a private key."""
    _windows_cert_stores = ("CA", "ROOT")

    #sslsocket_class = None  # SSLSocket is assigned later.
    #sslobject_class = None  # SSLObject is assigned later.

    def __new__(cls, protocol=None, *args, **kwargs):
        if protocol is None:
            pass
            #protocol = PROTOCOL_TLS
        return self

    def _encode_hostname(self, hostname):
        if hostname is None:
            return None
        elif isinstance(hostname, str):
            return hostname.encode('idna').decode('ascii')
        else:
            return hostname.decode('ascii')

    def wrap_socket(sock, server_side=False,
                    do_handshake_on_connect=True,
                    suppress_ragged_eofs=True,
                    server_hostname=None, session=None):
        # SSLSocket class handles server_hostname encoding before it calls
        # ctx._wrap_socket()
        return sslsocket_class._create(
            sock=sock,
            server_side=server_side,
            do_handshake_on_connect=do_handshake_on_connect,
            suppress_ragged_eofs=suppress_ragged_eofs,
            server_hostname=server_hostname,
            context=SSLContext,
            session=session
        )

    def wrap_bio(self, incoming, outgoing, server_side=False,
                 server_hostname=None, session=None):
        # Need to encode server_hostname here because _wrap_bio() can only
        # handle ASCII str.
        return self.sslobject_class._create(
            incoming, outgoing, server_side=server_side,
            server_hostname=self._encode_hostname(server_hostname),
            session=session, context=self,
        )

    def set_npn_protocols(self, npn_protocols):
        warnings.warn(
            "ssl NPN is deprecated, use ALPN instead",
            DeprecationWarning,
            stacklevel=2
        )
        protos = bytearray()
        for protocol in npn_protocols:
            b = bytes(protocol, 'ascii')
            if len(b) == 0 or len(b) > 255:
                raise SSLError('NPN protocols must be 1 to 255 in length')
            protos.append(len(b))
            protos.extend(b)

        self._set_npn_protocols(protos)

    def set_servername_callback(self, server_name_callback):
        if server_name_callback is None:
            self.sni_callback = None
        else:
            if not callable(server_name_callback):
                raise TypeError("not a callable object")

            def shim_cb(sslobj, servername, sslctx):
                servername = self._encode_hostname(servername)
                return server_name_callback(sslobj, servername, sslctx)

            self.sni_callback = shim_cb

    def set_alpn_protocols(self, alpn_protocols):
        protos = bytearray()
        for protocol in alpn_protocols:
            b = bytes(protocol, 'ascii')
            if len(b) == 0 or len(b) > 255:
                raise SSLError('ALPN protocols must be 1 to 255 in length')
            protos.append(len(b))
            protos.extend(b)

        self._set_alpn_protocols(protos)

    def _load_windows_store_certs(self, storename, purpose):
        certs = bytearray()
        try:
            for cert, encoding, trust in enum_certificates(storename):
                # CA certs are never PKCS#7 encoded
                if encoding == "x509_asn":
                    if trust is True or purpose.oid in trust:
                        certs.extend(cert)
        except PermissionError:
            warnings.warn("unable to enumerate Windows certificate store")
        if certs:
            self.load_verify_locations(cadata=certs)
        return certs

    def load_default_certs(self, purpose=Purpose.SERVER_AUTH):
        if sys.platform == "win32":
            for storename in self._windows_cert_stores:
                self._load_windows_store_certs(storename, purpose)
        self.set_default_verify_paths()

    @property
    def options(self):
        return Options(super().options)

    @options.setter
    def options(self, value):
        super(SSLContext, SSLContext).options.__set__(self, value)


    @property
    def hostname_checks_common_name(self):
        return True


    @property
    def _msg_callback(self):
        """TLS message callback

        The message callback provides a debugging hook to analyze TLS
        connections. The callback is called for any TLS protocol message
        (header, handshake, alert, and more), but not for application data.
        Due to technical  limitations, the callback can't be used to filter
        traffic or to abort a connection. Any exception raised in the
        callback is delayed until the handshake, read, or write operation
        has been performed.

        def msg_cb(conn, direction, version, content_type, msg_type, data):
            pass

        conn
            :class:`SSLSocket` or :class:`SSLObject` instance
        direction
            ``read`` or ``write``
        version
            :class:`TLSVersion` enum member or int for unknown version. For a
            frame header, it's the header version.
        content_type
            :class:`_TLSContentType` enum member or int for unsupported
            content type.
        msg_type
            Either a :class:`_TLSContentType` enum number for a header
            message, a :class:`_TLSAlertType` enum member for an alert
            message, a :class:`_TLSMessageType` enum member for other
            messages, or int for unsupported message types.
        data
            Raw, decrypted message content as bytes
        """
        inner = super()._msg_callback
        if inner is not None:
            return inner.user_function
        else:
            return None

    @_msg_callback.setter
    def _msg_callback(self, callback):
        if callback is None:
            super(SSLContext, SSLContext)._msg_callback.__set__(self, None)
            return

        if not hasattr(callback, '__call__'):
            raise TypeError(f"{callback} is not callable.")

        def inner(conn, direction, version, content_type, msg_type, data):
            try:
                version = TLSVersion(version)
            except ValueError:
                pass

            try:
                content_type = _TLSContentType(content_type)
            except ValueError:
                pass

            if content_type == _TLSContentType.HEADER:
                msg_enum = _TLSContentType
            elif content_type == _TLSContentType.ALERT:
                msg_enum = _TLSAlertType
            else:
                msg_enum = _TLSMessageType
            try:
                msg_type = msg_enum(msg_type)
            except ValueError:
                pass

            return callback(conn, direction, version,
                            content_type, msg_type, data)

        inner.user_function = callback

        super(SSLContext, SSLContext)._msg_callback.__set__(self, inner)

    @property
    def protocol(self):
        return _SSLMethod(super().protocol)

    @property
    def verify_flags(self):
        return VerifyFlags(super().verify_flags)

    @verify_flags.setter
    def verify_flags(self, value):
        super(SSLContext, SSLContext).verify_flags.__set__(self, value)

    @property
    def verify_mode(self):
        value = super().verify_mode
        try:
            return VerifyMode(value)
        except ValueError:
            return value

    @verify_mode.setter
    def verify_mode(self, value):
        super(SSLContext, SSLContext).verify_mode.__set__(self, value)


def create_default_context(purpose=Purpose.SERVER_AUTH, *, cafile=None,
                           capath=None, cadata=None):
    """Create a SSLContext object with default settings.

    NOTE: The protocol and settings may change anytime without prior
          deprecation. The values represent a fair balance between maximum
          compatibility and security.
    """

    # SSLContext sets OP_NO_SSLv2, OP_NO_SSLv3, OP_NO_COMPRESSION,
    # OP_CIPHER_SERVER_PREFERENCE, OP_SINGLE_DH_USE and OP_SINGLE_ECDH_USE
    # by default.
    if purpose == Purpose.SERVER_AUTH:
        # verify certs and host name in client mode
        context = SSLContext
        #context.verify_mode = CERT_REQUIRED
        #context.check_hostname = True
    elif purpose == Purpose.CLIENT_AUTH:
        context = SSLContext(PROTOCOL_TLS_SERVER)
    else:
        raise ValueError(purpose)

    if cafile or capath or cadata:
        context.load_verify_locations(cafile, capath, cadata)
    # OpenSSL 1.1.1 keylog file
    if hasattr(context, 'keylog_filename'):
        keylogfile = os.environ.get('SSLKEYLOGFILE')
        if keylogfile and not sys.flags.ignore_environment:
            context.keylog_filename = keylogfile
    return context







# Python does not support forward declaration of types.
#SSLContext.sslsocket_class = SSLSocket
#SSLContext.sslobject_class = SSLObject


# some utility functions
