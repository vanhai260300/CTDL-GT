#include<stdio.h>
struct Node_BnTr{
	int Data_15;
	Node_BnTr *AdrL_15, *AdrR_15;
};
Node_BnTr *Add_Node(Node_BnTr *Tr_15, Node_BnTr *node_15)
{
	Node_BnTr *tmp_15, *TMP_15;
	if(Tr_15==NULL)
		Tr_15=node_15;
	else
	{
		tmp_15= Tr_15;
		while(tmp_15!=NULL)
		{
			TMP_15= tmp_15;
			if(tmp_15->Data_15>node_15->Data_15)
				tmp_15=tmp_15->AdrL_15;
			else
				tmp_15=tmp_15->AdrR_15;
		}
		if(TMP_15->Data_15>node_15->Data_15)
			TMP_15->AdrL_15=node_15;
		else
			TMP_15->AdrR_15=node_15;
	}
	return Tr_15;
}
void NHAP(Node_BnTr *&Tr_15)
{
	Tr_15=NULL;
	int n;
	printf("Nhap bao nhieu so: ");
	scanf("%d", &n);
	for(int i=1; i<=n; i++)
	{
		Node_BnTr *p= new Node_BnTr;
		printf("Nhap so thu %d: ", i);
		fflush(stdin);
		scanf("%d",&p->Data_15);
		p->AdrL_15=NULL;
		p->AdrR_15=NULL;
		Tr_15=Add_Node(Tr_15,p);
	}
}
void In(Node_BnTr *Tr_15)
{
	if(Tr_15!=NULL)
	{
		In(Tr_15->AdrL_15);
		printf(" %d ",Tr_15->Data_15);
		In(Tr_15->AdrR_15);
	}
}
Node_BnTr *SEARCH(Node_BnTr *Tr_15, int info_15)
{
	Node_BnTr *tmp_15;
	if(Tr_15==NULL)
		return NULL;
	else
	{
		tmp_15=Tr_15;
		while(tmp_15!=NULL && tmp_15->Data_15!= info_15)
			if(tmp_15->Data_15>info_15)
				tmp_15=tmp_15->AdrL_15;
			else
				tmp_15=tmp_15->AdrR_15;
		if(tmp_15!=NULL)
			return tmp_15;
		else
			return NULL;
	}
}
Node_BnTr *XGoc(Node_BnTr *Tr_15, int info_15)
{
	Node_BnTr *tmp_15, *R;
	while(SEARCH(Tr_15,info_15)!=NULL)
	{
		tmp_15=SEARCH(Tr_15,info_15);
		if(tmp_15==Tr_15)
		{
			if(tmp_15->AdrL_15!=NULL)
			{
				R=Tr_15->AdrR_15;
				Tr_15=Tr_15->AdrL_15;
				
				tmp_15->AdrL_15=NULL;
				tmp_15->AdrR_15=NULL;
				tmp_15=Tr_15;
				
				while(tmp_15->AdrR_15!=NULL)
					tmp_15=tmp_15->AdrR_15;
				tmp_15->AdrR_15=R;
			}
			else
			{
				Tr_15=Tr_15->AdrR_15;
				tmp_15->AdrR_15=NULL;
			}
		}
	}
	return Tr_15;
}
Node_BnTr *XLa(Node_BnTr *Tr_15, int info_15)
{
	Node_BnTr *tmp_15, *t;
	while(SEARCH(Tr_15,info_15)!=NULL)
	{
		tmp_15=SEARCH(Tr_15,info_15);
		if(tmp_15!=Tr_15)
		{
			t=Tr_15;
			while(t->AdrL_15!=tmp_15 && t->AdrR_15!=tmp_15)
			{
				if(t->Data_15>info_15)
					t=t->AdrL_15;
				else
					t=t->AdrR_15;
			}
			if(tmp_15->AdrL_15==NULL && tmp_15->AdrR_15==NULL)
				if(t->AdrR_15==tmp_15)
					t->AdrR_15=NULL;
				else
					t->AdrL_15=NULL;
		}
	}
	return Tr_15;
}
Node_BnTr *XKoT(Node_BnTr *Tr_15, int info_15)
{
	Node_BnTr *tmp_15, *t, *R;
	while(SEARCH(Tr_15,info_15)!=NULL)
	{
		tmp_15=SEARCH(Tr_15,info_15);
		if(tmp_15!=Tr_15)
		{
			t=Tr_15;
			while(t->AdrL_15!=tmp_15 && t->AdrR_15!=tmp_15)
			{
				if(t->Data_15>info_15)
					t=t->AdrL_15;
				else
					t=t->AdrR_15;
			}
			if(tmp_15->AdrL_15==NULL)
			{
				R=tmp_15->AdrR_15;
				if(t->AdrL_15==tmp_15)
					t->AdrL_15=R;
				else
					t->AdrR_15=R;
				tmp_15->AdrR_15=NULL;
			}	
		}
	}
	return Tr_15;
}
Node_BnTr *XKoP(Node_BnTr *Tr_15, int info_15)
{
	Node_BnTr *tmp_15, *t, *L;
	while(SEARCH(Tr_15,info_15)!=NULL)
	{
		tmp_15=SEARCH(Tr_15,info_15);
		if(tmp_15!=Tr_15)
		{
			t=Tr_15;
			while(t->AdrL_15!=tmp_15 && t->AdrR_15!=tmp_15)
			{
				if(t->Data_15>info_15)
					t=t->AdrL_15;
				else
					t=t->AdrR_15;
			}
			if(tmp_15->AdrR_15==NULL)
			{
				L=tmp_15->AdrL_15;
				if(t->AdrL_15==tmp_15)
					t->AdrL_15=L;
				else
					t->AdrR_15=L;
				tmp_15->AdrL_15=NULL;
			}
		}
	}
	return Tr_15;
}
Node_BnTr *XCoTP(Node_BnTr *Tr_15, int info_15)
{
	Node_BnTr *tmp_15, *t;
	while(SEARCH(Tr_15,info_15)!=NULL)
	{
		tmp_15=SEARCH(Tr_15,info_15);
		if(tmp_15!=Tr_15)
		{
			t=Tr_15;
			while(t->AdrL_15!=tmp_15 && t->AdrR_15!=tmp_15)
			{
				if(t->Data_15>info_15 )
					t=t->AdrL_15;
				else
					t=t->AdrR_15;
			}
			if(t->AdrL_15==tmp_15)
			{
				t->AdrL_15=tmp_15->AdrL_15;
				t=t->AdrL_15;
			}
			else
			{
				t->AdrR_15=tmp_15->AdrL_15;
				t=t->AdrR_15;
			}
			while(t->AdrR_15!=NULL)
				t=t->AdrR_15;
			t->AdrR_15=tmp_15->AdrR_15;
			tmp_15->AdrR_15=NULL;
			tmp_15->AdrL_15=NULL;	
		}
	}
	return Tr_15;
}
main()
{
	Node_BnTr *Tree_15;
	NHAP(Tree_15);
	In(Tree_15);
	printf("\n 1. Xoa nut goc.");
	printf("\n 2. Xoa nut la.");
	printf("\n 3. Xoa nut ko co cay con trai.");
	printf("\n 4. Xoa nut ko co cay con phai.");
	printf("\n 5. Xoa nut co du 2 cay con.");
	printf("\n 6. Hoan Tat...");
	int num_15;
	while(true)
	{
		printf("\n Nhap so de chom ham: ");
		scanf("%d", &num_15);
		switch(num_15)
		{
			case 1:{
				int so;
				printf(" => Nhap nut goc can xoa: ");
				scanf("%d", &so);
				Tree_15=XGoc(Tree_15,so);
				In(Tree_15);
			};break;
			case 2:{
				int so1;
				printf(" => Nhap nut la can xoa: ");
				scanf("%d",&so1);
				Tree_15=XLa(Tree_15,so1);
				In(Tree_15);
			};break;
			case 3:{
				int so2;
				printf(" => Nhap nut khong co cay con ben trai can xoa: ");
				scanf("%d",&so2);
				Tree_15=XKoT(Tree_15,so2);
				In(Tree_15);
			} break;
			case 4: {
				int so3;
				printf(" => Nhap nut khong co cay con ben phai can xoa: ");
				scanf("%d",&so3);
				Tree_15=XKoP(Tree_15,so3);
				In(Tree_15);
				
			}break;
			case 5:{
				int so4;
				printf(" => Nhap nut co du 2 cay con de xoa: ");
				scanf("%d",&so4);
				Tree_15=XCoTP(Tree_15,so4);
				In(Tree_15);
			}break;
			case 6: return 0;
		}
	}
}















