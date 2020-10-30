#include<stdio.h>

struct Node_BnTr{
	int data;
	Node_BnTr *L, *R;
};
Node_BnTr *Add(Node_BnTr *Tr, Node_BnTr *node)
{
	Node_BnTr *tmp, *TMP;
	if(Tr==NULL)
		Tr=node;
	else
	{
		tmp=Tr;
		while(tmp!=NULL)
		{
			TMP=tmp;
			if(tmp->data>node->data)
				tmp=tmp->L;
			else
				tmp=tmp->R;
		}
		if(TMP->data>node->data)
			TMP->L=node;
		else
			TMP->R=node;		
	}
	return Tr;
}
Node_BnTr *INPUT(Node_BnTr *Tr, int n)
{
	Node_BnTr *p;
	for(int i=1;i<=n;i++)
	{
		p=new Node_BnTr;		
		printf("Nhap so thu %d: ",i);
		scanf("%d",&p->data);
		p->L=NULL;
		p->R=NULL;
		Tr=Add(Tr,p);
	}
	return Tr;
}
void BRW_GTP(Node_BnTr *Tr)
{
	if(Tr!=NULL)
	{
		printf("%d\t",Tr->data);
		BRW_GTP(Tr->L);		
		BRW_GTP(Tr->R);
	}
}
void BRW_TPG(Node_BnTr *Tr)
{
	if(Tr!=NULL)
	{		
		BRW_TPG(Tr->L);		
		BRW_TPG(Tr->R);
		printf("%d\t",Tr->data);
	}
}
int COUNT(Node_BnTr *Tr)
{
	if(Tr==NULL)
		return 0;
	else	
		return 1+COUNT(Tr->L)+COUNT(Tr->R);
	
}

int SEARCH(Node_BnTr *Tr, int t)
{
	if(Tr==NULL)
		return 0;
	if(Tr->data==t)
		return 1+SEARCH(Tr->R,t);
	else
		return SEARCH(Tr->R,t) + SEARCH(Tr->L,t);
	
}
main()
{
	Node_BnTr *Tree;
	int t;
	int spt;
	Tree=NULL;
	printf("Nhap bao nhieu so: \n");
	scanf("%d",&spt);
	Tree=INPUT(Tree,spt);
	printf("\nDanh sach vua nhap theo Goc Trai Phai: ");
	BRW_GTP(Tree);
	printf("\nDanh sach nhap theo Trai Phai Goc: ");
	BRW_TPG(Tree);
	printf("\n\nSo phan tu: %d",COUNT(Tree));
	printf("\n\nNhap so can tim: ");
	scanf("%d",&t);
	printf("\nCo: %d sinh vien can tim",SEARCH(Tree,t));	
}























