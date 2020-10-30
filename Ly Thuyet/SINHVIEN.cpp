#include<stdio.h>
#include<string.h>
struct SinhVien{
	char masv[13],hl[10],ten[6];
	float dtb;
};
void Nhap(SinhVien ds[], int *n)
{
	printf("Nhap so Sinh Vien ");
	scanf("%d",&*n);
	int i;
	for	(i=1;i<=*n;i++){
		fflush(stdin);
		printf("Nhap ma sv thu %d: ",i);
		gets(ds[i].masv);
		printf("Nhap ho va ten: ");
		gets(ds[i].hl);
		gets(ds[i].ten);
		printf("DTB: ");
		scanf("%f",&ds[i].dtb);
	}
}
void IN(SinhVien ds[], int n)
{
	for(int i=1;i<=n;i++){
		printf("%13s|%10s%5s|%2f\n",ds[i].masv,ds[i].hl,ds[i].ten,ds[i].dtb);
	}
}
int Ktra(SinhVien ds[], int n, char t[6]){
	for(int i=1;i<=n;i++){
		if(strcmp(ds[i].ten,t)==0)
			return 1;
	
	}
	return 0;
}
main()
{
	SinhVien a[100];
	int spt;
	char te[6];
	Nhap(a,&spt);
	fflush(stdin);
	IN(a,spt);
	fflush(stdin);
	printf("Nhap ten: ");
	gets(te);
	if(Ktra(a,spt,te)==1)
		printf(" Co ten sinh vien trong danh sach ");
	else
		printf("Khong cos ten sinh vien trong danh sach");
	
}
