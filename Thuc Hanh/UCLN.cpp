#include<stdio.h>
int UCLN(int a,int b)
{
	if(a==b)
		return a;
	if(a>b)
		return UCLN(a-b,b);
	else
		return UCLN(a,b-a);
}
main()
{
	int a,b;
	printf("nhap a b: ");
	scanf("%d %d",&a,&b);
	printf("UCLN la: %d",UCLN(a,b));
}
