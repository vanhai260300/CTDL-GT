#include<stdio.h>
#include<string.h>
struct Node_BnTr_15{
	char ten_15[30];
	Node_BnTr_15 *Adr_TrL_15, *Adr_TrR_15;
};
Node_BnTr_15 *Add_Node_15(Node_BnTr_15 *Tr_15, Node_BnTr_15 *node_15)
{
	Node_BnTr_15 *tmp_15, *TMP_15;
	if(Tr_15==NULL)
		Tr_15=node_15;
	else
	{
		tmp_15=Tr_15;
		while(tmp_15!=NULL)
		{
			TMP_15=tmp_15;
			if(strcmp(tmp_15->ten_15,node_15->ten_15)>0)
				tmp_15=tmp_15->Adr_TrL_15;
			else
				tmp_15=tmp_15->Adr_TrR_15;		
		}
		if(strcmp(TMP_15->ten_15,node_15->ten_15)>0)
			TMP_15->Adr_TrL_15=node_15;
		else
			TMP_15->Adr_TrR_15=node_15;
	}
	return Tr_15;
}
Node_BnTr_15 *INPUT_15(Node_BnTr_15 *Tr_15, int n_15)
{
	Node_BnTr_15 *p_15;
	for(int i=1;i<=n_15;i++)
	{
		p_15=new Node_BnTr_15;		
		printf("Nhap ten sinh vien thu %d: ",i);
		fflush(stdin);
		gets(p_15->ten_15);
		p_15->Adr_TrL_15=NULL;
		p_15->Adr_TrR_15=NULL;
		Tr_15=Add_Node_15(Tr_15,p_15);
	}
	return Tr_15;
}
void BRW_Node_GTP_15(Node_BnTr_15 *Tr_15)
{
	if(Tr_15!=NULL)
	{
		printf("%s\t",Tr_15->ten_15);
		BRW_Node_GTP_15(Tr_15->Adr_TrL_15);		
		BRW_Node_GTP_15(Tr_15->Adr_TrR_15);
	}
}
void BRW_Node_TPG_15(Node_BnTr_15 *Tr_15)
{
	if(Tr_15!=NULL)
	{		
		BRW_Node_TPG_15(Tr_15->Adr_TrL_15);		
		BRW_Node_TPG_15(Tr_15->Adr_TrR_15);
		printf("%s\t",Tr_15->ten_15);
	}
}
int COUNT_15(Node_BnTr_15 *Tr_15)
{
	if(Tr_15==NULL)
		return 0;
	else	
		return 1+COUNT_15(Tr_15->Adr_TrL_15)+COUNT_15(Tr_15->Adr_TrR_15);
	
}

int SEARCH_15(Node_BnTr_15 *Tr_15, char t_15[])
{
	if(Tr_15==NULL)
		return 0;
	if(strcmp(Tr_15->ten_15,t_15)==0)
		return 1+SEARCH_15(Tr_15->Adr_TrR_15,t_15);
	else
		return SEARCH_15(Tr_15->Adr_TrR_15,t_15) + SEARCH_15(Tr_15->Adr_TrL_15,t_15);
	
}
main()
{
	Node_BnTr_15 *Tree_15;
	char T_15[10];
	int spt_15;
	Tree_15=NULL;
	printf("Nhap so sinh vien: \n");
	scanf("%d",&spt_15);
	Tree_15=INPUT_15(Tree_15,spt_15);
	printf("\nDanh sach vua nhap theo Goc Trai Phai: ");
	BRW_Node_GTP_15(Tree_15);
	printf("\nDanh sach nhap theo Trai Phai Goc: ");
	BRW_Node_TPG_15(Tree_15);
	printf("\n\nSo sinh vien: %d",COUNT_15(Tree_15));
	printf("\n\nNhap ten sinh vien can tim: ");
	fflush(stdin);
	gets(T_15);
	printf("\nCo: %d sinh vien can tim",SEARCH_15(Tree_15,T_15));	
}























