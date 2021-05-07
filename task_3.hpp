#pragma once

#include <bits/stdint-uintn.h>
#include <cmath>


inline double Sin(double x) {
    double Sum = 0;
    const double epsilon = 0.000001;
    double a = x; 
    for (uint16_t k = 0; fabs(a) > epsilon; k++) {
        Sum += a;
        a *= -x*x/(2*k + 2)/(2*k + 3);
    }
    return Sum;
}