#include<stdio.h>
void NHAP(int ds[], int pt)
{
	for(int i=0;i<pt;i++)
	{
		printf("Nhap phan tu thu %d: ",i);
		scanf("%d",&ds[i]);
	}
	
}
void XUAT(int ds[], int pt)
{
	for(int i=0;i<pt;i++)
	{
		printf("%d\t",ds[i]);
	}
}
void TKNP(int ds[],int pt,int x)
{
	int a,,b,c;
	a=1;
	b=pt;
}
main()
{
	int a[100],  n;
	printf("Nhap so pahn tu: ");
	scanf("%d",&n);
	NHAP(a,n);
	XUAT(a,n);
}
