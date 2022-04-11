#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;		    //���������������ͣ���ʾ�������״̬ 
typedef char TElemType;		//�������������Ԫ������Ϊ�ַ�
 
 
//��������ʽ
typedef struct BiTNode 
{
	TElemType data;
	BiTNode* lchild, * rchild;
} BiTNode, * BiTree;
 
//��������
typedef struct TriTNode 
{
	int mark;
	TElemType data;
	TriTNode* parent, * lchild, * rchild;
}TriTNode, * TriTree;
 
 
//����ջ
typedef struct BSNode
{
	BiTree data;
	struct BSNode* next;
}BSNode, *BStack;
//��ʼ��ջ
void InitStack(BStack& s)
{
	s = NULL;
}
//Ԫ����ջ
Status Push_BS(BStack& s, BiTree e)
{
	BSNode* p;
	p = (BSNode*)malloc(sizeof(BSNode));
	if (p == NULL)return OVERFLOW;
	p->data = e;
	p->next = s;
	s = p;
	return OK;
}
//��ջ
Status Pop_Bs(BStack& s, BiTree& e)
{
	BSNode* p;
	if (s == NULL)return ERROR;
	p = s;
	e = s->data;
	s = s->next;
	free(p);
	return OK;
}
//�ж�ջ��
Status StackEmpty_BS(BStack s)
{
	if (s == NULL)return TRUE;
	else return FALSE;
}
 
 
 
//����1�����ʽ���ֵ
Status visit(TElemType e)
{
	if (e)
	{
		printf("%c", e);
		return OK;
	}
	else return ERROR;
}
//����2�����������Զ�����T�������ʱ��k�����ʵ��Ľ���ֵ
TElemType visitsPreOrderK(BiTree T, Status& i, Status k)
{
	TElemType p = '#';
	if (T == NULL)return '#';
	if (i == k)return T->data;
	i++;
	if (T->lchild)
		p = visitsPreOrderK(T->lchild, i, k);
	if (T->rchild && p == '#')
		p = visitsPreOrderK(T->rchild, i, k);
	return p;
}
//����3��������ֵΪx�Ľ��Ϊ�����������
Status depth(BiTree T)
{
	int depl, depr;
	if (T == NULL)return 0;
	else
	{
		depl = depth(T->lchild);
		depr = depth(T->rchild);
		return 1 + (depl > depr ? depl : depr);
	}
}
 
//����������
TriTree CreateTriTree(TElemType* tree, Status& i)
{
	TriTree T;
	TElemType node = tree[i++];
	if (node=='#')
	{
		T = NULL; //T�ǿ���
	}
	else 
	{
		T = (TriTree)malloc(sizeof(TriTNode));
		if (T == NULL)
			return NULL;
		T->data = node;
		T->mark = 0;
		T->parent = NULL;
		T->lchild = CreateTriTree(tree, i); //����������
		if (T->lchild != NULL)
		{
			T->lchild->parent = T;
		}   //������������ڣ�����˫��ֵ
		T->rchild = CreateTriTree(tree, i); //����������
		if (T->rchild != NULL)
		{
			T->rchild->parent = T;      //������������ڣ�����˫��ֵ
		}
	}
	return T;
}
 
//��������������ʼ��
Status InitBiTree(BiTree& T) 
{
	T = NULL;
	return OK;
}
 
//����һ�ö�����T�����и�����ֵΪe��L��R�ֱ�Ϊ��������������
BiTree MakeBiTree(TElemType e, BiTree L, BiTree R)
{
	BiTree T;
	T = (BiTNode*)malloc(sizeof(BiTNode));
	if (T==NULL) 
	{
		return NULL;
	}
	T->data = e;
	T->lchild = L;
	T->rchild = R;
	return T;
}
 
//�����������
BiTree CreateBiTree(TElemType* T, Status& i, Status&tag)
{
	BiTree temp;
	TElemType ch;
	int len;
	len = strlen(T);
	ch = T[i++];
	if (i>len)
	{
		tag = 0;
		printf("��%d�������������򲻴��ڣ�����������\n",i);
		temp = NULL;
		return ERROR;
	}
	else if ('#' == ch)InitBiTree(temp);//��������
	else
	{
		temp = MakeBiTree(ch, NULL, NULL);
		temp->lchild = CreateBiTree(T, i,tag);
		temp->rchild = CreateBiTree(T, i,tag);
	}
	return temp;
}
 
