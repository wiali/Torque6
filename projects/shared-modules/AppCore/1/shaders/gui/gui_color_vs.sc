$input a_position, a_color0
$output v_color0

#include <torque6.sc>

void main()
{
    v_color0 = a_color0;
    gl_Position = mul(u_modelViewProj, vec4(a_position.xyz, 1.0) );
}
