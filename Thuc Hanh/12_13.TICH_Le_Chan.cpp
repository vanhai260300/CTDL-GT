#include<stdio.h>
int TICH_Le(int n)
{
	if (n/10==0)
		return n;
	else
		if((n%10)%2!=0)
			return (n%10)*TICH_Le(n/10);
		else
			TICH_Le(n/10);
}
int TICH_Chan(int n)
{
	if (n/10==0)
		return n;
	else
		if((n%10)%2==0)
			return (n%10)*TICH_Chan(n/10);
		else
			TICH_Chan(n/10);
}
main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("Tich so Le=%d\n",TICH_Le(x));
	printf("Tich so Chan=%d\n",TICH_Chan(x));
}
