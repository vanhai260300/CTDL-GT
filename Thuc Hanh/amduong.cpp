#include<stdio.h>
int main()
{
	int a;
	printf("Nhap a: ");
	scanf("%d",&a);
	if(a>0)
		printf("so %d la so duong!!!",a);
	else
		if(a<0)
			printf("so %d la so am!!!",a);
		else
			printf("So %d la so 0",a);
}
