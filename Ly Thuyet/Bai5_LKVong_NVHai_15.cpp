#include <stdio.h>
#include <string.h>
struct SINHVIEN {
	char masv[15], tensv[50], lop[8];
	float dtb;
};
struct Node_List {
	SINHVIEN data;
	Node_List *Adr_ItAf;
};
Node_List *Add_Af(Node_List *H, Node_List *It)
{
	if(H==NULL)
	{
		H=It;
		It->Adr_ItAf=H;
	}
	else
		{
			Node_List *tmp=H;
			while(tmp->Adr_ItAf!=H)
				tmp=tmp->Adr_ItAf;
			tmp->Adr_ItAf=It;
		}
	return H;
}
Node_List *INPUT(Node_List *H,int n)
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
		p->Adr_ItAf=H;
		H=Add_Af(H,p);
	}
	return H;
}
void BRW(Node_List *H)
{
	Node_List *tmp=H;
	if(H==NULL)
		printf("\nDanh sach NULL\n");
	else
		do
		{
			printf("\n\n| %15s | %25s | %8s | %4.1f |" ,
			tmp->data.masv ,tmp->data.tensv ,tmp->data.lop ,tmp->data.dtb) ;
			tmp=tmp->Adr_ItAf;
		}
		while(tmp!=H);
}
Node_List *SEARCH(Node_List *H,char lp[])
{
	Node_List *tmp=H;
	do
	{
		if(strcmp(tmp->data.lop,lp)==0)
			return tmp;
		tmp=tmp->Adr_ItAf;
	}
	while(tmp!=H);
	return NULL;			
}
Node_List *DELETE(Node_List *H, char lp[])
{
	Node_List *It=SEARCH(H,lp);
	if(It ==NULL)
		return H;
	if(H->Adr_ItAf==H)
		return NULL;
	if(It ==H)
		{
			H=H->Adr_ItAf;
			It ->Adr_ItAf=NULL;
			Node_List *tmp=H;
			do
			{
				if(tmp->Adr_ItAf!=It )
					tmp=tmp->Adr_ItAf;
			}
			while(tmp->Adr_ItAf!=It );
			tmp->Adr_ItAf=H;
			return DELETE(H,lp);
		}
	Node_List *tmp=H;
	while(tmp->Adr_ItAf!=It )
		tmp=tmp->Adr_ItAf;
	tmp->Adr_ItAf=It ->Adr_ItAf;
	It ->Adr_ItAf=NULL;
	return DELETE(H,lp);
}
Node_List *DTB1(Node_List *H)
{
	if(H==NULL)
		return NULL;
	Node_List *Head=NULL,*tmp=H,*p;
	do
	{
		if(tmp->data.dtb<5)
			{
				Node_List *It=new Node_List;
				It->data=tmp->data;
				It->Adr_ItAf=Head;
				Head=Add_Af(Head,It);
				p=It;
			}
		tmp=tmp->Adr_ItAf;
	}
	while(tmp!=H);
	return Head;
}
Node_List *DTB2(Node_List *H)
{
	if(H==NULL)
		return NULL;
	Node_List *Head=NULL,*tmp=H;
	do
	{
		if(tmp->data.dtb>=5)
			{
				Node_List *It=new Node_List;
				It->data=tmp->data;
				It->Adr_ItAf=Head;
				Head=Add_Af(Head,It);
			}
		tmp=tmp->Adr_ItAf;
	}
	while(tmp!=H);
	return Head;
}
main()
{
	Node_List *Hd,*Hd1,*Hd2;
	int n;
	char l[10];
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	Hd= INPUT(NULL,n)	;
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






