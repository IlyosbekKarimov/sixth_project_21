/*------------------------------------
        Здравствуй, человек!
        Чтобы получить ключ
        поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

#define NMAX 10

void input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
        Функция получает массив данных
        через stdin.
        Выдает в stdout особую сумму
        и сформированный массив
        специальных элементов
        (выбранных с помощью найденной суммы):
        это и будет частью ключа
-------------------------------------*/
int main() {
    int n;
    if (scanf("%d", &n) != 1) {
        printf("n/a");
        return 0;
    }
    if (n > NMAX) {
        printf("n/a");
        return 0;
    }
    int arr[NMAX], numbers[NMAX];
    int *lenght = &n;
    input(arr, lenght);
    if (*lenght == 0) {
        return 0;
    }
    if (getchar() == ' ') {
        printf("n/a");
        return 0;
    }
    int number = sum_numbers(arr, n);
    int k = find_numbers(arr, n, number, numbers);
    printf("%d", number);
    puts("");
    output(numbers, k);
    return 0;
}

void input(int *buffer, int *length) {
    int error = 1;
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &buffer[i]) != 1) {
            printf("n/a");
            error = 0;
            break;
        }
    }
    if (!error) {
        *length = 0;
    }
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", buffer[i]);
    }
}

/*------------------------------------
        Функция должна находить
        сумму четных элементов
        с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }

    return sum;
}

/*------------------------------------
        Функция должна находить
        все элементы, на которые нацело
        делится переданное число и
        записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int k = 0;
    for (int i = 0; i < length; i++) {
        if (buffer[i] != 0 && number % buffer[i] == 0) {
            numbers[k++] = buffer[i];
        }
    }
    return k;
}
