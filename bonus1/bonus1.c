#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// static const char shell_path[] __attribute__((section(".rodata"))) = "/bin/sh";
// static const char shell_argv0[] __attribute__((section(".rodata"))) = "sh";

int main(int argc, char **argv) {
    int length;
    char buffer[40];

    if (argc < 3) {
        return 1;
    }

    length = atoi(argv[1]);
    if (length > 9) {
        return 1;
    }
    printf("Length: %d\n", length);
    memcpy(buffer, argv[2], (size_t)length * 4); //32

    if (length == 0x574f4c46) { //1464814662
        execl("/bin/sh", "sh", (char *)0);
    }

    return 0;
}
