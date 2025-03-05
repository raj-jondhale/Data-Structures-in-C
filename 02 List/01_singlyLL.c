#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *start = NULL, *p, *q; // initialy linked list is empty
int loc;

void createatstart();
void traverse();
void createatend();
void createatlocation();
void deleteatstart();
void deleteatend();
void deleteatlocation();
int main()
{
    int ch;
    do
    {
        /* code */
        printf("\n\n1.Create at start\n2.create at end\n3.create at given location\n4.delete at start\n5.delete at end\n6.delete at given location\n7.Traverse\n8.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createatstart();
            break;

        case 2:

            createatend();
            break;
        case 3:
            createatlocation();
            /* code */

            break;
        case 4:
            /* code */
            deleteatstart();
            break;
        case 5:
            /* code */
            deleteatend();
            break;
        case 6:
            /* code */
            deleteatlocation();
            break;
        case 7:
            /* code */
            traverse();
            break;
        case 8:
            /* code */
            break;

        default:
            printf("incorrect choice");
            break;
        }
    } while (ch != 8);

    return 0;
}
void createatstart()
{
    // NODE *p;
    p = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter data element:");
    scanf("%d", &p->data);
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
    }
    else
    {
        p->next = start;
        start = p;
    }
}

void createatend()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("Enter data element:");
    scanf("%d", &p->data);
    if (start == NULL)
    {
        p->next = NULL;
        start = p;
    }
    else
    {
        q = start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
        p->next = NULL;
    }
}
void createatlocation()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("\nEnter data element:");
    scanf("%d", &p->data);
    printf("\nEnter location: ");
    scanf("%d", &loc);

    if (start == NULL)
    {
        if (loc <= 1)
        {
            p->next = NULL;
            start = p;
        }
        else
        {
            printf("\nInvalid location");
            free(p);
        }
    }
    else
    {
        if (loc == 1)
        {
            p->next = start;
            start = p;
        }
        else
        {
            int i = 1;
            q = start;
            while (i < loc - 1 && q != NULL)
            {
                q = q->next;
                i++;
            }
            if (q != NULL)
            {
                p->next = q->next;
                q->next = p;
            }
            else
            {
                printf("\nInvalid Location");
                free(p);
            }
        }
    }
}

void traverse()
{
    // NODE *q;
    if (start == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        q = start;
        while (q != NULL)
        {
            /* code */
            printf("%d ", q->data);
            q = q->next;
        }
    }
}

void deleteatstart()
{
    if (start == NULL)
    {
        printf("Delete can not be performed");
    }
    else
    {
        p = start;
        start = p->next;
        printf("Deleted node is : %d", p->data);
        free(p);
    }
}

void deleteatend()
{
    if (start == NULL)
    {
        printf("Delete can not be performed");
    }
    else if (start->next == NULL)
    {
        p = start;
        start = p->next;
        printf("Deleted node is : %d", p->data);
        free(p);
    }
    else
    {
        p = start;

        while (p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        printf("Deleted node is : %d", p->data);
        free(p);
    }
}

void deleteatlocation()
{
    // int loc;

    if (start == NULL)
    {
        printf("Delete can not be performed");
    }
    else
    {
        printf("Enter loc :");
        scanf("%d", &loc);
        if (loc == 1)
        {
            p = start;
            start->next = NULL;
            printf("Deleted node is : %d", p->data);
            free(p);
        }
        else
        {
            p = start;
            int i = 1;
            while (i < loc && p->next != NULL)
            {
                q = p;
                p = p->next;
                i++;
            }
            if (p != NULL)
            {
                q->next = p->next;
                printf("Deleted node is : %d", p->data);
                free(p);
            }
            else
            {
                printf("Invalid");
            }
        }
    }
}
