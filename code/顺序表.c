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
    datatype data[MAXSIZE];//存储顺序表中的元素
    int len;//顺序表的表长
}SeqList;//顺序表类型

/*输出顺序表*/
void Output_SeqList(SeqList *L)
{
    int i;
    for(i=1;i<=L->len;i++)
        printf("%d\t",L->data[i]);
    printf("\n");
}

/*顺序表的初始化
构造空表，分配顺序表的存储空间，设表长为0*/
SeqList *Init_SeqList()
{
    SeqList *L;//定义顺序表指针变量
    L = (SeqList*)malloc(sizeof(SeqList));//给顺序表分配存储空间，sizeof函数返回类型所占的字节数
    L->len = 0;//表长设置为0
    return L;//返回顺序表指针
}

/*建立顺序表
输入顺序表的长度n和n个元素即可建立顺序表*/
void CreatList(SeqList *L)
{
    int i,n;
    printf("输入顺序表的长度：");
    scanf("%d",&n);//输入顺序表的表长n
    printf("输入顺序表元素");
    for(i=1;i<=n;i++)
        scanf("%d",&(L->data[i]));//依次输入n个元素
    L->len = n;//设置表长
}

/*插入运算
在顺序表的第i个位置插入新元素x*/
void Insert_SeqList(SeqList *L, int i, datatype x)
{
    int j;
    if(L->len == MAXSIZE)//判断表满
        printf("表满！");
    else
	    if(i<1 || i>L->len+1)//判断插入位置非法
	        printf("插入位置非法！");
	    else
	    {
	    	
	        for(j=L->len;j>=i;j--)//将a[i]到a[n]顺序后移一个位置 ，使第i个位置空出来
	            L->data[j+1] = L->data[j];
	        L->data[i] = x;//新元素放入第i个位置
	        L->len++;//表长加1
	    }
}

/*删除运算
将顺序表中第i个元素删去*/
void Delete_SeqList(SeqList *L, int i)
{
	int j;
	if(L->len == 0)//判断表为空 
		printf("表为空！");
	else
		if(i<1 || i>L->len)//判断删除位置非法
			printf("删除位置非法！");
		else
		{
			for(j=i+1;j<=L->len;j++)//将a[i+1]到a[n]向前移一位，a[i]就被覆盖掉了 
				L->data[j-1] = L->data[j];
			L->len--;//表长减一 
		 } 
} 

/*查找运算
查找与给定值x相等的元素，找到就返回下标，否则返回0*/
int Location_SeqList(SeqList *L, datatype x)
{
	int i=1;//从第一个元素开始查找 
	while(i<L->len && L->data[i]!=x)//顺序表未查找完且当前元素不是要找的元素 
		i++; 
	if(L->data[i]==x)//找到返回其下标 
		return i;
	else
		return 0;//未找到返回0 
} 

/*逆置顺序表
首尾元素交换*/ 
void Coverts(SeqList *L)
{
	int i, n;
	datatype tmp;//临时变量 
	n = L->len;
	for(i=1;i<=n/2;i++)//只用遍历前一半元素，后一半自然就交换了 
	{
		tmp = L->data[i];
		L->data[i] = L->data[n-i+1];
		L->data[n-i+1] = tmp;
	}
} 

/*两个有序的顺序表合并为一个有序的顺序表*/
void Merge(SeqList *A, SeqList *B, SeqList *C)
{
	int i,j,k;
	i=j=k=1;
	if(A->len+B->len>=MAXSIZE)//合并之后元素个数不能超出最大范围 
		printf("元素个数超出范围！");
	else
	{
		while(i<=A->len && j<=B->len)//将A和B中元素逐一比较，直到有一个顺序表已空 
			if(A->data[i]<B->data[j])
				C->data[k++] = A->data[i++];
			else
				C->data[k++] = B->data[j++];
		if(j<=B->len)//B中有剩余元素，即A先遍历完，就将指针A指向B 
		{
			A = B;
			i = j;
		}
		while(i<=A->len)//将剩下的元素直接复制到C中 
			C->data[k++] = A->data[i++];
		C->len = k-1;//设置表长 
	}
} 

int main()
{
//    SeqList *L;
    //创建一个顺序表并输出
//    L = Init_SeqList();
//    CreatList(L);
//    Output_SeqList(L);
	
    //插入元素后输出
//    Insert_SeqList(L,L->len,66);
//    Output_SeqList(L);
//    
    //删除元素之后输出
//	Delete_SeqList(L,1);
//	Output_SeqList(L); 
	
	//逆置顺序表后输出
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


