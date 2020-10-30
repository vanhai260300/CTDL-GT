#include<stdio.h>
struct Node_List
{
	int data1,data2;
	Node_List *Adr_ItAf;
};
Node_List *Add_Af(Node_List *H, Node_List *It)
{
	if(H==NULL)
		H=It;
	else
	{
		Node_List *tmp;
		tmp=H;
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=It;
	}
	return H;
}
void INPUT(Node_List **H)
{
	Node_List *p;
	int n;
	*H =NULL;
	printf("Nhap Bao nhieu phan tu: ");
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		p= new Node_List;
		printf("Nhap co so cua phan tu %d: " ,i);
		scanf("%d" ,&p->data1);
		printf("Nhap so mu cua phan tu %d:" ,i);
		scanf("%d" ,&p->data2);
		printf("\n");
		p->Adr_ItAf=NULL;
		*H=Add_Af(*H,p);
	}
}
void BRW(Node_List *H)
{
	Node_List *tg;
	if(H==NULL)
	{
		printf("Danh sach null");
	}
	else
	{
		tg=H;
		while(tg!=NULL)
		{
			printf("%dX^%d + ",tg->data1,tg->data2);
			tg=tg->Adr_ItAf;
		}
	}
}
main()
{
	Node_List *Hd;
	INPUT(&Hd);
	BRW(Hd);
	printf("0");
}

