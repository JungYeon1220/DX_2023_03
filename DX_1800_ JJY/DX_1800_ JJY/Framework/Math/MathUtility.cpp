#include "framework.h"
#include "MathUtility.h"

int MathUtility::RandomInt(int min, int max)
{
    return rand() & (max - min) + min;
}

float MathUtility::RandomFloat(float min, float max)
{
    float temp = rand() / (float)RAND_MAX;

    return (max - min) * temp + min;
}
