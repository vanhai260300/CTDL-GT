#include<stdio.h>
int Dem(int n)
{
	if(n==0)
		return 0;
	return Dem(n/10) + 1;
}
int main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("A= %d\n",Dem(x));
}
