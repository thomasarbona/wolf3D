
#version 110

uniform sampler2D	texture;

uniform vec4		lightColor;
uniform float		dist;

void main()
{
  vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
  vec4 lc = normalize(lightColor);

  float rate = dist * 0.6;

  lc.a = (1. - dist) * 0.1;

  pixel = vec4(
	       pixel.r * (1. - lc.a) + lc.r * lc.a,
	       pixel.g * (1. - lc.a) + lc.g * lc.a,
	       pixel.b * (1. - lc.a) + lc.b * lc.a,
	       pixel.a * (1. - lc.a) + lc.a * lc.a
	       );

  gl_FragColor = vec4(
  pixel.r * (1. - dist),
  pixel.g * (1. - dist),
  pixel.b * (1. - dist),
  pixel.a
);
}
