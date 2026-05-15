#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t length_for_bytes(uint32_t bytes) {
    // bytes must be a multiple of 4
    // length = -((2^32 - bytes) / 4)
    return -(int32_t)((0x100000000ULL - bytes) / 4);
}

int main(int argc, char **argv) {
    uint32_t bytes = atoi(argv[1]);
    int32_t len = length_for_bytes(bytes);
    printf("bytes=%u -> length=%d\n", bytes, len);
    return 0;
}