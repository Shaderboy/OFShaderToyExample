#version 120
#extension GL_ARB_texture_rectangle : enable

uniform sampler2DRect texture;
uniform vec2 resolution;
uniform vec2 texResolution;
uniform float time;

void main(void){
	/////////////////////////////Translate to Shader Toy coordinates///////////////////
	vec2 uv = vec2(gl_FragCoord.xy/resolution.xy) * 2.0 - 1.0;
	uv *= resolution.x / resolution.y;

	uv.x += sin(time * uv.y);

	//////////////////////////////Translate back to OF coordinates//////////////////////////
	uv *= resolution.y/resolution.x;
	uv += 1.0;
	uv /= 2.0;
	uv *= resolution.xy;

	uv.y = resolution.y - uv.y;
	uv = mod(uv, resolution);
	uv *= texResolution/resolution;
	//////////////////////////////////////////////////////////////////////////////////
	gl_FragColor = texture2DRect(texture, uv);

}
