#include<stdio.h>
#include<stdlib.h>
#include"BinaryTree.h"
 
 
//����������
Status InitBiTree(BiTree& T); 
 
//����һ�ö�����T�����и�����ֵΪe��L��R�ֱ�Ϊ��������������
BiTree MakeBiTree(TElemType e, BiTree L, BiTree R);
 
//���ٶ�����
void DestroyBiTree(BiTree& T);
 
//�Զ������пգ����򷵻�TURE�����򷵻�FALSE
Status BiTreeEmpty(BiTree T);
 
//��һ�ö������ֽ�Ϊ��������������������������
Status BreakBiTree(BiTree& T);
 
//����������
Status Breakleft(BiTree& T);
 
//����������
Status Breakright(BiTree& T);
 
//�滻����������T�ǿգ�����LT�滻T��������������LT����T��ԭ��������
Status ReplaceLeft(BiTree& T, BiTree& LT);
 
//�滻����������T�ǿգ�����RT�滻T��������������RT����T��ԭ��������
Status ReplaceRight(BiTree& T, BiTree& RT);
 
//�����������
BiTree CreateBiTree(TElemType* T, Status& i, Status& tag);//defBTΪ���������
 
//�ݹ��㷨����Զ�����T�������ʱ��k�����ʵ��Ľ���ֵ
TElemType PreOrderK(BiTree T, Status k);
 
//���������Ҷ����
Status Leaves(BiTree T);
 
//������������
Status Node(BiTree T, Status& num);
 
//�ж��Ƿ�ΪС��������������TURE����
Status SmallBiTree(BiTree T);
 
//�ж϶��������Ƿ����Ԫ��Ϊx�Ľ�㣬���򷵻�ok
Status SearchX(BiTree T, TElemType x);
 
//�ж϶������Ƿ�Ϊ���������(��Ϊ1�Ľ�����Ϊ0)
Status RegularBiTree(BiTree T);
 
//�����н��������������
void ExchangeSubTree(BiTree& T);
 
//�����з�֧�����
Status BranchNodes(BiTree T);
 
//�ж������������Ƿ�����
Status Similar(BiTree T1, BiTree T2);
 
 
//���������������ʹ��ջ�ķǵݹ飩
Status PreOrderTraverse(BiTree T);
 
//�������������(�ݹ�)
void InOrderTraverse(TriTree T, Status(*visit)(TElemType e));
 
//�������������
void PostOrder(TriTree bt, Status(*visit)(TElemType e));
 
//����������
TriTree CreateTriTree(TElemType* tree, Status& i);
 
//����1�����ʽ���ֵ
Status visit(TElemType e);
//����2�����������Զ�����T�������ʱ��k�����ʵ��Ľ���ֵ
TElemType visitsPreOrderK(BiTree T, Status& i, Status k);
//����3��������ֵΪx�Ľ��Ϊ�����������
Status depth(BiTree T);
