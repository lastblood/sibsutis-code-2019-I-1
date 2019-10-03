#include <stdio.h>

int * find_element(int * begin, int * end, int value) {
    int temp = 0;
    int * pointer = begin;
    while(pointer < end) {
        temp = *pointer;
        if(temp == value) return pointer;
        pointer++;
    }
    return NULL;
}

int _main() {
    printf("Enter array size:");
    int size = 0;
    scanf("%d", &size);
    int array[size];

    printf("Enter array elements:");
    for(int i = 0; i < size; i++) scanf("%d", &array[i]);

    int value = 0;
    printf("Enter element to find:");
    scanf("%d", &value);

    int * result = find_element(&array[0], &array[size], value);
    if(result == NULL) {
        printf("Element %d not found\n", value);
    } else {
        printf("Found %d at pointer %p\n", *result, result);
        *result = *result * -1;
    }

    for(int i = 0; i < size; i++) printf("%d ", array[i]);

    return 0;
}