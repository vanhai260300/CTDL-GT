#include<stdio.h>
#include<conio.h>
#include<string.h>

void NenChuoi(char str1[],char str2[])
{
	char kt[2];
	int dem=0, demkt=1;
	for(int i=0;i<strlen(str1);i++)
	{	
		if(str1[i]==str1[i+1])
			demkt=demkt+1;
		else
		{
			sprintf(kt,"%d",demkt);
			if(demkt!=1)
			{
				str2[dem]=kt[0];
				str2[dem+1]=str1[i];
				dem=dem+2;
			}
			else
			{
				str2[dem]=str1[i];
				dem=dem+1;
			}
			demkt=1;
		}
	}
	str2[dem]='\0';
}
main()
{
	char str1[30],str2[30];
	fflush(stdin);
	printf("Nhap chuoi:");
	gets(str1);
	NenChuoi(str1,str2);
	printf("Chuoi da nen: %s",str2);
}

