#include<stdio.h>
int SHH(int n,int i)
{
	if(i==n)
		return 0;
	else
		if(n%i==0)
			return i+SHH(n,i+1);
		else
			return SHH(n,i+1);
}
int main()
{
	int x,i=1;
	printf("Nhap x: ");
	scanf("%d",&x);
	int Ktr=SHH(x,i);
	printf("%d\n",Ktr);
	if (SHH(x,i)==x)
		printf("La so hoan hao");
	else
		printf("Khong");
}
