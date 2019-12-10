#include <time.h>


struct PlayerScore {
    int army, heroes, resources, total_score;
};


void smartsort(struct PlayerScore array[], int count, int f);
void sort(struct PlayerScore array[], int count, int f);
void naivesort(struct PlayerScore array[], int count, int f);


void printPlayerScore(struct PlayerScore ps) {
    printf("army = %d, heroes = %d, resources = %d, total_score = %d\n",
            ps.army, ps.heroes, ps.resources, ps.total_score);
}

void printPlayerScoreArray(struct PlayerScore array[], int count) {
    for(int i = 0; i < count; i++)
        printPlayerScore(array[i]);
}

int maxValueOfParam = 99;
struct PlayerScore randomStruct() {
    struct PlayerScore temp = {
            1 + rand() % maxValueOfParam,
            1 + rand() % maxValueOfParam,
            1 + rand() % maxValueOfParam,
            1 + rand() % maxValueOfParam
    };

    return temp;
}

int getValueByIndex(struct PlayerScore* pointer, int index) {
    return *(int*) ((int) pointer + 4 * index);
}

// a = b -> =0
// a < b -> <0
// a > b -> >0
int compare(struct PlayerScore *array, int a, int b, int indexOfField) {
    return getValueByIndex(&array[a], indexOfField) - getValueByIndex(&array[b], indexOfField);
}

int swaps = 0;
void swap(struct PlayerScore array[], int a, int b) {
    if(a != b) {
        swaps++;
        struct PlayerScore temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }
}

void naivesort(struct PlayerScore array[], int count, int indexOfField) {
    for(int i = 1; i < count; i++)
        for(int tempi = i; tempi > 0; tempi--)
            if(compare(array, tempi, tempi - 1, indexOfField) < 0)
                swap(array, tempi, tempi - 1);
            else break;
}

struct Pair { int a,b; };

void naivesortTHX4POLIMORPHISM_FuckC(struct Pair *array, int count) {
    for(int i = 1; i < count; i++)
        for(int j = i; j > 0; j--)
            if(array[j].a < array[j-1].a) {
                struct Pair temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            } else break;
}

struct Pair pairFromPSbyIndex(struct PlayerScore array[], int index, int field) {
    struct Pair p = { getValueByIndex(&array[index], field), index};
    return p;
}

void smartsort(struct PlayerScore array[], int count, int f) {
    if(count == 2 && compare(array, 0, 1, f) > 0)
            swap(array, 0, 1);

    if(count > 2) {
        int try = count - 1;
        while (!compare(array, 0, try, f))
            if (!try--)
                return;
        swap(array, try, count - 1);

        if (count > 31) {
            int x = ((sizeof(count) << 3) - __builtin_clz(count) << 1) + 2;

            struct Pair vars[x];
            vars[0] = pairFromPSbyIndex(array, 0, f);
            vars[1] = pairFromPSbyIndex(array, count - 1, f);
            for(int i = 2; i < x; i++) {
                // Thx C 4 implementation/platform dependent code #FuckC
                int t = (((rand() << 15) + rand()) & 0x7FFFFFFF) % count;
                vars[i] = pairFromPSbyIndex(array, t, f);
            }

            naivesortTHX4POLIMORPHISM_FuckC(vars, x);
            swap(array, 0, vars[x / 3].b);
            swap(array, count - 1, vars[(x / 3) << 1].b);
        }

        if (compare(array, 0, count - 1, f) > 0)
            swap(array, 0, count - 1);

        int left = 1, right = count - 2;
        for(int i = left; i <= right; i++) {
            if(compare(array, i, 0, f) < 0)
                swap(array, i, left++);
            else if(compare(array, i, count-1, f) > 0)
                swap(array, i--, right--);
        }

        swap(array, 0, left - 1);
        swap(array, count - 1, right + 1);

        //Поставлю свечку, если это заработает
        sort(array, left, f);
        sort(array + left, right - left + 1, f);
        sort(array + right + 1, count - right - 1, f);
    }
}


void sort(struct PlayerScore array[], int count, int f) {
    if(count < 2) return;
    else if(count < 32) naivesort(array, count, f);
    else smartsort(array, count, f);
}

char needToPrint = 0;
int scoresort() {
    srand(time(NULL));
    /*
    printf("Enter count\n");
    int count = -1;
    int c = scanf("%d", &count);
    if(c != 1 || count == -1) {
        printf("Wrong count %d", count);
        exit(-1);
    }
     */

    int count = 100;
    struct PlayerScore array[count]; //На стеке, потому что могу

    for(int i = 0; i < count; i++) array[i] = randomStruct();
    if(needToPrint) {
        printf("Original array:\n");
        printPlayerScoreArray(array, count);
    }

    struct PlayerScore copy[count];
    for(int i = 0; i < count; i++) {
        copy[i] = array[i];
    }

    /*
    int indexOfField = -1;
    printf("Enter index of field [0-3]\n");
    int s = scanf("%d", &indexOfField);
    if(s != 1 || indexOfField < 0 || indexOfField > 3) {
        printf("Wrong index %d", indexOfField);
        exit(-1);
    }
     */
    int indexOfField = 0;

    swaps = 0;
    smartsort(array, count, indexOfField);
    printf("swaps = %d\n", swaps);

    swaps = 0;
    naivesort(copy, count, indexOfField);
    printf("naive_swaps = %d\n", swaps);

    if(needToPrint) {
        printf("\nSorted array:\n");
        printPlayerScoreArray(array, count);
    }

    return 0;
}