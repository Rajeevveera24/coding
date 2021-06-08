#include<stdio.h>
#include<malloc.h>

struct link{
    int coeff;
    int pow;
    struct link *next;
};

struct link *poly1=NULL,*poly2=NULL,*poly3=NULL,*poly4=NULL,*poly5=NULL;
void create(struct link *node)
{
    char ch[3];
    do
    {
        printf("enter coeff:\n");
        scanf("%d",&node->coeff);
        printf("enter power:\n");
        scanf("%d",&node->pow);
        node->next=(struct link*)malloc(sizeof(struct link));
        node=node->next;
        node->next=NULL;
        printf("continue(Yes/No):\n");
        scanf("%s",ch);
    }
    while(ch[0]=='y' || ch[0]=='Y');
}
void show(struct link *node)
{
    while(node->next!=NULL)
    {
        printf("%dx^%d",node->coeff,node->pow);
        node=node->next;
        if(node->next!=NULL)
        printf(" + ");
    }
    printf("\n");
}
void polyadd(struct link *poly1,struct link *poly2,struct link *poly)
{
    while(poly1->next &&  poly2->next)
    {
        if(poly1->pow>poly2->pow)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow)
        {
            poly->pow=poly2->pow;
            poly->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        else
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff+poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        poly->next=(struct link *)malloc(sizeof(struct link));
        poly=poly->next;
        poly->next=NULL;
    }
    while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        if(poly2->next)
        {
            poly->pow=poly2->pow;
            poly->coeff=poly2->coeff;
            poly2=poly2->next;
        }
        poly->next=(struct link *)malloc(sizeof(struct link));
        poly=poly->next;
        poly->next=NULL;
    }
}

void polysub(struct link *poly1,struct link *poly2,struct link *poly)
{
    while(poly1->next &&  poly2->next)
    {
        if(poly1->pow>poly2->pow)
        {
            poly->pow=poly1->pow;
            poly->coeff=poly1->coeff;
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow)
        {
            poly->pow=poly2->pow;
            poly->coeff= -(poly2->coeff);
            poly2=poly2->next;
        }
        else
        {
            poly->pow=poly1->pow;
            poly->coeff = poly1->coeff - poly2->coeff;
            poly1=poly1->next;
            poly2=poly2->next;
        }
        poly->next=(struct link *)malloc(sizeof(struct link));
        poly=poly->next;
        poly->next=NULL;
    }
    while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly->pow=poly1->pow;
            poly->coeff = poly1->coeff;
            poly1=poly1->next;
        }
        if(poly2->next)
        {
            poly->pow=poly2->pow;
            poly->coeff = -(poly2->coeff);
            poly2=poly2->next;
        }
        poly->next=(struct link *)malloc(sizeof(struct link));
        poly=poly->next;
        poly->next=NULL;
    }
}

void polymul(struct link *n1, struct link *n2, struct link **n)
{
    struct link * n2beg = n2;
    while (n1) 
    {
        struct link * temp=(struct link *)malloc(sizeof(struct link));
        temp->next=NULL;    
        n2 = n2beg;
        while (n2) 
        {
            temp->coeff = n1->coeff * n2->coeff;
            temp->pow = n1->pow + n2->pow;
            n2 = n2->next;
            temp->next=(struct link *)malloc(sizeof(struct link));
            temp=temp->next;
            temp->next=NULL;
        }
        polyadd(temp,*n,*n);
        n1 = n1->next;
        free(temp);
    }
}
int main()
{
    int op;
    char ch;
    poly1=(struct link *)malloc(sizeof(struct link));
    poly2=(struct link *)malloc(sizeof(struct link));
    poly3=(struct link *)malloc(sizeof(struct link));
    poly4=(struct link *)malloc(sizeof(struct link));
    poly5=(struct link *)malloc(sizeof(struct link));
    printf("Enter the first polynomial\n");
    create(poly1);
    printf("Enter the second polynomial\n");
    create(poly2);
    printf("Addition\t");
    polyadd(poly1,poly2,poly3);
    show(poly3);
    printf("Subtraction\t");
    polysub(poly1,poly2,poly4);
    show(poly4);
    printf("Multiplication\t");
    polymul(poly1,poly2,&poly5);
    show(poly5);
    return 0;
}