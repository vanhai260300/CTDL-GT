#include<stdio.h>
#include<string.h>
struct Node_list
{
	char masv[15],tensv[50],lop[5];
	float dtb;
	Node_list *Adr_ItAf;
};
Node_list *Add_Af(Node_list *H, Node_list *It)
{
	if(H==NULL)
		H=It;
	else
	{
		Node_list *tmp;
		tmp=H;
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=It;
	}
	return H;
}
void Input(Node_list **H)
{
	Node_list *p;
	int *n;
	*H =NULL;
	printf("Nhap so sinh vien: ");
	scanf("%d",&*n);
	for(int i=1;i<=*n;++i)
	{
		p= new Node_list;
		fflush(stdin);
		printf("Nhap ma sv thu %d: ",i);
		gets(p->masv);
		printf("Nhap ho va ten: ");
		gets(p->tensv);
		printf("Nhap lop: ");
		gets(p->lop);
		printf("DTB: ");
		scanf("%f",&p->dtb);
		p->Adr_ItAf=NULL;
		*H=Add_Af(*H,p);
	}
}
void BRW_IT(Node_list *H)
{
	Node_list *tmp;
	if(H==NULL)
	{
		printf("Danh sach null");
	}
	else
	{
		tmp=H;
		while(tmp!=NULL)
		{
			printf("%20s || %20s || %6s || %3f\n",tmp->masv,tmp->tensv,tmp->lop,tmp->dtb);
			tmp=tmp->Adr_ItAf;
		}
	}
}
Node_list *Search(Node_list *H, char m[])
{
	Node_list *tmp;
	tmp=H;
	while (tmp!=NULL)
	{
		if (strcmpi(tmp->lop,m)==0)
			return tmp;
		tmp=tmp->Adr_ItAf;
	}
	return NULL;
}
Node_list *Delete(Node_list *H, char m[])
{
	Node_list *tmp, *p;
	p=Search(H,m);
	while(p!=NULL)
	{
		if (H==p)
		{
			H=H->Adr_ItAf;
			p->Adr_ItAf=NULL;
		}
		else
		{
			tmp=H;
			while (tmp->Adr_ItAf!=p)
				tmp=tmp->Adr_ItAf;
			tmp->Adr_ItAf=p->Adr_ItAf;
			p->Adr_ItAf=NULL;
		}
		p=Search(H,m);
	}
	return H;
}
main()
{
	Node_list *hd;
	char l[10];
	Input(&hd);
	BRW_IT(hd);
	printf("Nhap Lop can xoa: ");
	fflush(stdin);
	gets(l);
	hd=Delete(hd,l);
	BRW_IT(hd);
}

