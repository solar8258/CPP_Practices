#include <stdio.h>
#include <stdint.h>
typedef union {
    uint32_t i;
    char c[sizeof(uint32_t)];
} EndianTest;

int main() {
    EndianTest test;
    test.i = 0x01020304;
    printf("c[0]:%p, c[3]:%p\n",&test.c[0],&test.c[3]);  //c[0]:00000000005ffe9c, c[3]:00000000005ffe9f
    if (test.c[0] == 0x04 && test.c[3] == 0x01) {  //
        printf("System is Little Endian.\n");
    } else if (test.c[0] == 0x01 && test.c[3] == 0x04) {
        printf("System is Big Endian.\n");
    } else {
        printf("Unknown endianness!\n");
    }

    return 0;
}