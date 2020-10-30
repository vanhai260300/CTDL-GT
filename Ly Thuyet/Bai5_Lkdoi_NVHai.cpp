#include <stdio.h>
#include <string.h>
struct SINHVIEN {
	char masv[15], tensv[50], lop[8];
	float dtb;
};
struct Node_List {
	SINHVIEN data;
	Node_List *Adr_ItBf,*Adr_ItAf;
};
Node_List *Add_Af(Node_List *H, Node_List *It)
{
	if(H==NULL)
		H=It;
	else
		{
			Node_List *tmp=H;
			while(tmp->Adr_ItAf!=NULL)
				tmp=tmp->Adr_ItAf;
			tmp->Adr_ItAf=It;
			It->Adr_ItBf=tmp;
		}
	return H;
}
Node_List *INPUT1(Node_List *H,int n)
{
	for(int i=1;i<=n;++i)
	{
		fflush(stdin);
		Node_List *p= new Node_List;
		printf("\nSinh vien thu %d: " ,i);
		printf("\nNhap ma sinh vien: ");
		gets(p->data.masv);
		printf("Nhap ten sinh vien: ");
		gets(p->data.tensv);
		printf("Nhap lop sinh vien: ");
		gets(p->data.lop);
		printf("Nhap diem trung binh: ");
		scanf("%f" ,&p->data.dtb);
		p->Adr_ItBf=NULL;
		p->Adr_ItAf=NULL;
		H=Add_Af(H,p);
	}
	return H;
}
Node_List *INPUT2(Node_List *H,int n)
{
	Node_List *p;
	for(int i=n;i>=1;i--)
	{
		fflush(stdin);
		Node_List *It= new Node_List;
		printf("\nSinh vien thu %d: " ,i);
		printf("\nNhap ma sinh vien: ");
		gets(It->data.masv);
		printf("Nhap ten sinh vien: ");
		gets(It->data.tensv);
		printf("Nhap lop sinh vien: ");
		gets(It->data.lop);
		printf("Nhap diem trung binh: ");
		scanf("%f" ,&It->data.dtb);
		It->Adr_ItAf=H;
		H=Add_Af(H,It);
	}
	return H;
}
void BRW(Node_List *H)
{
	Node_List *tmp=H;
	if(H==NULL)
		printf("\n\nDanh sach NULL\n\n");
	while(tmp!=NULL)
	{
		printf("\n\n| %15s | %25s | %8s | %4.1f |" ,
		tmp->data.masv ,tmp->data.tensv ,tmp->data.lop ,tmp->data.dtb);
		tmp=tmp->Adr_ItAf;
	}		
}
Node_List *SEARCH(Node_List *H,char lp[])
{
	Node_List *tmp=H;
	while(tmp!=NULL)
	{
		if(strcmp(tmp->data.lop,lp)==0)
			return tmp;
		tmp=tmp->Adr_ItAf;
	}
	return NULL;			
}
Node_List *DELETE(Node_List *H, char lp[])
{
	Node_List *It =SEARCH(H,lp), *tg;
	if(It ==NULL)
		return H;
	if(It ==H)
		{
			H=H->Adr_ItAf;
			if(H!=NULL)
			{		
				H->Adr_ItBf=NULL;
				It ->Adr_ItAf=NULL;
			}
			return DELETE(H,lp);
		}
	Node_List *tmp=H;
	while(tmp->Adr_ItAf!=It )
		tmp=tmp->Adr_ItAf;
	tg=It ->Adr_ItAf;
	tmp->Adr_ItAf=tg;
	if(tg!=NULL)
		tg->Adr_ItBf=tmp;
	It ->Adr_ItBf=NULL;
	It ->Adr_ItAf=NULL;
	return DELETE(H,lp); 
}
Node_List *DTB1(Node_List *H)
{
	Node_List *Head=NULL,*tmp=H;
	while(tmp!=NULL)
	{
		if(tmp->data.dtb<5)
			{
				Node_List *p=new Node_List;
				p->data=tmp->data;
				p->Adr_ItBf=NULL;
				p->Adr_ItAf=NULL;
				Head=Add_Af(Head,p);
			}
		tmp=tmp->Adr_ItAf;
	}
	return Head;
}
Node_List *DTB2(Node_List *H)
{
	Node_List *Head=NULL,*tmp=H;
	while(tmp!=NULL)
	{
		if(tmp->data.dtb>=5)
			{
				Node_List *p=new Node_List;
				p->data=tmp->data;
				p->Adr_ItBf=NULL;
				p->Adr_ItAf=NULL;
				Head=Add_Af(Head,p);
			}
		tmp=tmp->Adr_ItAf;
	}
	return Head;
}
main()
{
	Node_List *Hd,*Hd1,*Hd2;
	int n;
	char l[10];
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	Hd= INPUT1(NULL,n)	;
	BRW(Hd);
	Hd= INPUT2(NULL,n)	;
	BRW(Hd);
	fflush(stdin);
	printf("\n\nNhap lop muon xoa: ");
	gets(l);
	Hd=DELETE(Hd,l);
	BRW(Hd);
	Hd1=DTB1(Hd);
	printf("\n Danh sach sinh vien dtb <5 \n");
	BRW(Hd1);
	Hd2=DTB2(Hd);
	printf("\n Danh sach sinh vien dtb >=5 \n");
	BRW(Hd2);	
}













