// 4-8 2 1
struct Foo {
    struct Bar *p;
    short x;
    char c;
    // char c[1]; or char c[5];
};

// 4 2 1 1
struct Bar {
    int n;
    short d;
    char c;
    char i;
};

// 8 4 1
struct Baz {
    long l;
    int i;
    char c;
    //char c[3];
};