//���������������ʹ��ջ�ķǵݹ飩
Status PreOrderTraverse(BiTree T, Status(*visit)(TElemType e))
{
	BStack s;
	InitStack(s);
	BiTree p = T;
	while (p != NULL || !StackEmpty_BS(s))
	{
		if (p != NULL)
		{
			visit(p->data);
			Push_BS(s, p);
			p = p->lchild;
		}
		else
		{
			Pop_Bs(s, p);
			p = p->rchild;
		}
	}
	return OK;
}
 
//����������������ݹ飩
void InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);       //ǰ�����������
		printf("%c", T->data);              //���ʸ����
		InOrderTraverse(T->rchild);       //ǰ�����������
	}
}
 
//�������������(������)
void PostOrder(TriTree bt, Status(*visit)(TElemType e))
{
	TriTree p = bt;
	// visit(p->data);
	while (p) {
		while (p->mark == 0) {  //�ȱ�������
			p->mark = 1;
			if (p->lchild)
				p = p->lchild;
		}
		while (p->mark == 1) {  //�ٱ����Һ���
			p->mark = 2;
			if (p->rchild)
				p = p->rchild;
		}
		if (p->mark == 2) {
			visit(p->data);
			p = p->parent;
		}
	}
}
 
//���ٶ�����
void DestroyBiTree(BiTree& T)
{
	if (T == NULL)return;
	else
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);
		free(T);
		T = NULL;
	}
}
 
 
//�Զ������пգ����򷵻�TURE�����򷵻�FALSE
Status BiTreeEmpty(BiTree T)
{
	if (T == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
 
//��һ�ö������ֽ�Ϊ��������������������������
Status BreakBiTree(BiTree& T)
{
	BiTree L, R;
	if (T == NULL)return ERROR;
	else
	{
		L = T->lchild;
		R = T->rchild;
		T->lchild = NULL;
		T->rchild = NULL;
		printf("�����Ϊ�����򣩣�");
		PreOrderTraverse(T,visit);
		printf("\n");
		printf("������Ϊ�����򣩣�");
		PreOrderTraverse(L, visit);
		printf("\n");
		printf("������Ϊ�����򣩣�");
		PreOrderTraverse(R, visit);
		printf("\n");
		return OK;
	}
}
 
//����������
Status Breakleft(BiTree& T)
{
	BiTree l;
	if (T == NULL)return ERROR;
	l = T->lchild;
	T->lchild=NULL;
	printf("�������������Ϊ(����)��");
	PreOrderTraverse(l, visit);
	printf("\n");
	printf("������ԭ��Ϊ(����):");
	PreOrderTraverse(T, visit);
	return OK;
}
 
//����������
Status Breakright(BiTree& T)
{
	BiTree r;
	if (T == NULL)return ERROR;
	r = T->rchild;
	T->rchild = NULL;
	printf("�������������Ϊ(����)��");
	PreOrderTraverse(r, visit);
	printf("\n");
	printf("������ԭ��Ϊ(����):");
	PreOrderTraverse(T, visit);
	return OK;
}
 
//�滻����������T�ǿգ�����LT�滻T��������������LT����T��ԭ��������
Status ReplaceLeft(BiTree& T, BiTree& LT)
{
	BiTree temp;
	if (T == NULL)return ERROR;
	temp = T->lchild;
	T->lchild = LT;
	LT = temp;
	return OK;
}
 
//�滻����������T�ǿգ�����RT�滻T��������������RT����T��ԭ��������
Status ReplaceRight(BiTree& T, BiTree& RT)
{
	BiTree temp;
	if (T == NULL)return ERROR;
	temp = T->rchild;
	T->rchild = RT;
	RT = temp;
	return OK;
}
 
 
//�ݹ��㷨����Զ�����T�������ʱ��k�����ʵ��Ľ���ֵ
TElemType PreOrderK(BiTree T, Status k)
{
	int x = 1;
	return visitsPreOrderK(T, x, k);
}
 
//���������Ҷ����
Status Leaves(BiTree T)
{
	if (T == NULL)return 0;
	else
	{
		if (T->lchild == NULL && T->rchild == NULL)return 1;
		else
			return Leaves(T->lchild) + Leaves(T->rchild);
	}
}
 
//������
Status Node(BiTree T,int& num)
{
	if (T)
	{
		num++;
		Node(T->lchild, num);
		Node(T->rchild, num);
	}
	else return ERROR;
	return OK;
}
 
 
//�ж��Ƿ�ΪС��������������TURE����
Status SmallBiTree(BiTree T)
{  
	int l, r;
	int cur;
	if (T == NULL)return TRUE;
	if (T->lchild != NULL && T->rchild != NULL)
	{
 
		if (T->data <= T->lchild->data && T->data <= T->rchild->data)
		{
			l = SmallBiTree(T->lchild);
			r = SmallBiTree(T->rchild);
			cur = l & r;
		}
		else cur = 0;
		return cur;
	}
	if (T->lchild == NULL && T->rchild != NULL)
	{
		if (T->data <= T->rchild->data)
		{
			r = SmallBiTree(T->rchild);
			cur = r;
		}
		else
			cur = 0;
		return cur;
	}
	if (T->rchild == NULL && T->lchild != NULL)
	{
		if (T->data <= T->lchild->data)
		{
			l = SmallBiTree(T->lchild);
			cur = l;
		}
		else
			cur = 0;
		return cur;
	}
	if (T->lchild == NULL && T->rchild == NULL)
	{
		return TRUE;
	}
}
 
//�ж϶��������Ƿ����Ԫ��Ϊx�Ľ�㣬���򷵻�ok
Status SearchX(BiTree T, TElemType x)
{ 
	if (T == NULL)return ERROR;
	else
	{
		if (T->data == x)return OK;
		else
		{
			return SearchX(T->lchild, x) | SearchX(T->rchild, x);
		}
	}
}
 
//�ж϶������Ƿ�Ϊ���������(��Ϊ1�Ľ�����Ϊ0)
Status RegularBiTree(BiTree T)
{ 
	if (T == NULL)return TRUE;
	else
	{
		if (T->lchild == NULL && T->rchild == NULL)
		{
			return TRUE;
		}
		else if (T->lchild != NULL && T->rchild != NULL)
		{
			int l, r;
			l = RegularBiTree(T->lchild);
			r = RegularBiTree(T->rchild);
			return l & r;
		}
		else
			return ERROR;
	}
}
 
//�����н��������������
void ExchangeSubTree(BiTree& T)
{
	if (T == NULL)return;
	BiTree l, r;
	l = T->lchild;
	r = T->rchild;
	T->lchild = r;
	T->rchild = l;
	ExchangeSubTree(T->rchild);
	ExchangeSubTree(T->lchild);
}
 
//����xΪ���Ľ������������
Status Depthx(BiTree T, TElemType x)
{
	int depth(BiTree T);
	int d;
	if (T == NULL)return ERROR;
	if (T->data != x)
	{
		int l, r;
		l = Depthx(T->lchild, x);
		r = Depthx(T->rchild, x);
		d = l > r ? l : r;
		return d;
	}
	else
	{
		return depth(T);
	}
 
}
 
//�����з�֧�����
Status BranchNodes(BiTree T)
{
	if (T == NULL)return 0;
	else
	{
		if (T->lchild != NULL || T->rchild != NULL)
		{
			return 1 + BranchNodes(T->lchild) + BranchNodes(T->rchild);
		}
		if (T->rchild == NULL && T->lchild == NULL)
		{
			return 0;
		}
	}
}
 
//�ж������������Ƿ�����
Status Similar(BiTree T1, BiTree T2)
{  
	if (T1 == NULL && T2 == NULL)return TRUE;
	else if (T1 == NULL && T2 != NULL)return FALSE;
	else if (T1 != NULL && T2 == NULL)return FALSE;
	else
	{
		if (Similar(T1->lchild, T2->lchild) == TRUE && Similar(T1->rchild, T2->rchild) == TRUE)return TRUE;
		else return FALSE;
	}
}
