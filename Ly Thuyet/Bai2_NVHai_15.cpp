#include <stdio.h>
struct Node_List
{
	int SMu, CSo;
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
main()
{
	int n;
	Node_List *Hd,*p,*tg;
	Hd=NULL;
	printf("Nhap so phan tu: ");
	scanf("%d" ,&n);
	for(int i=1;i<=n;++i)
	{
		p= new Node_List;
		printf("Nhap co so cua phan tu %d: " ,i);
		scanf("%d" ,&p->CSo);
		printf("Nhap so mu cua phan tu %d:" ,i);
		scanf("%d" ,&p->SMu);
		printf("\n");
		p->Adr_ItAf=NULL;
		Hd=Add_Af(Hd,p);
	}
	tg=Hd;
	while(tg!=NULL)
	{
		if(tg->CSo%2==0)
			printf(" %dX^%d + " ,tg->CSo ,tg->SMu);
		tg=tg->Adr_ItAf;
	}	
	printf("0");
}
