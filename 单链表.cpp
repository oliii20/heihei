//����������������ĳ�ʼ���� 
#include<stdio.h>
#include<stdlib.h>
typedef struct Londe{
	ElemType data;
	struct Londe *next;
}Londe,*LinkList;
Status InitList_L(LinkList &L){
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	return OK;
}
//�����������
Status DestroyList_L(LinkList &L){
	Londe *p;
	while(L){
		p=L;
		L=L->next;
		delete p;
	}
}
//��յ�����(��Ϊ�ձ���ͷָ���ͷ�ڵ㣩
Status ClearList(LinkList &L){      //��L����Ϊ�ձ� 
	Londe *p,*q;                    //��LinkList p.q; 
	p=L->next;
	while(p){                       //û����β 
	q=p->datanext;
	delete p;
	p=q;
	}
	L->next=NULL;                   //ͷ���ָ����Ϊ�� 
	return OK;
}
//������ı�
int ListLength_L(LinkList L){        //����L������Ԫ�ظ��� 
	LinkList p;
	p=L->next;                        //pָ���һ����� 
	i=0;
	while(p){
	i++;
	p=p->next;                          //����������ͳ�ƽ���� 	
	}
	return i;
} 
//ȡ��i��Ԫ��
Status GetElem_L(LinkList L,int i,ElemType &e){  //��ȡ���Ա�L�е�ĳ������Ԫ�ص����ݣ�
                                                //ͨ������e���� 
	p=L->next;j=1;              //��ʼ�� 
	while(p&&j<i){               //���ɨ�裬ֱ��pָ���i��Ԫ�ػ�pΪ�� 
		p=p->next;++j;
	}
	if(!p||j>i) return ERROR;     //��i��Ԫ�ز����� 
	e=p->data;                    //ȡ��i��Ԫ�� 
	return OK;
} 
//������İ�ֵ����--�ҵ�ַ
Londe *LocateELem_L(LinkList L,Elemtype e){
	//�����Ա�L�в���ֵΪe������Ԫ��
	//�ҵ����򷵻�L��ֵΪe������Ԫ�صĵ�ַ������ʧ�ܷ���NULL
	p=L->next;
	while(p&&p->data!=e)
	p=p->next;
	return p; 
} 
//������ֵ����--��λ�����
int LocateElem_L (LinkList L,Elemtype e){  //��Ԫ��e����� 
	p=L->next;j=1;                         //����e��λ����ţ�����ʧ�ܷ���0 
	while(p&&p->data!=e)
	{p=p->next;j++;}
	if(p) return j;
	else return 0;
	}
}
//������
//��L�е�i��Ԫ��֮ǰ��������Ԫ��e
Status Listinsert_L(LinkList&L,int i,ElemType e){
	p=L;j=0;                             //p�ȵ���ͷ��� 
	while (p&&j<i-1){
		p=p->next;++j;                  //Ѱ�ҵ�i-1����㣬pָ��i-1��� 
	}
	if(!p||j>i-1) return ERROR;          //i���ڱ�+1����С��1������λ�÷Ƿ� 
	s=new LNode; s->data=e;              //�����½��s�������s����������Ϊe 
	s->next=p->next;                    //�����s����L�� 
	p->next=s;
	return OK;
} 
//ɾ�����
//�����е�i������Ԫ��ɾ��
Status ListDelete_L(LinkList &L,int i,ElemType &e){
	p=L;j=0;
	whlie(p->next&&j<i-1){p=p->next;++j;}
	                                      //Ѱ�ҵ�i-1����㣬����pָ����ǰ�� 
	if(!(p->next)||j>i-1) return ERROR;   //ɾ��λ�ò����� 
	q=p->next;                            //��ʱ���汻ɾ���ĵ�ַ�Ա��ͷ� 
	p->next=q->next;                      //�ı�ɾ�����ǰ������ָ���� 
	e=q->data;                            //����ɾ������������ 
	delete q;                             //�ͷ�ɾ�����Ŀռ� 
	return OK�� 
} 
//ͷ�巨��������
void CreatList_H(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;           //�Ƚ���һ����ͷ���ĵ����� 
	for (i=n;i>0;--i){
		p=new LNode;         //�����½�� p=(LNode*)malloc(sizeof(LNode)); 
		cin>>p->data;        //����Ԫ��ֵscanf(&p->data); 
		p->next=L->next;     //���뵽��ͷ 
		L->next=p;
	}
} 
//β�巨�������� ������
void CreateList_R (LinkList &L,int n) {
	L=new LNode; 
	L->next=NULL;
	r=L;                   //βָ��rָ��ͷ��� 
	for(i=0;i<n;++i){
		p=new LNode;
		cin>>p->data;      //�����½�㣬����Ԫ��ֵ 
		p->next=NULL;
		r->next=p;        //���뵽��β 
		r=p;              //rָ���µ�β��� 
	}
}
 

 

	
 
 
 
 

