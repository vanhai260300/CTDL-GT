#include<stdio.h>
struct Node_BnTr
{
	int data;
	Node_BnTr *Adr_TrL,*Adr_TrR;
};
Node_BnTr *Add_Node(Node_BnTr *Tr,Node_BnTr *node)
{
	Node_BnTr *tmp,*TMP;
	if(Tr==NULL)
	{
		Tr=node;
	}
	else
	{
		tmp=Tr;
		while(tmp!=NULL)
		{
			TMP=tmp;
			if(tmp->data>node->data)
				tmp=tmp->Adr_TrL;
			else
				tmp=tmp->Adr_TrR;
		}
		 if(TMP->data>node->data)
		 	TMP->Adr_TrL=node;
		else
			TMP->Adr_TrR=node;
	}
	return Tr;
}
Node_BnTr *INPUT(Node_BnTr *Tr, int n)
{
	Node_BnTr *p;
	Tr=NULL;
	for(int i=1;i<=n;i++)
	{
		p=new Node_BnTr;
		printf("Nhap so thu %d: ",i);
		scanf("%d",&p->data);
		p->Adr_TrL=NULL;
		p->Adr_TrR=NULL;
		Tr=Add_Node(Tr,p);
		
	}
	return Tr;
}
void BRW_TGP(Node_BnTr *Tr)
{
	if(Tr!=NULL)
	{
		BRW_TGP(Tr->Adr_TrL);
		printf("%d\t",Tr->data);
		BRW_TGP(Tr->Adr_TrR);
	}
}
main()
{
	Node_BnTr *Tree;
	int n;
	printf("Nhap bao nhieu so: ");
	scanf("%d",&n);
	Tree=INPUT(Tree,n);
	BRW_TGP(Tree);
}
