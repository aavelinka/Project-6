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

int enter_independently(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        if (scanf_s("%d", &a[i]) != 1) {
            printf("Data is not correct, try again");
            return 0;
        }
    }
    return 1;
}

void enter_random(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 21 - 10;
        printf("%d ", a[i]);
    }
}

void printf_array(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void sort_direct_merge(int* a, int n) { //сортировка методом слияния по убыванию
    if (n < 2)
        return;

    sort_direct_merge(a, n / 2);
    sort_direct_merge(&a[n / 2], n - (n / 2));

    int* tmp = (int*)malloc(n * sizeof(int));

    int idtmp = 0, idl = 0, idr = n / 2;
    while ((idl < n / 2) && (idr < n)) {
        if (a[idl] > a[idr])
            tmp[idtmp++] = a[idl++];
        else
            tmp[idtmp++] = a[idr++];
    }

    while (idl < n / 2) tmp[idtmp++] = a[idl++];
    while (idr < n) tmp[idtmp++] = a[idr++];

    for (idl = 0; idl < n; idl++) {
        a[idl] = tmp[idl];
    }
    free(tmp);
}

int main() {
    srand(time(NULL));
    int n = 0;

    do {
        scanf_s("%*[^\n]");

        printf("Enter the numbers of desired rows for the array: ");
        if (!enter_number(&n)) {
            continue;
        }

        int* a = (int*)malloc(n * sizeof(int));  // выделяем память под элементы
        if (!a) {
            printf("Memory allocation failed");
            continue;
        }


        puts(" Do you want to enter the data yourself or randomly?\n Please, press 0 - for independently, 1 - for randomly.");
        char option_1 = _getch();
        if (option_1 == '0') {
            if (!enter_independently(a, n)) {
                printf("Data is not correct, please, try again\n");
                break;
            }
        }
        else if (option_1 == '1') {
            enter_random(a, n);
        }
        else {
            printf("Data is incorrect\n");
            break;
        }

     
      int* positive = (int*)malloc(n / 2 * sizeof(int));
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                positive[j] = a[i];
                j++;
            }
        } 
        
        sort_direct_merge(positive, j);

        j = 0;
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                a[i] = positive[j];
                j++;
            }
        }
        

        printf("\nThe result: ");
        printf_array(a, n);

        free(a);
       
    } while (puts("Contiue - 1, Exit - 0"), _getch() == '1');

    return 0;
}
