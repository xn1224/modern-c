#include <stdio.h>

void create_magic_square(int n, char magic_square[n][n]);
void print_magic_square(int n, char magic_square[n][n]);

int main(void)
{
    int n;

    printf("This program creates a magic square of s specified size.\n");
    printf("The size must be a odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    char arr[n][n];
    
    create_magic_square(n, arr);
    print_magic_square(n, arr);

    return 0;
}

void create_magic_square(int n, char magic_square[n][n])
{
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            magic_square[i][j] = 0;
        }
    }

    // init
    i = 0;
    j = n / 2;
    magic_square[i][j] = 1;

    for (k = 2; k <= n*n; k++) {
        i--;
        j++;
        i = (i + n) % n;
        j = (j + n) % n;

        if (magic_square[i][j] != 0) {
            i++;
            j--;
            i++;
            i = (i + n) % n;
            j = (j + n) % n;
        }
        magic_square[i][j] = (char)k;
        //printf("i = %d, j = %d, k = %d || ", i, j, k);
    }
    //printf("\n");
}
void print_magic_square(int n, char magic_square[n][n])
{
    int i ,j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2d ", magic_square[i][j]);
        }
        printf("\n");
    }
}
