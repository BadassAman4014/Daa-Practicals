#include <stdio.h>
#include <math.h>
void findRoots(int a, int b, int c);
int main(){
    int a = 1, b = -3, c = -4;
    printf("The coefficients of recurrence equation:\nc1: %d\nc2: %d\nc3: %d\n", a, b, c);
    findRoots(a, b, c);
    float a1, b1, c1, a2, b2, c2, x, y, det;
    printf("\nEnter the coefficients of the first equation (a1x + b1y = c1):\n");
    scanf("%f %f %f", &a1, &b1, &c1);

    printf("\nEnter the coefficients of the second equation (a2x + b2y = c2):\n");
    scanf("%f %f %f", &a2, &b2, &c2);
    det = a1 * b2 - a2 * b1;
    if (det == 0) {
        printf("\nThe system of equations has no unique solution.\n");
    } else {
        x = (b2 * c1 - b1 * c2) / det;
        y = (a1 * c2 - a2 * c1) / det;
        printf("The solution is x = %f, y = %f\n", x, y);
    }
    return 0;
}

void findRoots(int a, int b, int c){
    int d = b * b - 4 * a * c;
    if (d > 0){
        printf("\nRoots are real and different.\n");
        int root1 = (-b + sqrt(d)) / (2 * a);
        int root2 = (-b - sqrt(d)) / (2 * a);
        printf("Roots are r1 = %d and r2 = %d\n", root1, root2);
        //tn = (c1*r1^n) + (c2*r2^n) ;
    }
}
