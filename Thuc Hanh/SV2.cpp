#include<stdio.h>
#include<string.h>
struct SINHVIEN
	{
		char masv[12],holot[20],ten[10];
		float dtb;
	};
	void NHAP(SINHVIEN ds[], int n)
	{
		int i;
		for(i=1;i<=n;i++)
		{
			fflush(stdin);
			printf("Nhap masv thu %d: ",i);
			gets(ds[i].masv);
			printf("Ho va ten: ");
			gets(ds[i].holot);
			gets(ds[i].ten);
			printf("DTB: ");
			scanf("%f",&ds[i].dtb);
			
		}
	}
	void IN(SINHVIEN ds[], int n)
	{
		int i;
		for(i=1;i<=n;i++)
			printf("%10s |%10s %5s| %2f\n",ds[i].masv,ds[i].holot,ds[i].ten,ds[i].dtb);
	}
	int KTRA(SINHVIEN ds[], int n, char t[10])
	{
		int i;
		for(i=1;i<=n;i++)
			if(strcmp(ds[i].ten,t)==0)
				return 1;
			else
				return 0;	
	}
int main()
{
	SINHVIEN a[100];
	int spt;
	char te[10];
	printf("Nhap so sv: ");
	scanf("%d",&spt);
	NHAP(a,spt);
	IN(a,spt);
	fflush(stdin);
	printf("Nhap ten: ");
	gets(te);
	if(KTRA(a,spt,te)==1)
		printf("co");
	else
		printf("Khong");
}
	
