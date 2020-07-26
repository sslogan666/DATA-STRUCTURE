#include <stdio.h>
#include <stdlib.h>
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;

}LNode;

/*创建一个带头结点的空单链表*/
LNode *Create_head( )
{ 
	LNode *head;//头指针，指向头结点的指针 
	head = (LNode *)malloc(sizeof(LNode));//生成头结点 
	head->next = NULL;//指针域为空 
	return head;
} 

/*头插法建立链表*/
LNode *Create_LinkList1() 
{
	LNode *head, *s;
	int x;
	head = Create_head(); //创建头结点 
	scanf("%d",&x);
	while(x!=-1)//-1为结束标志 
	{
		s = (LNode*)malloc(sizeof(LNode));//为新结点申请空间 
		s->data = x;//新结点数据域赋值 
		s->next = head->next;//将头结点后面的结点链接到新结点之后 
		head->next = s;//插入头结点之后 
		scanf("%d",&x);
	}
	return head; 
} 

/*尾插法建立链表*/
LNode *Create_LinkList2() 
{
	LNode *head, *r,*s;
	int x;
	head = Create_head(); //创建头结点 
	r=head;//尾指针指最后一个结点即头结点 
	scanf("%d",&x);
	while(x!=-1)//-1为结束标志 
	{
		s = (LNode*)malloc(sizeof(LNode));//为新结点申请空间 
		s->data = x;//新结点数据域赋值 
		s->next = NULL; //新结点要插入尾部，所以指针域为空 
		r->next = s;
		r = s;
		scanf("%d",&x);
	}
	return head; 
}

/*求表长*/ 
int Length_LinkList(LNode *head)
{
	LNode *p=head->next;//从头结点的直接后继结点开始
	int i=0;
	while(p!=NULL)//当未到链尾时继续遍历 
	{
		i++;
		p=p->next;
	}
	return i;
}

/*按序号查找*/
LNode *Get_LinkList(LNode *head, int i)
{
	LNode *p=head;//由第一个结点开始查找 
	int j=0;
	while(p!=NULL && j<i)//当未找到链尾且没到第i个时继续查找 
	{
		p=p->next;
		j++;
	}
	return p;//找到则返回指向i结点的指针，找不到则p已为空返回空值 
} 

/*按值查找*/
LNode *Locate_LinkList(LNode *head, int x)
{
	LNode *p=head->next;//从第一个数据结点开始查找 
	while(p!=NULL && p->data!=x)//当未查到链尾且当前结点不等于x时继续查找 
		p=p->next;
	return p;//找到则返回指向值为x的结点的指针值，找不到则p已为空返回空值 
}

/*插入结点
在单链表第i个位置上插入值为x的元素*/ 
void Insert_LinkList(LNode *head, int i, datatype x)
{
	LNode *p,*q;
	p=Get_LinkList(head, i-1);//查找第i-1个元素 
	if(p==NULL)
		printf("插入位置非法！"); //第i-1个位置不存在 
	else
	{
		q=(LNode *)malloc(sizeof(LNode));//申请结点空间 
		q->data=x;
		q->next=p->next;//先连 
		p->next=q;//后断 
	}
}

/*删除结点
删除单链表上第i个数据结点 */ 
void Del_LinkList(LNode *head, int i)
{
	LNode *p,*q;
	p=Get_LinkList(head, i-1);//查找第i-1个元素 
	if(p==NULL)
		printf("第i-1个结点不存在！");//待删除结点的前一个结点不存在 
	else
		if(p->next==NULL)
			printf("第i个结点不存在！");//待删除结点不存在 
		else
		{
			q=p->next;
			p->next=q->next;
			free(q);//回收第i个结点的空间 
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
