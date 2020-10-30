#include <stdio.h>
#include <conio.h>
#include <string.h>
//Zm=26;
char *Proccess(char *input, int k)
{
    char *temp = new char[1000]; 
	strcpy(temp,input);
    for (int i=0; i<strlen(temp); i++)
	{
        int x = (int)temp[i]; 
        int y = x+k%26; //26 chu cai
        int sp; 
        if (x>64 && x<91) //chu cai in trong ascii
            sp=0; 
        else 
			if (x>96 && x<123) //chu cai thuong trong ascii
            	sp=32; 
	        else 
	            y=x; 
	    if (y>=90+sp) 
			y=y-k;
	    else 
			if (y<=65+sp) 
				 y=y+k; 
    	temp[i] = (char)y; 
    } 
    return temp; 
} 
char *Encrypt(char *input, int k) //k la ma dich vong
{ 
    return Proccess(input,k); 
} 
 
main(){ 
    char str[100];
	printf("Nhap chuoi: "); 
    gets(str);
     printf("Chuoi truoc khi ma hoa : %s",str); 
    printf("\nChuoi sau khi ma hoa: %s \n",Encrypt(str,5));
    getch();
}
