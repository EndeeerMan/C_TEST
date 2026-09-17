#include <stdlib.h>
#include <stdio.h>

#define ElemType int

typedef struct LNode
{
    ElemType data;       // 数据域
    struct LNode *next;  // 指向下一个结点
} LNode, *LinkList;

void LinkList_Init(LinkList *L)
{
    *L = (LinkList)malloc(sizeof(LNode));  // 分配头结点
    (*L)->data = 0;
    (*L)->next = NULL;
}

void List_HeadInsert(LinkList *L)
{
    LNode *s;
    int x = 0;
    scanf("%d",&x);

    while(x != -1){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = (*L)->next;
        (*L)->next = s;
        scanf("%d",&x);
    }
}

int main(){
    LinkList L;
    LinkList_Init(&L);

    List_HeadInsert(&L);

    LNode *p = L->next;
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }

    return 0;
}
