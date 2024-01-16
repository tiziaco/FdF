#include <stdio.h>


int lerp(int a, int b, float t) {
    // Ensure t is in the range [0, 1]
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }

    // Perform linear interpolation
    return (int)(a + t * (b - a));
}

int main() {
    int a = 10;
    int b = 20;

    // Interpolate between a and b with t in the range [0, 1]
    float t = 2;
    int result = lerp(a, b, t);

    printf("Linear interpolation between %d and %d at t=%f is: %d\n", a, b, t, result);

    return 0;
}
