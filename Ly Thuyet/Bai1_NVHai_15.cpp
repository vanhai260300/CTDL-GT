#include <stdio.h>
struct Node_List
{
	int data;
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
	*H =NULL;
	do
	{
		p= new Node_List;
		printf("Nhap so: ");
		scanf("%d",&p->data);
		p->Adr_ItAf=NULL;
		*H=Add_Af(*H,p);
	}
	while (p->data!=0);
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
		while (tg->data!=0)
		{
		printf("%d	" ,tg->data);
		tg=tg->Adr_ItAf;	
		}	
	}
}
main()
{
	Node_List *Hd;
	INPUT(&Hd);
	BRW(Hd);
}









