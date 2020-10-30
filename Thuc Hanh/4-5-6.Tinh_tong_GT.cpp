#include<stdio.h>
int GT(int n)
{
	if(n==1)
		return 1;
	else
		return n*GT(n-1);
}
float TT(int n)
{
	if(n==1)
		return 1;
	else
		return 1.0/GT(n)+TT(n-1);
}
float TTLeD(int n)
{
	if(n==1)
		return 1;
	else
		if(n%2==0)
			return -1.0/GT(n)+TTLeD(n-1);
		else
			return 1.0/GT(n)+TTLeD(n-1);
}
float TTLeA(int n)
{
	if(n==1)
		return -1;
	else
		if(n%2==0)
			return 1.0/GT(n)+TTLeA(n-1);
		else
			return -1.0/GT(n)+TTLeA(n-1);
}
main()
{
	int x;
	printf("Nhap x: ");
	scanf("%d",&x);
	printf("A1=%f\n",TT(x));
	printf("A2=%f\n",TTLeD(x));
	printf("A3=%f\n",TTLeA(x));
}

