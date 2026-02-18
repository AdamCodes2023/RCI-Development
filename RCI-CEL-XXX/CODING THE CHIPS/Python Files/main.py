from m5stack import *
from m5stack_ui import *
from uiflow import *
import i2c_bus
import ads1x15
import mcp4728
import pcf8575
from machine import I2C, Pin, Timer
import time

def adc_to_dac(adcChannel, dacChannel, i2c, adc):
    if adcChannel >= 0 and adcChannel <=3:
        raw = adc.read(0, adcChannel)
        raw *= 1.21
        raw *= 2
        raw = int(raw)
        binary = '{:016b}'.format(raw)
        binary = binary[:(len(binary)-2)]
        binary = '0b' + binary[:8] + '0b' + binary[8:] + '00'
        binary = binary.replace('-', '0')
        
        if dacChannel.lower() == 'a':
            #lcd.text(10, 100, str(int.from_bytes(bytearray([int(binary[:10]), int(binary[10:])]), 'big')), lcd.BLUE)
            writeCommand = bytearray([0b00011000, int(binary[:10]), int(binary[10:])])
            i2c.writeto(26, writeCommand, True)
            time.sleep(0.02)
        elif dacChannel.lower() == 'b':
            #lcd.text(10, 120, str(int.from_bytes(bytearray([int(binary[:10]), int(binary[10:])]), 'big')), lcd.BLUE)
            writeCommand = bytearray([0b00011001, int(binary[:10]), int(binary[10:])])
            i2c.writeto(26, writeCommand, True)
            time.sleep(0.02)
        elif dacChannel.lower() == 'c':
            #lcd.text(10, 140, str(int.from_bytes(bytearray([int(binary[:10]), int(binary[10:])]), 'big')), lcd.BLUE)
            writeCommand = bytearray([0b00011010, int(binary[:10]), int(binary[10:])])
            i2c.writeto(26, writeCommand, True)
            time.sleep(0.02)
        elif dacChannel.lower() == 'd':
            #lcd.text(10, 160, str(int.from_bytes(bytearray([int(binary[:10]), int(binary[10:])]), 'big')), lcd.BLUE)
            writeCommand = bytearray([0b00011011, int(binary[:10]), int(binary[10:])])
            i2c.writeto(26, writeCommand, True)
            time.sleep(0.02)
        elif dacChannel.lower() == 'all':
            #lcd.text(10, 180, str(int.from_bytes(bytearray([int(binary[:10]), int(binary[10:])]), 'big')), lcd.BLUE)
            writeCommand = bytearray([0b00011111, int(binary[:10]), int(binary[10:])])
            i2c.writeto(26, writeCommand, True)
            time.sleep(0.02)
        else:
            lcd.text(10, 200, 'SOMETHING WENT WRONG', lcd.BLUE)
            return ''
        return binary
    else:
        lcd.text(10, 200, 'SOMETHING WENT WRONG', lcd.BLUE)
        return ''


power.setBusPowerMode(0)
screen = M5Screen()
screen.clean_screen()
screen.set_screen_bg_color(0xff0000)
lcd.font(lcd.FONT_DejaVu24)


#i2c0 = i2c_bus.easyI2C(i2c_bus.PORTA, 0x00, freq=400000)
#lcd.text(10, 10, str(i2c0.scan()), lcd.BLUE)
#lcd.text(10, 40, str(i2c0.available()), lcd.BLUE)

i2c = I2C(freq=400000, sda=32, scl=33)
lcd.text(10, 70, str(i2c.scan()), lcd.BLUE)
time.sleep(0.75)

writeCommand = bytearray([0b00011111, 0b00000000, 0b00000000])
i2c.writeto(26, writeCommand, True)
time.sleep(0.5)
adc = ads1x15.ADS1115(i2c, 72, 0)
adc._write_register(0, 0)

#x = 0
lcd.font(lcd.FONT_DejaVu40)

