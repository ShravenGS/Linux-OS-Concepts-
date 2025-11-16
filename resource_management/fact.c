#include <stdio.h>

int fact(int n, int f);

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int result = fact(n, 1);
    printf("Factorial = %d\n", result);
}

int fact(int n, int f) {
    if(n != 0)
        return fact(n - 1, f * n);
    else
        return f;
}

