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
	char tree[50];  //�洢������
	int flag = 1;
	while (flag)
	{
		system("cls");
		printf(" -------------------------------------------------\n");
		printf("|        0. ���ĳ�ʼ��                           |\n");
		printf("|        1. ����������                           |\n");
		printf("|        2. ���������                         |\n");
		printf("|        3. ����Ҷ����                           |\n");
		printf("|        4. �ж϶������Ƿ�ΪС����               |\n");
		printf("|        5. ���������ֽ�Ϊ��������             |\n");
		printf("|        6. �滻������                           |\n");
		printf("|        7. �滻������                           |\n");
		printf("|        8. ���������k�����ʵ��Ľ��            |\n");
		printf("|        9. �ж϶��������Ƿ����Ԫ��Ϊx�Ľ��    |\n");
		printf("|        10.�ж϶������Ƿ�Ϊ���������           |\n");
		printf("|        11.��������ÿ��������������           |\n");
		printf("|        12.����xΪ���������������            |\n");
		printf("|        13.��������з�֧�����                 |\n");
		printf("|        14.�ж������������Ƿ�����               |\n");
		printf("|        15.���ٶ�����                           |\n");
		printf("|        16.����������                           |\n");
		printf("|        17.����������                           |\n");
		printf("|        18.�˳�                                 |\n");
		printf(" -------------------------------------------------\n");
		printf("\n����0-16��ѡ����һ��������ѡ�񣬽�ִ���׸�ѡ��\n");
		printf("����������Ҫִ�еĲ���ָ����ţ�");
		scanf("%d", &num);
		getchar();
		switch (num)
		{
		//������
		case 0:
			tag = 1;
			i = 0;
			printf("�밴�����������ʽ�������������#����ʾ��������");
			scanf("%s", tree);
			T = CreateBiTree(tree, i,tag);
			if (tag == 0)
			{
				printf("��������󣬴���ʧ��\n");
				break;
			}
			i = 0;
			triTree = CreateTriTree(tree, i);//���������������ʱʹ��
			printf("�������ɹ�\n");
			printf("�Ѿ�������Ĵ���");
			flag = 1;
			break;
 
		//������
		case 1:
			if (T == NULL)
			{
				printf("��δ������");
			}
			else
			{
				printf("a.�������   b.�������  c.�������:");
				scanf("%c", &sel);
				getchar();
				switch (sel)
				{
				case 'a'://�������
					PreOrderTraverse(T, visit);
					break;
				case 'b'://�������
					InOrderTraverse(T);
					break;
				case 'c'://�������
					i = 0;
					triTree_temp = CreateTriTree(tree, i);//ÿ�κ��������mark�����޸ģ�����Ҫ�ض���
					PostOrder(triTree_temp, visit);//�������
					break;
				default:
					printf("\n��������ȷ�����");
					break;
				}
			}
			break;
 
		//��������
		case 2:
			count = 0;
			Node(T, count);
			printf("\n�����Ľ�㹲�У�%d��", count);
			break;
 
		//����Ҷ����
		case 3:
			count = 0;
			count = Leaves(T);
			printf("\n������Ҷ�ӹ���%d��",count);
			break;
 
		//�ж϶������Ƕ�ΪС��������
		case 4:
			if (T == NULL)printf("����δ����");
			else
			{
				if (SmallBiTree(T) == TRUE)printf("\n��ǰ������ΪС��������\n");
				else printf("\n��ǰ��������ΪС��������\n");
			}
			break;
		//���������ֽ�Ϊ���ң���������
		case 5:
			if (T == NULL)printf("����δ����");
			else
			{
				BreakBiTree(T);
			}
			break;
 
		//�滻������
		case 6:
			if (T == NULL)printf("����δ����");
			else
			{
				BiTree l;
				char lchar[50];
				int temp = 0;
				tag = 1;
				printf("\n����������Ҫ�滻����������");
				scanf("%s", lchar);
				l = CreateBiTree(lchar, temp,tag);
				if (tag == 0)
				{
					printf("\n��������󣬴���ʧ��\n");
					break;
				}
				ReplaceLeft(T, l);
				printf("�滻�����Ϊ��");
				PreOrderTraverse(T, visit);
			}
			break;
 
		//�滻������
		case 7:
			if (T == NULL)printf("����δ����");
			else
			{
				BiTree r;
				char rchar[50];
				int temp = 0;
				tag = 1;
				printf("\n����������Ҫ�滻����������");
				scanf("%s", rchar);
				r = CreateBiTree(rchar, temp,tag);
				if (tag == 0)
				{
					printf("\n��������󣬴���ʧ��\n");
					break;
				}
				ReplaceRight(T, r);
				printf("�滻�����Ϊ��");
				PreOrderTraverse(T, visit);
			}
			break;
 
		//��k�������ʵ��Ľ��
		case 8:
			if (T == NULL)printf("����δ����");
			else
			{
				int k;
				char temp;
				printf("\n����Ҫ�鿴�ڼ��������ʵĽ�㣺");
				scanf("%d", &k);
				getchar();
				temp=PreOrderK(T, k);
				printf("\n��%d�������ʵ��Ľ���ǣ�%c", k,temp);
			}
			break;
		
		//�ж϶��������Ƿ����Ԫ��Ϊx�Ľ��
		case 9:
			if (T == NULL)printf("����δ����");
			else
			{
				char temp;
				int result;
				printf("\n����Ҫ���Ľ��������:");
				scanf("%c", &temp);
				result=SearchX(T, temp);
				if (result == 1)printf("\n�ý�����\n");
				else printf("\n�ý�㲻����\n");
			}
			break;
 
		//�ж϶������Ƿ�Ϊ���������
		case 10:
			if (T == NULL)printf("����δ����");
			else
			{
				int temp;
				temp=RegularBiTree(T);
				if (temp == 1)printf("\n��Ϊ���������\n");
				else printf("\n����Ϊ���������\n");
			}
			break;
 
		//��������ÿ��������������
		case 11:
			if (T == NULL)printf("����δ����");
			else 
			{
				ExchangeSubTree(T);
				printf("\n�������\n");
			}
			break;
 
		//����xΪ���������������
		case 12:
			if (T == NULL)printf("����δ����");
			else
			{
				char temp;
				int dep;
				printf("\n����Ҫ����ʲôΪ�������������:");
				scanf("%c", &temp);
				dep= Depthx(T, temp);
				if (dep == 0)
				{
					printf("��%cΪֵ��㲻���ڣ�����������\n",temp);
				}
				else
				{
					printf("\n��%cΪ�������������Ϊ%d", temp, dep);
				}
				
			}
			break;
 
		//�����з�֧����� 
		case 13:
			if (T == NULL)printf("����δ����");
			else
			{
				int temp;
				temp = BranchNodes(T);
				printf("\n���з�֧�����Ϊ:%d", temp);
			}
			break;
 
		//�ж��������Ƿ�����
		case 14:
			if (T == NULL)printf("����δ����");
			else
			{
				BiTree T2;
				char t2[50];
				int temp = 0;
				tag = 1;
				printf("\n����������Ҫ�Ƚϵ�������");
				scanf("%s", t2);
				T2 = CreateBiTree(t2, temp, tag);
				if (tag == 0)
				{
					printf("\n��������󣬴���ʧ��\n");
					break;
				}
				if (Similar(T, T2) == TRUE)printf("\n����������");
				else printf("\n������������");
			}
			break;
 
		//���ٶ�����
		case 15:
			if (T == NULL)printf("����δ����");
			else
			{
				DestroyBiTree(T);
				printf("��������");
			}
			break;
 
		//����������
		case 16:
			if (T == NULL)printf("����δ����");
			else
			{
				Breakleft(T);
			}
			break;
 
		//
		case 17:
			if (T == NULL)printf("����δ����");
			else
			{
				Breakright(T);
			}
			break;
		case 18:
			flag = 0;
			printf("�������");
			break;
		default:
			printf("\n��������ȷ�����");
			break;
		}
		printf("\n");
		getchar();
		system("pause");
	}
	return 0;
}