"""
#WORKS -> CONVERT FROM ADC TO DAC
while x < 20:
    bin1 = adc_to_dac(0, 'a', i2c, adc)
    byArrayA = bytearray(3)
    i2c.readfrom_into(26, byArrayA, True)
    time.sleep(0.02)
    binaryA = '{:016b}'.format(int.from_bytes(byArrayA[1:], 'big'))
    binaryA = '00' + binaryA[:14]
    binaryA = '0b' + binaryA[:8] + '0b' + binaryA[8:]
    
    bin2 = adc_to_dac(1, 'b', i2c, adc)
    byArrayB = bytearray(3)
    i2c.readfrom_into(26, byArrayB, True)
    time.sleep(0.02)
    binaryB = '{:016b}'.format(int.from_bytes(byArrayB[1:], 'big'))
    binaryB = '00' + binaryB[:14]
    binaryB = '0b' + binaryB[:8] + '0b' + binaryB[8:]

    lcd.text(10, 120, 'AI 1: ' + str(int.from_bytes(bytearray([int(bin1[:10]), int(bin1[10:])]), 'big')), lcd.BLUE)
    lcd.text(10, 160, 'AI 2: ' + str(int.from_bytes(bytearray([int(bin2[:10]), int(bin2[10:])]), 'big')), lcd.BLUE)
    #lcd.text(10, 160, str(int.from_bytes(byArrayA[1:], 'big')), lcd.BLUE)
    #lcd.text(10, 180, str(int.from_bytes(byArrayB[1:], 'big')), lcd.BLUE)
    #lcd.text(110, 160, str(int.from_bytes(bytearray([int(binaryA[:10]), int(binaryA[10:])]), 'big')), lcd.BLUE)
    #lcd.text(110, 180, str(int.from_bytes(bytearray([int(binaryB[:10]), int(binaryB[10:])]), 'big')), lcd.BLUE)

    time.sleep(2.0)
    lcd.textClear(10, 120, 'AI 1: ' + str(int.from_bytes(bytearray([int(bin1[:10]), int(bin1[10:])]), 'big')), lcd.RED)
    lcd.textClear(10, 160, 'AI 2: ' + str(int.from_bytes(bytearray([int(bin2[:10]), int(bin2[10:])]), 'big')), lcd.RED)
    #lcd.textClear(10, 160, str(int.from_bytes(byArrayA[1:], 'big')), lcd.RED)
    #lcd.textClear(10, 180, str(int.from_bytes(byArrayB[1:], 'big')), lcd.RED)
    #lcd.textClear(110, 160, str(int.from_bytes(bytearray([int(binaryA[:10]), int(binaryA[10:])]), 'big')), lcd.RED)
    #lcd.textClear(110, 180, str(int.from_bytes(bytearray([int(binaryB[:10]), int(binaryB[10:])]), 'big')), lcd.RED)
    
    x += 1
"""

"""
#DONE -> PCF8575 16-Bit I2C I/O Expander with Interrupt
pcf = pcf8575.PCF8575(i2c, 0x20)
#SET ALL PINS HIGH FOR INPUT
pcf.port = 0xffff
lcd.text(10, 120, str(pcf.port), lcd.BLUE)
x = 0
while x < 100:
    #BUTTON DRIVES INPUT LOW
    if pcf.pin(10) == 0: 
        pcf.pin(0, 0)
    else:
        pcf.pin(0, 1)
    #RESET INPUT PIN
    pcf.pin(10, 1)
    time.sleep(0.25)
    x += 1
"""

"""
#DONE -> AD5645R Digital to Analog Converter

#DIFFERENT CHIP (ADAFRUIT)
# dac = mcp4728.MCP4728(i2c, 0x1a)

#DOES NOT WORK
# writeCommand = bytearray([0b00110100, 0b00010111, 0b00000000, 0b11111100])

#USE THIS COMMAND (JUST WRITE TO DAC CHANNEL)
# writeCommand = bytearray([0b00011000, 0b11111111, 0b01011000])

# value = i2c.writeto(26, writeCommand, True)
# time.sleep(1.0)
"""

"""
#Read from DAC (USE A BYTE ARRAY TO HOLD LAST DAC COMMAND AND CONVERT THE LAST TWO BYTES)
readCommand = bytearray([0b00110101])
value2 = i2c.writeto(26, readCommand, False)
time.sleep(1.0)
value3 = i2c.readfrom(26, 2, True)
time.sleep(1.0)
lcd.text(10, 100, str(value), lcd.BLUE)
lcd.text(10, 130, str(value2), lcd.BLUE)
lcd.text(10, 160, str(int.from_bytes(value3, 'big')), lcd.BLUE)
"""

"""
#DONE -> ADS1115 16 Bit I2C Analog to Digital Converter
adc = ads1x15.ADS1115(i2c, 72, 0)
adc2 = ads1x15.ADS1115(i2c, 73, 0)
adc._write_register(0, 0)
adc2._write_register(0, 0)

x = 0

while x < 5:
    raw = adc.read(0, 0)
    raw2 = adc2.read(0, 0)
    value = adc.raw_to_v(raw)
    value2 = adc2.raw_to_v(raw2)
    lcd.text(10, 100, str(value), lcd.BLUE)
    lcd.text(10, 130, str(value2), lcd.BLUE)
    #registerVal = adc._read_register(0)
    #registerVal2 = adc2._read_register(0)
    #lcd.text(70, 100, str(registerVal), lcd.BLUE)
    #lcd.text(70, 130, str(registerVal2), lcd.BLUE)
    time.sleep(1)
    screen.clean_screen()
    screen.set_screen_bg_color(0xff0000)
    x += 1
"""