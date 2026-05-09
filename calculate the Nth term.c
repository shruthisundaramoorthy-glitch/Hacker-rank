#include <stdio.h>

int main() {

    int n;
    int a, b, c, d;
    int i;

    scanf("%d", &n);
    scanf("%d %d %d", &a, &b, &c);

    if(n == 1)
        printf("%d", a);

    else if(n == 2)
        printf("%d", b);

    else if(n == 3)
        printf("%d", c);

    else {

        for(i = 4; i <= n; i++) {

            d = a + b + c;

            a = b;
            b = c;
            c = d;
        }

        printf("%d", d);
    }

    return 0;
}
