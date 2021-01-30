#include<stdio.h>

//Tinh giai thua
int factorial(int n){
    int result = 1;
    for (int i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}

int main(){
    FILE * fpointer1 = fopen("TOHOP.INP", "r");
    FILE * fpointer2 = fopen("TOHOP.OUT", "w");
    fprintf(fpointer2, ""); // clear file TOHOP.OUT
    fclose(fpointer2);
    fpointer2 = fopen("TOHOP.OUT", "a");
    
    int n, k;

    while(fscanf(fpointer1,"%d %d", &n, &k) != EOF){
        if (n < 2 || n > 30 || k < 0 || k > n)
            fprintf(fpointer2, "Invalid input\n");
        else
            fprintf(fpointer2, "%d\n", factorial(n)/(factorial(k)* factorial(n - k)));//Tinh to hop
    }
    
    fclose(fpointer1);
    fclose(fpointer2);

    return 0;
}