#include <stdio.h>
#include <string.h>

int demTu(char *strHieu,int dem,int n)
{
	if(n>strlen(strHieu)-3)
	return dem;
	if(strHieu[n]!=32 && n==0)
		++dem;
	if(strHieu[n]==32 && strHieu[n+1]!=32)
		{
			++dem;
			return demTu(strHieu,dem,(n+1));
		}
	else
		return demTu(strHieu,dem,(n+1));
}
main()
{
	char strHieu[100];
	printf("Nhap chuoi bat ky: ");
	gets(strHieu);
	printf("%d" ,demTu(strHieu,0,0));
}
