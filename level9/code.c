#include <cstring>   // for strlen, memcpy
#include <cstdlib>   // for _exit
#include <iostream>  // triggers ios_base::Init static init

class N {
public:
    // Virtual table pointer at offset 0
    // Integer member at offset 0x68 (104 bytes in)
    // Total object size: 0x6c (108 bytes) — allocated via operator new

    int value;          // stored at offset 0x68
    char annotation[100]; // stored at offset 0x04, 100 bytes for the string

    // Constructor: takes an int, sets vtable and stores the value
    N(int v) {
        // vtable set implicitly by compiler to 0x8048848
        value = v;
    }

    // setAnnotation: copies a C-string into offset +4 of the object
    void setAnnotation(char* str) {
        memcpy(annotation, str, strlen(str));
    }

    // operator+: adds the value fields of two N objects
    int operator+(N& other) {
        return this->value + other.value;
    }

    // operator-: subtracts the value fields of two N objects
    int operator-(N& other) {
        return this->value - other.value;
    }

    // Virtual function called via vtable (index 0)
    // The exact body isn't in this translation unit,
    // but it's declared virtual and called through the vtable
    virtual int someVirtualMethod(N* other) = 0; // or defined elsewhere
};

int main(int argc, char** argv) {
    // Exit if no arguments provided (argc must be > 1)
    if (argc <= 1) {
        _exit(1);
    }

    // Allocate first N object with value 5
    N* a = new N(5);

    // Allocate second N object with value 6
    N* b = new N(6);

    // Call a->setAnnotation(argv[1])
    a->setAnnotation(argv[1]);

    // Call b's virtual method (index 0 in vtable), passing a as argument
    // Equivalent to: b->virtualMethod(a)
    b->someVirtualMethod(a);  // called via vtable: (*b->vtable[0])(b, a)

    return 0;
}