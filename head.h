#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"
 
 
//创建二叉树
Status InitBiTree(BiTree& T); 
 
//创建一棵二叉树T，其中根结点的值为e，L和R分别为左子树和右子树
BiTree MakeBiTree(TElemType e, BiTree L, BiTree R);
 
//销毁二叉树
void DestroyBiTree(BiTree& T);
 
//对二叉树判空，空则返回TURE，否则返回FALSE
Status BiTreeEmpty(BiTree T);
 
//将一棵二叉树分解为根，左子树，右子树三个部分
Status BreakBiTree(BiTree& T);
 
//分离左子树
Status Breakleft(BiTree& T);
 
//分离右子树
Status Breakright(BiTree& T);
 
//替换左子树。若T非空，则用LT替换T的左子树，并用LT返回T的原有左子树
Status ReplaceLeft(BiTree& T, BiTree& LT);
 
//替换右子树。若T非空，则用RT替换T的右子树，并用RT返回T的原有右子树
Status ReplaceRight(BiTree& T, BiTree& RT);
 
//先序构造二叉树
BiTree CreateBiTree(TElemType* T, Status& i, Status& tag);//defBT为输入的数组
 
//递归算法，求对二叉树T先序遍历时第k个访问到的结点的值
TElemType PreOrderK(BiTree T, Status k);
 
//求二叉树的叶子数
Status Leaves(BiTree T);
 
//求二叉树结点数
Status Node(BiTree T, Status& num);
 
//判断是否为小根二叉树，返回TURE则是
Status SmallBiTree(BiTree T);
 
//判断二叉树中是否存在元素为x的结点，是则返回ok
Status SearchX(BiTree T, TElemType x);
 
//判断二叉树是否为正则二叉树(度为1的结点个数为0)
Status RegularBiTree(BiTree T);
 
//将所有结点左右子树交换
void ExchangeSubTree(BiTree& T);
 
//求树中分支结点数
Status BranchNodes(BiTree T);
 
//判断两个二叉树是否相似
Status Similar(BiTree T1, BiTree T2);
 
 
//先序遍历二叉树（使用栈的非递归）
Status PreOrderTraverse(BiTree T);
 
//中序遍历二叉树(递归)
void InOrderTraverse(TriTree T, Status(*visit)(TElemType e));
 
//后序遍历三叉树
void PostOrder(TriTree bt, Status(*visit)(TElemType e));
 
//创建三叉树
TriTree CreateTriTree(TElemType* tree, Status& i);
 
//特殊1，访问结点的值
Status visit(TElemType e);
//特殊2，配合用于求对二叉树T先序遍历时第k个访问到的结点的值
TElemType visitsPreOrderK(BiTree T, Status& i, Status k);
//特殊3，辅助求值为x的结点为根的子树深度
Status depth(BiTree T);
