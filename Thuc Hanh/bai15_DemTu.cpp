#include<stdio.h>
#include<string.h>
int demtu(int dem,int i,int n,char *s){
  if(i == (n - 1))
    return dem;
  if(i == 0 && s[i] != ' ')
    dem = 1;
  if(s[i] == ' ' && s[i + 1] != ' ')
    dem++;
  return demtu(dem,i + 1,n,s);
}
main() {
  char s[100];
  int kq,dem = 0;
  int n,i = 0;
  printf("nhap chuoi: ");
  gets(s);
  n = strlen(s);
  kq = demtu(dem,i,n,s);
  printf("\nSo tu trong chuoi la: %d",kq);
}
