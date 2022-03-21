//创建空链表（单链表的初始化） 
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
//单链表的销毁
Status DestroyList_L(LinkList &L){
	Londe *p;
	while(L){
		p=L;
		L=L->next;
		delete p;
	}
}
//清空单链表(成为空表，有头指针和头节点）
Status ClearList(LinkList &L){      //将L重置为空表 
	Londe *p,*q;                    //或LinkList p.q; 
	p=L->next;
	while(p){                       //没到表尾 
	q=p->datanext;
	delete p;
	p=q;
	}
	L->next=NULL;                   //头结点指针域为空 
	return OK;
}
//求单链表的表长
int ListLength_L(LinkList L){        //返回L中数据元素个数 
	LinkList p;
	p=L->next;                        //p指向第一个结点 
	i=0;
	while(p){
	i++;
	p=p->next;                          //遍历单链表，统计结点数 	
	}
	return i;
} 
//取第i个元素
Status GetElem_L(LinkList L,int i,ElemType &e){  //获取线性表L中的某个数据元素的内容，
                                                //通过变量e返回 
	p=L->next;j=1;              //初始化 
	while(p&&j<i){               //向后扫描，直到p指向第i个元素或p为空 
		p=p->next;++j;
	}
	if(!p||j>i) return ERROR;     //第i个元素不存在 
	e=p->data;                    //取第i个元素 
	return OK;
} 
//单链表的按值查找--找地址
Londe *LocateELem_L(LinkList L,Elemtype e){
	//在线性表L中查找值为e的数据元素
	//找到，则返回L中值为e的数据元素的地址，查找失败返回NULL
	p=L->next;
	while(p&&p->data!=e)
	p=p->next;
	return p; 
} 
//单链表按值查找--找位置序号
int LocateElem_L (LinkList L,Elemtype e){  //找元素e的序号 
	p=L->next;j=1;                         //返回e的位置序号，查找失败返回0 
	while(p&&p->data!=e)
	{p=p->next;j++;}
	if(p) return j;
	else return 0;
	}
}
//插入结点
//在L中第i个元素之前插入数据元素e
Status Listinsert_L(LinkList&L,int i,ElemType e){
	p=L;j=0;                             //p先等于头结点 
	while (p&&j<i-1){
		p=p->next;++j;                  //寻找第i-1个结点，p指向i-1结点 
	}
	if(!p||j>i-1) return ERROR;          //i大于表长+1或者小于1，插入位置非法 
	s=new LNode; s->data=e;              //生成新结点s，将结点s的数据域置为e 
	s->next=p->next;                    //将结点s插入L中 
	p->next=s;
	return OK;
} 
//删除结点
//将表中第i个数据元素删除
Status ListDelete_L(LinkList &L,int i,ElemType &e){
	p=L;j=0;
	whlie(p->next&&j<i-1){p=p->next;++j;}
	                                      //寻找第i-1个结点，并令p指向其前驱 
	if(!(p->next)||j>i-1) return ERROR;   //删除位置不合理 
	q=p->next;                            //临时保存被删结点的地址以备释放 
	p->next=q->next;                      //改变删除结点前驱结点的指针域 
	e=q->data;                            //保存删除结点的数据域 
	delete q;                             //释放删除结点的空间 
	return OK； 
} 
//头插法建立链表
void CreatList_H(LinkList &L,int n){
	L=new LNode;
	L->next=NULL;           //先建立一个带头结点的单链表 
	for (i=n;i>0;--i){
		p=new LNode;         //生成新结点 p=(LNode*)malloc(sizeof(LNode)); 
		cin>>p->data;        //输入元素值scanf(&p->data); 
		p->next=L->next;     //插入到表头 
		L->next=p;
	}
} 
//尾插法建立链表 （正序）
void CreateList_R (LinkList &L,int n) {
	L=new LNode; 
	L->next=NULL;
	r=L;                   //尾指针r指向头结点 
	for(i=0;i<n;++i){
		p=new LNode;
		cin>>p->data;      //生成新结点，输入元素值 
		p->next=NULL;
		r->next=p;        //插入到表尾 
		r=p;              //r指向新的尾结点 
	}
}
 

 

	
 
 
 
 

