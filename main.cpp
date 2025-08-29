#include <print>


int round_to_int(float f) {
    int r;
    asm("vcvtr.s32.f32 %[r], %[f]" : [r] "=t" (r) : [f] "t" (f));
    return r;
}

int main() {
    float f = 1.55;
    int rounded = round_to_int(f);
    for (float f = -4; f < 4; f += .1) {
        std::print("Value: {:4.1f}, ", f);
        std::println("Rounded: {:2}", round_to_int(f));
    }
    //asm("bkpt #0");
    return 0;
}