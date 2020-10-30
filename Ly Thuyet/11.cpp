#include<stdio.h>
struct Node_List{
	int data;
	Node_List *Adr_ItAf;
};
Node_List *Add_Af(Node_List *H, Node_List*It)
{
	Node_List *tmp;
	if(H==NULL)
		H=It;
	else
	{
		while(tmp->Adr_ItAf!=NULL)
			tmp=tmp->Adr_ItAf;
		tmp->Adr_ItAf=It;
	}
	return H;
}
void INPUT(Node_List **H)
{
	Node_List *p;
	H==NULL;
	do
	{
		p=new Node_List;
		printf("Nhap so: ");
		scanf("%d",&p->data);
		p->Adr_ItAf==NULL;
		*H=Add_Af(*H,p);

	}	while(p->data!=0);
}
void BRW(Node_List *H)
{
	Node_List *pt;
	if(H==NULL)
		printf("Danh sach Null");
	else
	{
		pt=H;
		while(pt->data!=0)
		{
			printf("%d ",pt->data);
			pt=pt->Adr_ItAf;
		}
	}
}
main()
{
}
