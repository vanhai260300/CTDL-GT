#include <stdio.h>
#include <string.h>
struct SinhVien {
	char masv[15], tensv[17], lop[8];
	float dtb;
};
struct Node_List {
	SinhVien data;
	Node_List *Adr_ItAf;
};
Node_List *Add_Af(Node_List *H, Node_List *p)
{
	if(H==NULL)
		H=p;
	else
		{
			Node_List *tmp=H;
			while(tmp->Adr_ItAf!=NULL)
				tmp=tmp->Adr_ItAf;
			tmp->Adr_ItAf=p;
		}
	return H;
}
Node_List *INPUT(Node_List *H,int n)
{
	for(int i=1;i<=n;++i)
	{
		fflush(stdin);
		Node_List *It= new Node_List;
		printf("Sinh vien thu %d: " ,i);
		printf("\nNhap ma sinh vien: ");
		gets(It->data.masv);
		printf("Nhap ten sinh vien: ");
		gets(It->data.tensv);
		printf("Nhap lop sinh vien: ");
		gets(It->data.lop);
		printf("Nhap diem trung binh: ");
		scanf("%f" ,&It->data.dtb);
		It->Adr_ItAf=NULL;
		H=Add_Af(H,It);
	}
	return H;
}
void BRW(Node_List *H)
{
	Node_List *tmp=H;
	if(H==NULL)
		printf("Danh sach NULL");
	while(tmp!=NULL)
	{
		printf("\n\n| %10s | %20s | %5s | %2.2f |" ,tmp->data.masv ,
				tmp->data.tensv ,tmp->data.lop ,tmp->data.dtb) ;
		tmp=tmp->Adr_ItAf;
	}
}
Node_List *Search_It(Node_List *H,char info[])
{
	Node_List *tmp=H;
	while(tmp!=NULL)
	{
		if(strcmp(tmp->data.lop,info)==0)
			return tmp;
		tmp=tmp->Adr_ItAf;
	}
	return NULL;			
}
Node_List *Del(Node_List *H, char info[])
{
	Node_List *IT=Search_It(H,info);
	if(IT==NULL)
		return H;
	if(IT==H)
		{
			H=H->Adr_ItAf;
			IT->Adr_ItAf=NULL;
			return Del(H,info);
		}
	Node_List *tmp=H;
	while(tmp->Adr_ItAf!=IT)
		tmp=tmp->Adr_ItAf;
	tmp->Adr_ItAf=IT->Adr_ItAf;
	IT->Adr_ItAf=NULL;
	return Del(H,info);
}
Node_List *DTB1(Node_List *H)
{
	Node_List *hd=NULL,*tmp=H;
	while(tmp!=NULL)
	{
		if(tmp->data.dtb<5)
			{
				Node_List *p=new Node_List;
				p->data=tmp->data;
				p->Adr_ItAf=NULL;
				hd=Add_Af(hd,p);
			}
		tmp=tmp->Adr_ItAf;
	}
	return hd;
}
Node_List *DTB2(Node_List *H)
{
	Node_List *hd=NULL,*tmp=H;
	while(tmp!=NULL)
	{
		if(tmp->data.dtb>=5)
			{
				Node_List *p=new Node_List;
				p->data=tmp->data;
				p->Adr_ItAf=NULL;
				hd=Add_Af(hd,p);
			}
		tmp=tmp->Adr_ItAf;
	}
	return hd;
}
main()
{
	Node_List *Hd,*Hd1,*Hd2;
	int n;
	char l[10];
	printf("Nhap so sinh vien : ");
	scanf("%d" ,&n);
	Hd= INPUT(NULL,n)	;
	BRW(Hd);
	fflush(stdin);
	printf("\nNhap lop muon xoa: ");
	gets(l);
	Hd=Del(Hd,l);
	printf("Danh sach sau khi xoa la: ");
	BRW(Hd);
	Hd1=DTB1(Hd);
	printf("\n Danh sach  dtb <5 \n");
	BRW(Hd1);
	Hd2=DTB2(Hd);
	printf("\n Danh sach  dtb >=5 \n");
	BRW(Hd2);
	
}
