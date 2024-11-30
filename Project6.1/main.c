#include <malloc.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>

int enter_number(int* n) {
    if (scanf_s("%d", n) != 1 || *n <= 0) {
        printf("Data is incorrect\n");
        return 0;
    }
    return 1;
}

int enter_independently(int** a, int m, int i) {
        for (int j = 0; j < m; ++j) {
            if (scanf_s("%d", &a[i][j]) != 1) {
                printf("Data is not correct, try more");
                return 0;
            }
        }
        return 1;
}

void enter_random(int** a, int m, int i) {
        for (int j = 0; j < m; ++j) {
            a[i][j] = rand() % 21 - 10;
            printf("%d ", a[i][j]);
        }
        printf("\n");
}
       
void printf_array(int** a, int m, int i){ 
    for (int j = 0; j < m; ++j) {
        printf("%d ", a[i][j]);
    }
    printf("\n");
}

int sum(int** a, int m, int i, int s) {
    for (int j = 0; j < m; ++j) {
        s += a[i][j];
    }
    return s;
}

void swap_rows(int** a, int m, int i) {
    for (int j = 0; j < m; j++) {
        int tmp = a[i][j];
        a[i][j] = a[i + 2][j];
        a[i + 2][j] = tmp;
    }
}

void swap_odd_rows(int** a, int* count, int n, int m) {
    int c = 0;
    for (int i = 0; i < n; i += 2) {
        if (count[c] < count[c + 1]) {
            swap_rows(a, m, i);
            c++;
        }
    }
}

int main() {
    srand(time(NULL));
    int n = 0, m = 0;

    do {
        scanf_s("%*[^\n]");

        printf("Enter the numbers of desired rows for the matrics: ");
        if(!enter_number(&n)) {
            continue;
        }
        int** a = (int**)malloc(n * sizeof(int*));  // выделяем память под количество строк
        if (!a) {
            printf("Memory allocation failed");
            continue;
        }

        int* count = (int*)malloc(n * sizeof(int));  //  выделяем память для запоминания суммы элементов в нечет строке
        if (!count) {
            printf("Memory allocation failed");
            continue;
        }

        printf("Enter the number of colls for the matrics: ");
        if(!enter_number(&m)){
            continue;
        }

        for (int i = 0; i < n; ++i) {
            a[i] = (int*)malloc(m * sizeof(int)); //выделение памяти для подмассива
            if (!a[i]) {
                printf("Memory allocation failed");
                for (int k = 0; k < i; ++k) {
                    free(a[k]);
                }
                free(a);
                break;
            }

            puts(" Do you want to enter the data yourself or randomly?\n Please, press 0 - for independently, 1 - for randomly.");
            char option_1 = _getch();
            if (option_1 == '0') {
                if (!enter_independently(a, m, i)) {
                    printf("Data is not correct, please, try again\n");
                    break;
                }
            }
            else if (option_1 == '1') {
                enter_random(a, m, i);
            }
            else {
                printf("Data is incorrect\n");
                break;
            }
        }

        int c = 0;
        for (int i = 0; i < n; i += 2) {
            int s = 0;
            count[c] = sum(a, m, i, s);
            c++;
        }
        
        swap_odd_rows(a, count, n, m);

        printf("\nResult:\n");
        for (int i = 0; i < n; ++i) {
            printf_array(a, m, i);
        }
       
        for (int i = 0; i < n; ++i) {
            free(a[i]); 
        }
        free(count);
        free(a);

    } while (puts("Contiue - 1, Exit - 0"), _getch() == '1');

    return 0;
}
