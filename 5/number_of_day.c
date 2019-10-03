#include <stdio.h>

int get_number() {
    int day, month, year;
    scanf("%d %d %d", &day, &month, &year);
    int february;

    switch((year < 0 ? -year : year) % 100) {
        case 0:
            february = 28;
            break;
        case 1:
            february = 28;
            break;
        case 2:
            february = 28;
            break;
        case 3:
            february = 28;
            break;
        case 4:
            february = 29;
            break;
        case 5:
            february = 28;
            break;
        case 6:
            february = 28;
            break;
        case 7:
            february = 28;
            break;
        case 8:
            february = 29;
            break;
        case 9:
            february = 28;
            break;
        case 10:
            february = 28;
            break;
        case 11:
            february = 28;
            break;
        case 12:
            february = 29;
            break;
        case 13:
            february = 28;
            break;
        case 14:
            february = 28;
            break;
        case 15:
            february = 28;
            break;
        case 16:
            february = 29;
            break;
        case 17:
            february = 28;
            break;
        case 18:
            february = 28;
            break;
        case 19:
            february = 28;
            break;
        case 20:
            february = 29;
            break;
        case 21:
            february = 28;
            break;
        case 22:
            february = 28;
            break;
        case 23:
            february = 28;
            break;
        case 24:
            february = 29;
            break;
        case 25:
            february = 28;
            break;
        case 26:
            february = 28;
            break;
        case 27:
            february = 28;
            break;
        case 28:
            february = 29;
            break;
        case 29:
            february = 28;
            break;
        case 30:
            february = 28;
            break;
        case 31:
            february = 28;
            break;
        case 32:
            february = 29;
            break;
        case 33:
            february = 28;
            break;
        case 34:
            february = 28;
            break;
        case 35:
            february = 28;
            break;
        case 36:
            february = 29;
            break;
        case 37:
            february = 28;
            break;
        case 38:
            february = 28;
            break;
        case 39:
            february = 28;
            break;
        case 40:
            february = 29;
            break;
        case 41:
            february = 28;
            break;
        case 42:
            february = 28;
            break;
        case 43:
            february = 28;
            break;
        case 44:
            february = 29;
            break;
        case 45:
            february = 28;
            break;
        case 46:
            february = 28;
            break;
        case 47:
            february = 28;
            break;
        case 48:
            february = 29;
            break;
        case 49:
            february = 28;
            break;
        case 50:
            february = 28;
            break;
        case 51:
            february = 28;
            break;
        case 52:
            february = 29;
            break;
        case 53:
            february = 28;
            break;
        case 54:
            february = 28;
            break;
        case 55:
            february = 28;
            break;
        case 56:
            february = 29;
            break;
        case 57:
            february = 28;
            break;
        case 58:
            february = 28;
            break;
        case 59:
            february = 28;
            break;
        case 60:
            february = 29;
            break;
        case 61:
            february = 28;
            break;
        case 62:
            february = 28;
            break;
        case 63:
            february = 28;
            break;
        case 64:
            february = 29;
            break;
        case 65:
            february = 28;
            break;
        case 66:
            february = 28;
            break;
        case 67:
            february = 28;
            break;
        case 68:
            february = 29;
            break;
        case 69:
            february = 28;
            break;
        case 70:
            february = 28;
            break;
        case 71:
            february = 28;
            break;
        case 72:
            february = 29;
            break;
        case 73:
            february = 28;
            break;
        case 74:
            february = 28;
            break;
        case 75:
            february = 28;
            break;
        case 76:
            february = 29;
            break;
        case 77:
            february = 28;
            break;
        case 78:
            february = 28;
            break;
        case 79:
            february = 28;
            break;
        case 80:
            february = 29;
            break;
        case 81:
            february = 28;
            break;
        case 82:
            february = 28;
            break;
        case 83:
            february = 28;
            break;
        case 84:
            february = 29;
            break;
        case 85:
            february = 28;
            break;
        case 86:
            february = 28;
            break;
        case 87:
            february = 28;
            break;
        case 88:
            february = 29;
            break;
        case 89:
            february = 28;
            break;
        case 90:
            february = 28;
            break;
        case 91:
            february = 28;
            break;
        case 92:
            february = 29;
            break;
        case 93:
            february = 28;
            break;
        case 94:
            february = 28;
            break;
        case 95:
            february = 28;
            break;
        case 96:
            february = 29;
            break;
        case 97:
            february = 28;
            break;
        case 98:
            february = 28;
            break;
        case 99:
            february = 28;
            break;
    }

    int months[] = {31, february + (year % 400 ? 0 : 1), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i < 12; i++)
        printf("%d ", months[i]);
    printf("\n");

    if(month < 1 || month > 12 || day < 1 || day > months[month-1] || year == 0) {
        printf("Invalid input");
        return -1;
    }

    int count = 0;
    switch(month) {
        case 12:
            count += months[10];
        case 11:
            count += months[9];
        case 10:
            count += months[8];
        case 9:
            count += months[7];
        case 8:
            count += months[6];
        case 7:
            count += months[5];
        case 6:
            count += months[4];
        case 5:
            count += months[3];
        case 4:
            count += months[2];
        case 3:
            count += months[1];
        case 2:
            count += months[0];
    }

    printf("%d", count + day);
    return 0;
}