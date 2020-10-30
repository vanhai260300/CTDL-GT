#include<stdio.h>
int SLN(int n)
{
	if(n<10)
		return n;
	if((n%10)>SLN(n/10))
		return n%10;
	else
		return SLN(n/10);
}	
int SBN(int m)
{
	if(m<10)
		return m;
	if((m%10)<SBN(m/10))
		return m%10;
	else
		return SBN(m/10);
}
int main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("So lon nhat %d\n",SLN(x));
	printf("So be nhat %d",SBN(x));
}
