
#version 110

uniform sampler2D	texture;
uniform sampler2D	side;
uniform sampler2D	dist;

uniform vec3		lightPos;
uniform vec4		lightColor;
uniform float		shooting;

void main()
{
  vec4 pixel = texture2D(texture, gl_TexCoord[0].xy);
  vec4 pd = texture2D(dist, gl_TexCoord[0].xy);
  vec4 ps = texture2D(side, gl_TexCoord[0].xy);
  vec4 lc = normalize(lightColor);
  float ll = dot(lightPos, vec3(ps.x, ps.y, ps.z));

  ll /= 3.;
  ll += 0.2;

  float rate = pd.a * ((shooting > 0.) ? 0.75 : 0.9);

  lc.a = (1. - pd.a) * 0.1;

  if (shooting < 1.)
    {
      pixel = vec4(
      		   pixel.r * (1. - lc.a) + lc.r * lc.a,
      		   pixel.g * (1. - lc.a) + lc.g * lc.a,
      		   pixel.b * (1. - lc.a) + lc.b * lc.a,
      		   pixel.a
      		   );
    }
  gl_FragColor = vec4(
		      pixel.r * (1. - rate) * ll,
		      pixel.g * (1. - rate) * ll,
		      pixel.b * (1. - rate) * ll,
		      pixel.a
		      );
}
