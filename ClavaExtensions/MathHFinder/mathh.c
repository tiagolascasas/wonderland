#include <math.h>

int main()
{
    int x;
    double y;
    float z;
    long double t;
    char str[] = "foo";

    acos(0.5);
    acosf(0.5);
    acoshf(0.5);
    acoshl(0.5);
    acosl(0.5);
    asin(0.5);
    asinf(0.5);
    asinhf(0.5);
    asinhl(0.5);
    asinl(0.5);
    atan(0.5);
    atan2(0.5, 0.6);
    atan2f(0.5, 0.6);
    atan2l(0.5, 0.6);
    atanf(0.5);
    atanl(0.5);
    cbrtf(0.5);
    cbrtl(0.5);
    ceil(0.5);
    ceilf(0.5);
    ceill(0.5);
    copysign(0.5, 0.6);
    copysignf(0.5, 0.6);
    copysignl(0.5, 0.6);
    cos(0.5);
    cosf(0.5);
    cosh(0.5);
    coshf(0.5);
    coshl(0.5);
    cosl(0.5);
    exp(0.5);
    expf(0.5);
    expl(0.5);
    expm1f(0.5);
    expm1l(0.5);
    exp2(0.5);
    exp2f(0.5);
    exp2l(0.5);
    fabsf(0.5);
    fabsl(0.5);
    floor(0.5);
    floorf(0.5);
    floorl(0.5);
    fma(0.5, 0.6, 0.6);
    fmaf(0.5, 0.6, 0.6);
    fmal(0.5, 0.6, 0.6);
    fmax(0.5, 0.6);
    fmaxf(0.5, 0.6);
    fmaxl(0.5, 0.6);
    fmin(0.5, 0.6);
    fminf(0.5, 0.6);
    fminl(0.5, 0.6);
    fmod(0.5, 0.6);
    fmodf(0.5, 0.6);
    fmodl(0.5, 0.6);
    frexp(0.5, &x);
    frexpf(0.5, &x);
    frexpl(0.5, &x);
    hypotf(0.5, 0.6);
    hypotl(0.5, 0.6);
    ilogbf(0.5);
    ilogbl(0.5);
    ldexp(0.5, 0.6);
    ldexpf(0.5, 0.6);
    ldexpl(0.5, 0.6);
    lgammaf(0.5);
    lgammal(0.5);
    llrint(0.5);
    llrintf(0.5);
    llrintl(0.5);
    llround(0.5);
    llroundf(0.5);
    llroundl(0.5);
    log(0.5);
    logbf(0.5);
    logbl(0.5);
    logf(0.5);
    logl(0.5);
    log1pf(0.5);
    log1pl(0.5);
    log10(0.5);
    log10f(0.5);
    log10l(0.5);
    lrint(0.5);
    lrintf(0.5);
    lrintl(0.5);
    lround(0.5);
    lroundf(0.5);
    lroundl(0.5);
    modf(0.5, &y);
    modff(0.5, &z);
    modfl(0.5, &t);
    nan(str);
    nanf(str);
    nanl(str);
    nearbyint(0.5);
    nearbyintf(0.5);
    nearbyintl(0.5);
    nextafterf(0.5, 0.6);
    nextafterl(0.5, 0.6);
    nexttoward(0.5, 0.6);
    nexttowardf(0.5, 0.6);
    nexttowardl(0.5, 0.6);
    pow(0.5, 0.6);
    powf(0.5, 0.6);
    powl(0.5, 0.6);
    remainderf(0.5, 0.6);
    remainderl(0.5, 0.6);
    remquo(0.5, 0.6, &x);
    remquof(0.5, 0.6, &x);
    remquol(0.5, 0.6, &x);
    rintf(0.5);
    rintl(0.5);
    round(0.5);
    roundf(0.5);
    roundl(0.5);
    scalbln(0.5, x);
    scalblnf(0.5, x);
    scalblnl(0.5, x);
    sin(0.5);
    sinf(0.5);
    sinh(0.5);
    sinhf(0.5);
    sinhl(0.5);
    sinl(0.5);
    sqrt(0.5);
    sqrtf(0.5);
    sqrtl(0.5);
    tan(0.5);
    tanf(0.5);
    tanh(0.5);
    tanhf(0.5);
    tanhl(0.5);
    tanl(0.5);
    tgamma(0.5);
    tgammaf(0.5);
    tgammal(0.5);

    return 0;
}