#include<stdio.h>
struct Node_List
{
	float data;
	Node_List *Adr_ItAf;
};
Node_List *Add_Af(Node_List *H, Node_List *it)
{
	if(H==NULL)
		H=it;
	else
	{
		Node_List *tmp;
		tmp=H;
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=it;
	}
	return H;
}
void INPUT(Node_List *H,int n)
{
	Node_List *p;
	H==NULL;
	for(int i=1;i<=n;i++)
	{
		p=new Node_List;
		printf("Nhap phan tu thu %d: ",i);
		scanf("%f",&p->data);
		p->Adr_ItAf=NULL;
		H=Add_Af(H,p);
	}
}
void XUAT(Node_List *H)
{
	Node_List *tmp;
	if(H==NULL)
		printf("Danh sach NULL");
	else
	{
		tmp=H;
		while(tmp!=NULL)
		{
			printf("%f\t",tmp->data);
			tmp=tmp->Adr_ItAf;
		}
	}
}
main()
{
	int n;
	Node_List *Hd;
	printf("Nhap so Phan tu: ");
	scanf("%d",&n);
	INPUT(Hd,n);
	XUAT(Hd);
}

