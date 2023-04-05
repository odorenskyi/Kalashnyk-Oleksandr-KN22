#include <math.h>

float s_calculation(float x, float y, float z)
{
    double S =log(fabs(sin (z))) + ((1 / 2) * pow(x, 2) - sqrt(fabs(pow((y + z),2) - pow(x, 5)))) / (10 * pow(z,4) * M_PI);
    return S;
}

