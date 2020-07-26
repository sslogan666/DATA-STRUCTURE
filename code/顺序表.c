//#include <stdio.h>
//#include <stdlib.h>
//#define maxsize 10
//typedef int datatype;
//typedef struct
//  {datatype data[maxsize];
//   int last;
//  }seqlist;
//
//seqlist *init()
//  {seqlist *L;
//   L=(seqlist*)malloc(sizeof(seqlist));
//   L->last=-1;
//   return(L);
//  }
//
//void input(seqlist *L)
//  {int i,k;
//   printf("Input element number:");
//   scanf("%d",&k);
//   for(i=0;i<=k-1;i++)
//     scanf("%d",&L->data[i]);
//   L->last=k-1;
//  }
//
//void output(seqlist *L)
// {int i;
//  printf("\noutput:");
//  for(i=0;i<=L->last;i++)
//    printf("%d ",L->data[i]);
//  }
//int insert(seqlist *L,int i,datatype x)
//  {int j;
//   if (L->last==maxsize-1)
//     {printf("List full!");
//      return(-1); }
//    if (i<1||i>L->last+2)
//     {printf("Error!");
//      return(0); }
//    for (j=L->last;j>=i-1;j--)
//      L->data[j+1]=L->data[j];
//    L->data[i-1]=x;
//    L->last++;
//    return(1);
//  }
//int deleter(seqlist *L,int i)
//  {int j;
//   if (i<1||i>L->last+1)
//     {printf("No exist!");
//      return(0);  }
//   for (j=i;j<=L->last;j++)
//     L->data[j-1]=L->data[j];
//   L->last--;
//   return(1);
//  }
//int main()
//  {
//  	  printf("%d",sizeof(seqlist));
////	  seqlist *L1;
////    L1=init();
////    input(L1);
////    output(L1);
////    deleter(L1,2);
////    output(L1);
////    insert(L1,3,88);
////    output(L1);
//    return 0;


#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10
typedef int datatype;
typedef struct
{
    datatype data[MAXSIZE];//�洢˳����е�Ԫ��
    int len;//˳���ı�
}SeqList;//˳�������

/*���˳���*/
void Output_SeqList(SeqList *L)
{
    int i;
    for(i=1;i<=L->len;i++)
        printf("%d\t",L->data[i]);
    printf("\n");
}

/*˳���ĳ�ʼ��
����ձ�����˳���Ĵ洢�ռ䣬���Ϊ0*/
SeqList *Init_SeqList()
{
    SeqList *L;//����˳���ָ�����
    L = (SeqList*)malloc(sizeof(SeqList));//��˳������洢�ռ䣬sizeof��������������ռ���ֽ���
    L->len = 0;//������Ϊ0
    return L;//����˳���ָ��
}

/*����˳���
����˳���ĳ���n��n��Ԫ�ؼ��ɽ���˳���*/
void CreatList(SeqList *L)
{
    int i,n;
    printf("����˳���ĳ��ȣ�");
    scanf("%d",&n);//����˳���ı�n
    printf("����˳���Ԫ��");
    for(i=1;i<=n;i++)
        scanf("%d",&(L->data[i]));//��������n��Ԫ��
    L->len = n;//���ñ�
}

/*��������
��˳���ĵ�i��λ�ò�����Ԫ��x*/
void Insert_SeqList(SeqList *L, int i, datatype x)
{
    int j;
    if(L->len == MAXSIZE)//�жϱ���
        printf("������");
    else
	    if(i<1 || i>L->len+1)//�жϲ���λ�÷Ƿ�
	        printf("����λ�÷Ƿ���");
	    else
	    {
	    	
	        for(j=L->len;j>=i;j--)//��a[i]��a[n]˳�����һ��λ�� ��ʹ��i��λ�ÿճ���
	            L->data[j+1] = L->data[j];
	        L->data[i] = x;//��Ԫ�ط����i��λ��
	        L->len++;//����1
	    }
}

/*ɾ������
��˳����е�i��Ԫ��ɾȥ*/
void Delete_SeqList(SeqList *L, int i)
{
	int j;
	if(L->len == 0)//�жϱ�Ϊ�� 
		printf("��Ϊ�գ�");
	else
		if(i<1 || i>L->len)//�ж�ɾ��λ�÷Ƿ�
			printf("ɾ��λ�÷Ƿ���");
		else
		{
			for(j=i+1;j<=L->len;j++)//��a[i+1]��a[n]��ǰ��һλ��a[i]�ͱ����ǵ��� 
				L->data[j-1] = L->data[j];
			L->len--;//����һ 
		 } 
} 

/*��������
���������ֵx��ȵ�Ԫ�أ��ҵ��ͷ����±꣬���򷵻�0*/
int Location_SeqList(SeqList *L, datatype x)
{
	int i=1;//�ӵ�һ��Ԫ�ؿ�ʼ���� 
	while(i<L->len && L->data[i]!=x)//˳���δ�������ҵ�ǰԪ�ز���Ҫ�ҵ�Ԫ�� 
		i++; 
	if(L->data[i]==x)//�ҵ��������±� 
		return i;
	else
		return 0;//δ�ҵ�����0 
} 

/*����˳���
��βԪ�ؽ���*/ 
void Coverts(SeqList *L)
{
	int i, n;
	datatype tmp;//��ʱ���� 
	n = L->len;
	for(i=1;i<=n/2;i++)//ֻ�ñ���ǰһ��Ԫ�أ���һ����Ȼ�ͽ����� 
	{
		tmp = L->data[i];
		L->data[i] = L->data[n-i+1];
		L->data[n-i+1] = tmp;
	}
} 

/*���������˳���ϲ�Ϊһ�������˳���*/
void Merge(SeqList *A, SeqList *B, SeqList *C)
{
	int i,j,k;
	i=j=k=1;
	if(A->len+B->len>=MAXSIZE)//�ϲ�֮��Ԫ�ظ������ܳ������Χ 
		printf("Ԫ�ظ���������Χ��");
	else
	{
		while(i<=A->len && j<=B->len)//��A��B��Ԫ����һ�Ƚϣ�ֱ����һ��˳����ѿ� 
			if(A->data[i]<B->data[j])
				C->data[k++] = A->data[i++];
			else
				C->data[k++] = B->data[j++];
		if(j<=B->len)//B����ʣ��Ԫ�أ���A�ȱ����꣬�ͽ�ָ��Aָ��B 
		{
			A = B;
			i = j;
		}
		while(i<=A->len)//��ʣ�µ�Ԫ��ֱ�Ӹ��Ƶ�C�� 
			C->data[k++] = A->data[i++];
		C->len = k-1;//���ñ� 
	}
} 

int main()
{
//    SeqList *L;
    //����һ��˳������
//    L = Init_SeqList();
//    CreatList(L);
//    Output_SeqList(L);
	
    //����Ԫ�غ����
//    Insert_SeqList(L,L->len,66);
//    Output_SeqList(L);
//    
    //ɾ��Ԫ��֮�����
//	Delete_SeqList(L,1);
//	Output_SeqList(L); 
	
	//����˳�������
//	Coverts(L);
//	Output_SeqList(L); 

	SeqList *A, *B, *C;
	A = Init_SeqList();
	B = Init_SeqList();
	C = Init_SeqList();
	CreatList(A);
	CreatList(B);
	Merge(A,B,C);
	Output_SeqList(C);
    return 0;
}


