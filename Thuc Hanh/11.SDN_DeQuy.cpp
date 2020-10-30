#include<stdio.h>
int Dem(int n)
{
	if((n%10)%2==0)
		return 1;
	else{
		if(n==0)
			return 0;
		return Dem(n/10)+1;
}}
int TongSo(int n, int k)
{
	if((n%10)%2==0)
		return 0;
	else{
		if(k>1)		
			return TongSo(n*10,k-1);
		return n;
	}
}
int SDN(int n)
{
		if(n==0)
	 		return 0;
		int D=Dem(n);
		int V=n%10;
		int T=TongSo(V,D);
		return SDN(n/10)+T;
}
main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("A=%d\n",SDN(x));

}

