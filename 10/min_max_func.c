void min_max_elems(int *array, int arraysize, int * min, int * max) {
    int tmax = array[0], tmin = array[0];
    for(int i = 1; i < arraysize; i++) {
        tmin = tmin > array[i] ? array[i] : tmin;
        tmax = tmax < array[i] ? array[i] : tmax;
    }

    *min = tmin;
    *max = tmax;
}

/*
int main() {
    int array[6] = {0, 1, 5, 3, -6, 24};
    int min, max, size = 6;

    min_max_elems(array, size, &min, &max);
    printf("%d %d", min, max);

    return 0;
}
 */