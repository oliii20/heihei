#include"head.h"
 
int main(void)
{
	BiTree T = NULL;
	TriTree triTree = NULL;
	TriTree triTree_temp = NULL;
	int tag;
	int i, count;
	int num;
	char sel;
	char tree[50];  //存储二叉树
	int flag = 1;
	while (flag)
	{
		system("cls");
		printf(" -------------------------------------------------\n");
		printf("|        0. 树的初始化                           |\n");
		printf("|        1. 遍历二叉树                           |\n");
		printf("|        2. 计算结点个数                         |\n");
		printf("|        3. 计算叶子数                           |\n");
		printf("|        4. 判断二叉树是否为小根树               |\n");
		printf("|        5. 将二叉树分解为根，左，右             |\n");
		printf("|        6. 替换左子树                           |\n");
		printf("|        7. 替换右子树                           |\n");
		printf("|        8. 求二叉树第k个访问到的结点            |\n");
		printf("|        9. 判断二叉树中是否存在元素为x的结点    |\n");
		printf("|        10.判断二叉树是否为正则二叉树           |\n");
		printf("|        11.交换树中每个结点的左右子树           |\n");
		printf("|        12.求以x为根结点的子树的深度            |\n");
		printf("|        13.求二叉树中分支结点数                 |\n");
		printf("|        14.判断两个二叉树是否相似               |\n");
		printf("|        15.销毁二叉树                           |\n");
		printf("|        16.分离左子树                           |\n");
		printf("|        17.分离右子树                           |\n");
		printf("|        18.退出                                 |\n");
		printf(" -------------------------------------------------\n");
		printf("\n请在0-16中选择，若一次输入多个选择，将执行首个选择\n");
		printf("请输入你想要执行的操作指令序号：");
		scanf("%d", &num);
		getchar();
		switch (num)
		{
		//创建树
		case 0:
			tag = 1;
			i = 0;
			printf("请按照先序遍历格式输入二叉树（‘#’表示空树）：");
			scanf("%s", tree);
			T = CreateBiTree(tree, i,tag);
			if (tag == 0)
			{
				printf("树输入错误，创建失败\n");
				break;
			}
			i = 0;
			triTree = CreateTriTree(tree, i);//后序三叉链表遍历时使用
			printf("树创建成功\n");
			printf("已经完成树的创建");
			flag = 1;
			break;
 
		//遍历树
		case 1:
			if (T == NULL)
			{
				printf("尚未创建树");
			}
			else
			{
				printf("a.先序遍历   b.中序遍历  c.后序遍历:");
				scanf("%c", &sel);
				getchar();
				switch (sel)
				{
				case 'a'://先序遍历
					PreOrderTraverse(T, visit);
					break;
				case 'b'://中序遍历
					InOrderTraverse(T);
					break;
				case 'c'://后序遍历
					i = 0;
					triTree_temp = CreateTriTree(tree, i);//每次后序遍历后，mark都被修改，故需要重定义
					PostOrder(triTree_temp, visit);//后序遍历
					break;
				default:
					printf("\n请输入正确的序号");
					break;
				}
			}
			break;
 
		//计算结点数
		case 2:
			count = 0;
			Node(T, count);
			printf("\n该树的结点共有：%d个", count);
			break;
 
		//计算叶子数
		case 3:
			count = 0;
			count = Leaves(T);
			printf("\n该树的叶子共：%d个",count);
			break;
 
		//判断二叉树是都为小根二叉树
		case 4:
			if (T == NULL)printf("树尚未建立");
			else
			{
				if (SmallBiTree(T) == TRUE)printf("\n当前二叉树为小根二叉树\n");
				else printf("\n当前二叉树不为小根二叉树\n");
			}
			break;
		//将二叉树分解为左，右，根三部分
		case 5:
			if (T == NULL)printf("树尚未建立");
			else
			{
				BreakBiTree(T);
			}
			break;
 
		//替换左子树
		case 6:
			if (T == NULL)printf("树尚未建立");
			else
			{
				BiTree l;
				char lchar[50];
				int temp = 0;
				tag = 1;
				printf("\n请输入你想要替换的左子树：");
				scanf("%s", lchar);
				l = CreateBiTree(lchar, temp,tag);
				if (tag == 0)
				{
					printf("\n树输入错误，创建失败\n");
					break;
				}
				ReplaceLeft(T, l);
				printf("替换后的树为：");
				PreOrderTraverse(T, visit);
			}
			break;
 
		//替换右子树
		case 7:
			if (T == NULL)printf("树尚未建立");
			else
			{
				BiTree r;
				char rchar[50];
				int temp = 0;
				tag = 1;
				printf("\n请输入你想要替换的左子树：");
				scanf("%s", rchar);
				r = CreateBiTree(rchar, temp,tag);
				if (tag == 0)
				{
					printf("\n树输入错误，创建失败\n");
					break;
				}
				ReplaceRight(T, r);
				printf("替换后的树为：");
				PreOrderTraverse(T, visit);
			}
			break;
 
		//第k个被访问到的结点
		case 8:
			if (T == NULL)printf("树尚未建立");
			else
			{
				int k;
				char temp;
				printf("\n你想要查看第几个被访问的结点：");
				scanf("%d", &k);
				getchar();
				temp=PreOrderK(T, k);
				printf("\n第%d个被访问到的结点是：%c", k,temp);
			}
			break;
		
		//判断二叉树中是否存在元素为x的结点
		case 9:
			if (T == NULL)printf("树尚未建立");
			else
			{
				char temp;
				int result;
				printf("\n你想要检查的结点数据是:");
				scanf("%c", &temp);
				result=SearchX(T, temp);
				if (result == 1)printf("\n该结点存在\n");
				else printf("\n该结点不存在\n");
			}
			break;
 
		//判断二叉树是否为正则二叉树
		case 10:
			if (T == NULL)printf("树尚未建立");
			else
			{
				int temp;
				temp=RegularBiTree(T);
				if (temp == 1)printf("\n树为正则二叉树\n");
				else printf("\n树不为正则二叉树\n");
			}
			break;
 
		//交换树中每个结点的左右子树
		case 11:
			if (T == NULL)printf("树尚未建立");
			else 
			{
				ExchangeSubTree(T);
				printf("\n交换完成\n");
			}
			break;
 
		//求以x为根结点的子树的深度
		case 12:
			if (T == NULL)printf("树尚未建立");
			else
			{
				char temp;
				int dep;
				printf("\n你想要求以什么为根的子树的深度:");
				scanf("%c", &temp);
				dep= Depthx(T, temp);
				if (dep == 0)
				{
					printf("以%c为值结点不存在，请重新输入\n",temp);
				}
				else
				{
					printf("\n以%c为根结点的子树深度为%d", temp, dep);
				}
				
			}
			break;
 
		//求树中分支结点数 
		case 13:
			if (T == NULL)printf("树尚未建立");
			else
			{
				int temp;
				temp = BranchNodes(T);
				printf("\n树中分支结点数为:%d", temp);
			}
			break;
 
		//判断两棵树是否相似
		case 14:
			if (T == NULL)printf("树尚未建立");
			else
			{
				BiTree T2;
				char t2[50];
				int temp = 0;
				tag = 1;
				printf("\n请输入你想要比较的新树：");
				scanf("%s", t2);
				T2 = CreateBiTree(t2, temp, tag);
				if (tag == 0)
				{
					printf("\n树输入错误，创建失败\n");
					break;
				}
				if (Similar(T, T2) == TRUE)printf("\n两棵树相似");
				else printf("\n两棵树不相似");
			}
			break;
 
		//销毁二叉树
		case 15:
			if (T == NULL)printf("树尚未建立");
			else
			{
				DestroyBiTree(T);
				printf("树已销毁");
			}
			break;
 
		//分离左子树
		case 16:
			if (T == NULL)printf("树尚未建立");
			else
			{
				Breakleft(T);
			}
			break;
 
		//
		case 17:
			if (T == NULL)printf("树尚未建立");
			else
			{
				Breakright(T);
			}
			break;
		case 18:
			flag = 0;
			printf("程序结束");
			break;
		default:
			printf("\n请输入正确的序号");
			break;
		}
		printf("\n");
		getchar();
		system("pause");
	}
	return 0;
}
