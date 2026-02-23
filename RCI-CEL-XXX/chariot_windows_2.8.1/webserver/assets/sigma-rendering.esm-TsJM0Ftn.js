import{D as w,i as R,_ as y,a as N,F as G,p as P,r as x,s as O,t as C,b as U,c as H}from"./index-236c62ad.esm-CCiV41DP.js";import{u as X,h as Y,E as j,N as K,q as J,P as Q,v as Z,w as ee,x as oe,e as ae,f as te,g as ie,y as ne,z as re,A as se,B as ue,C as ce,G as _e}from"./index-236c62ad.esm-CCiV41DP.js";var F=`
attribute vec4 a_id;
attribute vec4 a_color;
attribute vec2 a_normal;
attribute float a_normalCoef;
attribute vec2 a_positionStart;
attribute vec2 a_positionEnd;
attribute float a_positionCoef;
attribute float a_sourceRadius;
attribute float a_targetRadius;
attribute float a_sourceRadiusCoef;
attribute float a_targetRadiusCoef;

uniform mat3 u_matrix;
uniform float u_zoomRatio;
uniform float u_sizeRatio;
uniform float u_pixelRatio;
uniform float u_correctionRatio;
uniform float u_minEdgeThickness;
uniform float u_lengthToThicknessRatio;
uniform float u_feather;

varying vec4 v_color;
varying vec2 v_normal;
varying float v_thickness;
varying float v_feather;

const float bias = 255.0 / 254.0;

void main() {
  float minThickness = u_minEdgeThickness;

  vec2 normal = a_normal * a_normalCoef;
  vec2 position = a_positionStart * (1.0 - a_positionCoef) + a_positionEnd * a_positionCoef;

  float normalLength = length(normal);
  vec2 unitNormal = normal / normalLength;

  // These first computations are taken from edge.vert.glsl. Please read it to
  // get better comments on what's happening:
  float pixelsThickness = max(normalLength, minThickness * u_sizeRatio);
  float webGLThickness = pixelsThickness * u_correctionRatio / u_sizeRatio;

  // Here, we move the point to leave space for the arrow heads:
  // Source arrow head
  float sourceRadius = a_sourceRadius * a_sourceRadiusCoef;
  float sourceDirection = sign(sourceRadius);
  float webGLSourceRadius = sourceDirection * sourceRadius * 2.0 * u_correctionRatio / u_sizeRatio;
  float webGLSourceArrowHeadLength = webGLThickness * u_lengthToThicknessRatio * 2.0;
  vec2 sourceCompensationVector =
    vec2(-sourceDirection * unitNormal.y, sourceDirection * unitNormal.x)
    * (webGLSourceRadius + webGLSourceArrowHeadLength);
    
  // Target arrow head
  float targetRadius = a_targetRadius * a_targetRadiusCoef;
  float targetDirection = sign(targetRadius);
  float webGLTargetRadius = targetDirection * targetRadius * 2.0 * u_correctionRatio / u_sizeRatio;
  float webGLTargetArrowHeadLength = webGLThickness * u_lengthToThicknessRatio * 2.0;
  vec2 targetCompensationVector =
  vec2(-targetDirection * unitNormal.y, targetDirection * unitNormal.x)
    * (webGLTargetRadius + webGLTargetArrowHeadLength);

  // Here is the proper position of the vertex
  gl_Position = vec4((u_matrix * vec3(position + unitNormal * webGLThickness + sourceCompensationVector + targetCompensationVector, 1)).xy, 0, 1);

  v_thickness = webGLThickness / u_zoomRatio;

  v_normal = unitNormal;

  v_feather = u_feather * u_correctionRatio / u_zoomRatio / u_pixelRatio * 2.0;

  #ifdef PICKING_MODE
  // For picking mode, we use the ID as the color:
  v_color = a_id;
  #else
  // For normal mode, we use the color:
  v_color = a_color;
  #endif

  v_color.a *= bias;
}
`,M=F,A=WebGLRenderingContext,b=A.UNSIGNED_BYTE,n=A.FLOAT,V=["u_matrix","u_zoomRatio","u_sizeRatio","u_correctionRatio","u_pixelRatio","u_feather","u_minEdgeThickness","u_lengthToThicknessRatio"],I={lengthToThicknessRatio:w.lengthToThicknessRatio};function L(d){var S=R(R({},I),{});return(function(k){function u(){return U(this,u),H(this,u,arguments)}return y(u,k),N(u,[{key:"getDefinition",value:function(){return{VERTICES:6,VERTEX_SHADER_SOURCE:M,FRAGMENT_SHADER_SOURCE:G,METHOD:WebGLRenderingContext.TRIANGLES,UNIFORMS:V,ATTRIBUTES:[{name:"a_positionStart",size:2,type:n},{name:"a_positionEnd",size:2,type:n},{name:"a_normal",size:2,type:n},{name:"a_color",size:4,type:b,normalized:!0},{name:"a_id",size:4,type:b,normalized:!0},{name:"a_sourceRadius",size:1,type:n},{name:"a_targetRadius",size:1,type:n}],CONSTANT_ATTRIBUTES:[{name:"a_positionCoef",size:1,type:n},{name:"a_normalCoef",size:1,type:n},{name:"a_sourceRadiusCoef",size:1,type:n},{name:"a_targetRadiusCoef",size:1,type:n}],CONSTANT_DATA:[[0,1,-1,0],[0,-1,1,0],[1,1,0,1],[1,1,0,1],[0,-1,1,0],[1,-1,0,-1]]}}},{key:"processVisibleItem",value:function(i,e,o,a,c){var _=c.size||1,l=o.x,m=o.y,f=a.x,g=a.y,h=P(c.color),r=f-l,T=g-m,z=o.size||1,D=a.size||1,s=r*r+T*T,E=0,p=0;s&&(s=1/Math.sqrt(s),E=-T*s*_,p=r*s*_);var t=this.array;t[e++]=l,t[e++]=m,t[e++]=f,t[e++]=g,t[e++]=E,t[e++]=p,t[e++]=h,t[e++]=i,t[e++]=z,t[e++]=D}},{key:"setUniforms",value:function(i,e){var o=e.gl,a=e.uniformLocations,c=a.u_matrix,_=a.u_zoomRatio,l=a.u_feather,m=a.u_pixelRatio,f=a.u_correctionRatio,g=a.u_sizeRatio,h=a.u_minEdgeThickness,r=a.u_lengthToThicknessRatio;o.uniformMatrix3fv(c,!1,i.matrix),o.uniform1f(_,i.zoomRatio),o.uniform1f(g,i.sizeRatio),o.uniform1f(f,i.correctionRatio),o.uniform1f(m,i.pixelRatio),o.uniform1f(l,i.antiAliasingFeather),o.uniform1f(h,i.minEdgeThickness),o.uniform1f(r,S.lengthToThicknessRatio)}}])})(x)}L();function B(d){return O([L(),C(d),C(R(R({},d),{},{extremity:"source"}))])}B();export{w as DEFAULT_EDGE_ARROW_HEAD_PROGRAM_OPTIONS,X as DEFAULT_EDGE_CLAMPED_PROGRAM_OPTIONS,I as DEFAULT_EDGE_DOUBLE_CLAMPED_PROGRAM_OPTIONS,Y as EdgeArrowProgram,x as EdgeProgram,j as EdgeRectangleProgram,K as NodeCircleProgram,J as NodeProgram,Q as Program,C as createEdgeArrowHeadProgram,Z as createEdgeArrowProgram,ee as createEdgeClampedProgram,O as createEdgeCompoundProgram,B as createEdgeDoubleArrowProgram,L as createEdgeDoubleClampedProgram,oe as createNodeCompoundProgram,ae as drawDiscNodeHover,te as drawDiscNodeLabel,ie as drawStraightEdgeLabel,ne as getAttributeItemsCount,re as getAttributesItemsCount,se as killProgram,ue as loadFragmentShader,ce as loadProgram,_e as loadVertexShader};
