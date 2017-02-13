#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode{
	int data;                         //������
	struct BiTNode *lchild, *rchild;  //���Һ���
}BiTNode,*BiTree;


BiTree TreeCreat(BiTree BT, int k);
void PreOrder(BiTree T);
void PreOrder_nonrecur(BiTree T);
void InOrder_nonrecur(BiTree T);
void PostOder_nonrecur(BiTree T);
int main(){
	BiTree BT = (BiTNode *)malloc(sizeof(BiTNode *));
	BiTree tree = TreeCreat(BT, 0);
	//PreOrder(tree);
	//PreOrder_nonrecur(tree);
	//InOrder_nonrecur(tree);
	PostOder_nonrecur(tree);

	printf("\n");
	system("pause");
	return 0;

}
//���ɶ���������
BiTree TreeCreat(BiTree BT,int k){

	BiTree p = (BiTNode *)malloc(sizeof(BiTNode *));
	int x;
	printf("����ڵ����ֵ��");

	scanf_s("%d", &x);
	if (x != 0){
		if (!(p = (BiTNode *)malloc(sizeof(BiTNode *)))) exit(0);

		//���ɸ����
		p->data = x;
		p->lchild = NULL;
		p->rchild = NULL;

		if (k == 0) BT = p;
		if (k == 1) BT->lchild = p;
		if (k == 2) BT->rchild = p;

		TreeCreat(p, 1);  //����������
		TreeCreat(p, 2);  //����������
	}
	return BT;
}

//����������ݹ����
void PreOrder(BiTree T){
	if (T != NULL){
		printf("%d", T->data);
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}

}
//����������ǵݹ����
void PreOrder_nonrecur(BiTree T){
	BiTree st[20];
	int top = -1;
	BiTree p = (BiTNode *)malloc(sizeof(BiTNode *));
	if (T != NULL){
		st[++top] = T;
		while (top>-1)
		{
			p = st[top--];
			printf("%d", p->data);

			if (p->rchild != NULL) st[++top] = p->rchild;
			if (p->lchild != NULL) st[++top] = p->lchild;
			
		}
	}

}
//����������ǵݹ����
void InOrder_nonrecur(BiTree T){
	BiTree st[20];
	BiTree p = (BiTree)malloc(sizeof(BiTree));
	p = T;
	int top = -1;
	while (p != NULL || top > -1){
	    
		if (p != NULL){
			st[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = st[top--];
			printf("%d", p->data);
			p = p->rchild;
		}
	}
	free(p);
}

//����������ǵݹ����
void PostOder_nonrecur(BiTree T){
	BiTree st[20];
	BiTree p = (BiTree)malloc(sizeof(BiTree));

	int flag, top = -1;
	do
	{
		//����������������ջ
		while (T != NULL){     
			st[++top] = T;
			T = T->lchild;
		}

		p = NULL, flag = 1;
	    
		//��ջ��Ԫ�ؼ���ǰ�ĸ�����ջǰ���ø�������������ջ
		while (top != -1 && flag==1){

			T = st[top];
			if (T->rchild == p){
				--top;
				printf("%d", T->data);
				p = T;               //pָ��ղŷ��ʵĽ��
			}
			else
			{
				T = T->rchild;
				flag = 0;           //���ó�δ�����ʵı�ǲ�����while���
			}
		}


	} while (top!=-1);

}