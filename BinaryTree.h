#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -1
typedef int Status;		    //用作函数返回类型，表示函数结果状态 
typedef char TElemType;		//假设二叉树结点的元素类型为字符
 
 
//二叉树链式
typedef struct BiTNode 
{
	TElemType data;
	BiTNode* lchild, * rchild;
} BiTNode, * BiTree;
 
//三叉链表
typedef struct TriTNode 
{
	int mark;
	TElemType data;
	TriTNode* parent, * lchild, * rchild;
}TriTNode, * TriTree;
 
 
//辅助栈
typedef struct BSNode
{
	BiTree data;
	struct BSNode* next;
}BSNode, *BStack;
//初始化栈
void InitStack(BStack& s)
{
	s = NULL;
}
//元素入栈
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
//出栈
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
//判断栈空
Status StackEmpty_BS(BStack s)
{
	if (s == NULL)return TRUE;
	else return FALSE;
}
 
 
 
//特殊1，访问结点的值
Status visit(TElemType e)
{
	if (e)
	{
		printf("%c", e);
		return OK;
	}
	else return ERROR;
}
//特殊2，配合用于求对二叉树T先序遍历时第k个访问到的结点的值
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
//特殊3，辅助求值为x的结点为根的子树深度
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
 
//创建三叉树
TriTree CreateTriTree(TElemType* tree, Status& i)
{
	TriTree T;
	TElemType node = tree[i++];
	if (node=='#')
	{
		T = NULL; //T是空树
	}
	else 
	{
		T = (TriTree)malloc(sizeof(TriTNode));
		if (T == NULL)
			return NULL;
		T->data = node;
		T->mark = 0;
		T->parent = NULL;
		T->lchild = CreateTriTree(tree, i); //构建左子树
		if (T->lchild != NULL)
		{
			T->lchild->parent = T;
		}   //如果左子树存在，则赋其双亲值
		T->rchild = CreateTriTree(tree, i); //构建右子树
		if (T->rchild != NULL)
		{
			T->rchild->parent = T;      //如果右子树存在，则赋其双亲值
		}
	}
	return T;
}
 
//创建二叉树，初始化
Status InitBiTree(BiTree& T) 
{
	T = NULL;
	return OK;
}
 
//创建一棵二叉树T，其中根结点的值为e，L和R分别为左子树和右子树
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
 
//先序构造二叉树
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
		printf("第%d个数据输入错误或不存在，请重新输入\n",i);
		temp = NULL;
		return ERROR;
	}
	else if ('#' == ch)InitBiTree(temp);//创建空树
	else
	{
		temp = MakeBiTree(ch, NULL, NULL);
		temp->lchild = CreateBiTree(T, i,tag);
		temp->rchild = CreateBiTree(T, i,tag);
	}
	return temp;
}
 
//先序遍历二叉树（使用栈的非递归）
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
 
//中序遍历二叉树（递归）
void InOrderTraverse(BiTree T)
{
	if (T)
	{
		InOrderTraverse(T->lchild);       //前序遍历左子树
		printf("%c", T->data);              //访问根结点
		InOrderTraverse(T->rchild);       //前序遍历右子树
	}
}
 
//后序遍历三叉树(三叉树)
void PostOrder(TriTree bt, Status(*visit)(TElemType e))
{
	TriTree p = bt;
	// visit(p->data);
	while (p) {
		while (p->mark == 0) {  //先遍历左孩子
			p->mark = 1;
			if (p->lchild)
				p = p->lchild;
		}
		while (p->mark == 1) {  //再遍历右孩子
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
 
//销毁二叉树
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
 
 
//对二叉树判空，空则返回TURE，否则返回FALSE
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
 
//将一棵二叉树分解为根，左子树，右子树三个部分
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
		printf("根结点为（先序）：");
		PreOrderTraverse(T,visit);
		printf("\n");
		printf("左子树为（先序）：");
		PreOrderTraverse(L, visit);
		printf("\n");
		printf("右子树为（先序）：");
		PreOrderTraverse(R, visit);
		printf("\n");
		return OK;
	}
}
 
//分离左子树
Status Breakleft(BiTree& T)
{
	BiTree l;
	if (T == NULL)return ERROR;
	l = T->lchild;
	T->lchild=NULL;
	printf("被分离的左子树为(先序)：");
	PreOrderTraverse(l, visit);
	printf("\n");
	printf("分离后的原树为(先序):");
	PreOrderTraverse(T, visit);
	return OK;
}
 
//分离右子树
Status Breakright(BiTree& T)
{
	BiTree r;
	if (T == NULL)return ERROR;
	r = T->rchild;
	T->rchild = NULL;
	printf("被分离的右子树为(先序)：");
	PreOrderTraverse(r, visit);
	printf("\n");
	printf("分离后的原树为(先序):");
	PreOrderTraverse(T, visit);
	return OK;
}
 
//替换左子树。若T非空，则用LT替换T的左子树，并用LT返回T的原有左子树
Status ReplaceLeft(BiTree& T, BiTree& LT)
{
	BiTree temp;
	if (T == NULL)return ERROR;
	temp = T->lchild;
	T->lchild = LT;
	LT = temp;
	return OK;
}
 
//替换右子树。若T非空，则用RT替换T的右子树，并用RT返回T的原有右子树
Status ReplaceRight(BiTree& T, BiTree& RT)
{
	BiTree temp;
	if (T == NULL)return ERROR;
	temp = T->rchild;
	T->rchild = RT;
	RT = temp;
	return OK;
}
 
 
//递归算法，求对二叉树T先序遍历时第k个访问到的结点的值
TElemType PreOrderK(BiTree T, Status k)
{
	int x = 1;
	return visitsPreOrderK(T, x, k);
}
 
//求二叉树的叶子数
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
 
//求结点数
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
 
 
//判断是否为小根二叉树，返回TURE则是
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
 
//判断二叉树中是否存在元素为x的结点，是则返回ok
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
 
//判断二叉树是否为正则二叉树(度为1的结点个数为0)
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
 
//将所有结点左右子树交换
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
 
//求以x为根的结点的子树的深度
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
 
//求树中分支结点数
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
 
//判断两个二叉树是否相似
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
