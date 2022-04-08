typedef struct node{
    void* data;       		
    struct node *next;		
} Node;
 
typedef struct Lqueue{
    Node *front;       		
    Node *rear;        		
	size_t data_size;		
} LQueue;
 //�洢�ṹ���� 
typedef enum{
    FALSE=0, TRUE=1
} Status;
void InitLQueue(LQueue *Q) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return;
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
	return;
}
//��ʼ��
Status IsEmptyLQueue(const LQueue *Q) {
	return (Q->front == Q->rear? TRUE: FALSE);
}//�п�
Status EnLQueue(LQueue *Q, void *data) {
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void *)malloc(Q->data_size);
	memcpy(p->data, data, Q->data_size);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}	//���
Status DeLQueue(LQueue *Q) {
	if(IsEmptyLQueue(Q))
		return FALSE;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)  
		Q->rear = Q->front;
	free(p);
	return TRUE;
}//����
Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->data_size);//��ͷ�����һ���ڵ�ָ���λ�ø����ֽ��� 
	return TRUE;	
}//���������ͷԪ�� 
int LengthLQueue(LQueue *Q) {
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next; 
	return length;
}//���г���
void DestoryLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return; 
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}//���ٶ���
void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q))
		return;
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next; 
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
	return;
}	//��ն���
//foo����Lprint��ӡ���� 
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q, int size)) {
	if (IsEmptyLQueue(Q))
		return FALSE;
		Node* p = (void *)malloc(Q->data_size); 
		p = Q->front->next; 
		int i = 1;
		while (p != NULL) {
			if (i % 5 == 0) printf("\n"); 
			foo(p->data, Q->data_size);
			p = p->next;
			i++;
		}
		printf("\n");
	return TRUE;
} 
//�����ֽ�����ʵ�ֱ��� 
void LPrint(void *q, int size) {
	if (size == sizeof(double))
		printf("%lf", *(double *)q);
	if (size == sizeof(char))
		printf("%c", *(char *)q);
	if (size == sizeof (int))
		printf("%d", *(int *)q);
	printf("-<");
} 
//���������� 
