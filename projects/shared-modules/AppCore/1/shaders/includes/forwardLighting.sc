uniform vec3 dirLightDirection;
uniform vec3 dirLightColor;
uniform vec3 dirLightAmbient;
uniform vec4 lightPosRadius[4];
uniform vec4 lightColorAttn[4];

vec3 computeForwardLighting(vec3 pos, vec3 normal)
{
    // Total Light Color
	vec3 lightColor;

    // Directional Light
    lightColor =  calcDirectionalLight(normal.xyz, dirLightDirection, dirLightColor);

    // Ambient
    lightColor += dirLightAmbient;

    // Point Lights
	lightColor += calcPointLight(pos, lightPosRadius[0].xyz, lightColorAttn[0].xyz, lightPosRadius[0].w, lightColorAttn[0].w);
	lightColor += calcPointLight(pos, lightPosRadius[1].xyz, lightColorAttn[1].xyz, lightPosRadius[1].w, lightColorAttn[1].w);
	lightColor += calcPointLight(pos, lightPosRadius[2].xyz, lightColorAttn[2].xyz, lightPosRadius[2].w, lightColorAttn[2].w);
	lightColor += calcPointLight(pos, lightPosRadius[3].xyz, lightColorAttn[3].xyz, lightPosRadius[3].w, lightColorAttn[3].w);

    return lightColor;
}
