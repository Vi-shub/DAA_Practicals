#include <stdio.h>
#include <math.h>

double fun1(double n)
{
return log(n);
}
double fun2(double n)
{
return n*log2(n);
}
double fun3(double n)
{
return n;
}
double fun4(double n)
{
return log2(log2(n));
}
double fun5(double n)
{
return pow(sqrt(2),log2(n)) ;
}
double fun6(double n)
{
return pow(2,log2(n));
}
double fun7(double n)
{
return pow(2,sqrt(2*log2(n)));
}
double fun8(double n)
{
return sqrt(log2(n));
}
double fun9(double n)
{
return log2(n);
}
double fun10(double n)
{
return pow(n,1/log2(n));
}

double fun11(double n)
{
double fac = 1;
for(int i=1;i<=n;i++)
{
fac = fac*i;
}
return fac;
}

void main()
{
int A[] = {0, 10, 20, 30, 40 ,50, 60, 70, 80, 90, 100};
printf("\nX\tFun_1\tFun_2\tFun_3\tFun_4\tFun_5\tFun_6\tFun_7\tFun_8\tFun_9\tFun_10\n\n");
for(int i=0; i<=10; i++)
{
printf("%d ", A[i]);
printf("\t");
printf("%0.2f",fun1(A[i]));
printf("\t");
printf("%0.2f",fun2(A[i]));
printf("\t");
printf("%0.2f",fun3(A[i]));
printf("\t");
printf("%0.2f",fun4(A[i]));
printf("\t");
printf("%0.2f",fun5(A[i]));
printf("\t");
printf("%0.2f",fun6(A[i]));
printf("\t");
printf("%0.2f",fun7(A[i]));
printf("\t");
printf("%0.2f",fun8(A[i]));
printf("\t");
printf("%0.2f",fun9(A[i]));
printf("\t");
printf("%0.2f\n",fun10(A[i]));
}
printf("\nX\tFun_11\n");
for(int i=0; i<=20; i+=2)
{
printf("%d ",i);
printf("\t");
printf("%0.2f\n",fun11(i));
}

}
