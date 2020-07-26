#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;

}LNode;

/*����һ����ͷ���Ŀյ�����*/
LNode *Create_head( )
{ 
	LNode *head;//ͷָ�룬ָ��ͷ����ָ�� 
	head = (LNode *)malloc(sizeof(LNode));//����ͷ��� 
	head->next = NULL;//ָ����Ϊ�� 
	return head;
} 

/*ͷ�巨��������*/
LNode *Create_LinkList1() 
{
	LNode *head, *s;
	int x;
	head = Create_head(); //����ͷ��� 
	scanf("%d",&x);
	while(x!=-1)//-1Ϊ������־ 
	{
		s = (LNode*)malloc(sizeof(LNode));//Ϊ�½������ռ� 
		s->data = x;//�½��������ֵ 
		s->next = head->next;//��ͷ������Ľ�����ӵ��½��֮�� 
		head->next = s;//����ͷ���֮�� 
		scanf("%d",&x);
	}
	return head; 
} 

/*β�巨��������*/
LNode *Create_LinkList2() 
{
	LNode *head, *r,*s;
	int x;
	head = Create_head(); //����ͷ��� 
	r=head;//βָ��ָ���һ����㼴ͷ��� 
	scanf("%d",&x);
	while(x!=-1)//-1Ϊ������־ 
	{
		s = (LNode*)malloc(sizeof(LNode));//Ϊ�½������ռ� 
		s->data = x;//�½��������ֵ 
		s->next = NULL; //�½��Ҫ����β��������ָ����Ϊ�� 
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	return head; 
}

/*���*/ 
int Length_LinkList(LNode *head)
{
	LNode *p=head->next;//��ͷ����ֱ�Ӻ�̽�㿪ʼ
	int i=0;
	while(p!=NULL)//��δ����βʱ�������� 
	{
		i++;
		p=p->next;
	}
	return i;
}

/*����Ų���*/
LNode *Get_LinkList(LNode *head, int i)
{
	LNode *p=head;//�ɵ�һ����㿪ʼ���� 
	int j=0;
	while(p!=NULL && j<i)//��δ�ҵ���β��û����i��ʱ�������� 
	{
		p=p->next;
		j++;
	}
	return p;//�ҵ��򷵻�ָ��i����ָ�룬�Ҳ�����p��Ϊ�շ��ؿ�ֵ 
} 

/*��ֵ����*/
LNode *Locate_LinkList(LNode *head, int x)
{
	LNode *p=head->next;//�ӵ�һ�����ݽ�㿪ʼ���� 
	while(p!=NULL && p->data!=x)//��δ�鵽��β�ҵ�ǰ��㲻����xʱ�������� 
		p=p->next;
	return p;//�ҵ��򷵻�ָ��ֵΪx�Ľ���ָ��ֵ���Ҳ�����p��Ϊ�շ��ؿ�ֵ 
}

/*������
�ڵ������i��λ���ϲ���ֵΪx��Ԫ��*/ 
void Insert_LinkList(LNode *head, int i, datatype x)
{
	LNode *p,*q;
	p=Get_LinkList(head, i-1);//���ҵ�i-1��Ԫ�� 
	if(p==NULL)
		printf("����λ�÷Ƿ���"); //��i-1��λ�ò����� 
	else
	{
		q=(LNode *)malloc(sizeof(LNode));//������ռ� 
		q->data=x;
		q->next=p->next;//���� 
		p->next=q;//��� 
	}
}

/*ɾ�����
ɾ���������ϵ�i�����ݽ�� */ 
void Del_LinkList(LNode *head, int i)
{
	LNode *p,*q;
	p=Get_LinkList(head, i-1);//���ҵ�i-1��Ԫ�� 
	if(p==NULL)
		printf("��i-1����㲻���ڣ�");//��ɾ������ǰһ����㲻���� 
	else
		if(p->next==NULL)
			printf("��i����㲻���ڣ�");//��ɾ����㲻���� 
		else
		{
			q=p->next;
			p->next=q->next;
			free(q);//���յ�i�����Ŀռ� 
		} 
}
 void output(LNode *h)
  { LNode *p;
    printf("Output:");
    p=h->next;
    while (p!=NULL)
      { printf("%d ",p->data);
        p=p->next;
       }
    printf("\n");
   }

void main()
  {LNode *L2;
   L2=Create_LinkList2();
   //output(L2);
   //printf("%d",Length_LinkList(L2));
   //printf("%d",Get_LinkList(L2, 2)->data);
   Del_LinkList(L2, 1);
   output(L2);
  }
