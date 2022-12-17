#include<stdio.h>
#define N 38
void add_big(char a[N], char b[N], char c[N+1]);

int main(){
    char a[N] = "8763845638363774673957584937685934737";
    char b[N] = "7638456383637746739575849376859343432";
    char c[N+1]="";
    printf("%s\n%s\n",a,b);
    add_big(a,b,c);
    printf("%s",c);
    return 0;
}

void add_big(char a[N], char b[N], char c[N+1]){
 	char add = 0; 
  	for(int i = N-2; i >= 0; i--){
        c[i+1] = a[i] + b[i] + add - '0';
        add = 0;
        if(c[i+1] > '9'){
            add = 1;
            c[i+1] -= 10;
        }
    }
  	c[0] = add;
    c[N] = '\0';
}