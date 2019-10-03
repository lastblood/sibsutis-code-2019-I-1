#include <stdio.h>
#include <string.h>

int unique_copy(const int *in, int in_length, int *out, int *out_length) {
    int index = 0;
    for(int i = 0; i < in_length; i++) {
        for(int j = i + 1; j < in_length; j++)
            if(in[i] == in[j]) {
                i = j;
            } else break;
        out[index++] = in[i];
    }
    out_length[0] = index;
    return index;
}

//Простейшая реализация за O(n^2) и Ω(n) с игнорированием дубликатов уже найденных элементов
int unique_copy_unstable(const int *in, int in_length, int *out, int *out_length) {
    char status[in_length];
    memset(status, 0, sizeof(status));
    int x = 0;

    for(int i = 0; i < in_length; i++) {
        if(status[i]) continue;
        int temp = in[i];
        for(int j = i; j < in_length; j++)
            if(temp == in[j])
                status[j] = 1;
        out[x++] = temp;
    }

    out_length[0] = x;
    return x;
}


int _main() {
    int arr[] = {1,2,2,3,1,3,5,1,10,0};
    int len = 10;
    int out_array1[10] = {0};
    int out_len1 = 10;
    int out_array2[10] = {0};
    int out_len2 = 10;
    unique_copy(&arr, len, &out_array1, &out_len1);
    unique_copy_unstable(&arr, len, &out_array2, &out_len2);

    printf("BEFORE: array[%d] = ", len);
    for(int i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\nAFTER unique_copy: array[%d] = ", out_len1);
    for(int i = 0; i < out_len1; i++) printf("%d ", out_array1[i]);
    printf("\nAFTER unique_copy_unstable: array[%d] = ", out_len2);
    for(int i = 0; i < out_len2; i++) printf("%d ", out_array2[i]);
    return 0;
}
