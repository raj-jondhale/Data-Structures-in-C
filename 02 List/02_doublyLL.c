#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
NODE *start = NULL, *p, *q;
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

            break;
        case 4:

            deleteatstart();
            break;
        case 5:

            deleteatend();
            break;
        case 6:

            deleteatlocation();
            break;
        case 7:

            traverse();
            break;
        case 8:

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
    p = (NODE *)malloc(sizeof(NODE));
    printf("Enter Data Element: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
        start = p;
    }
    else
    {
        p->next = start;
        start->prev = p;
        p->prev = NULL;
        start = p;
    }
}

void traverse()
{
    if (start == NULL)
    {
        printf("LL is empty");
    }
    else
    {
        q = start;
        while (q != NULL)
        {
            printf("%d ", q->data);
            q = q->next;
        }
    }
}

void createatend()
{
    p = (NODE *)malloc(sizeof(NODE));
    printf("Enter Data Element: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        p->next = NULL;
        p->prev = NULL;
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
        p->prev = q;
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
        if (loc == 1)
        {
            p->next = NULL;
            p->prev = NULL;
            start = p;
        }
        else
        {
            printf("\nInvalid");
            free(p);
        }
    }
    else
    {
        if (loc == 1)
        {
            p->next = NULL;
            p->prev = NULL;
            start = p;
        }
        else
        {
            q = start;
            int i = 1;
            while (i < loc - 1 && q != NULL)
            {
                q = q->next;
                i++;
            }
            if (q != NULL)
            {
                p->next = q->next;
                if (q->next != NULL)
                {
                    q->next->prev = p;
                }

                p->prev = q;
                q->next = p;
            }
            else
            {
                printf("\nInvalid");
                free(p);
            }
        }
    }
}

void deleteatstart()
{
    if (start == NULL)
    {
        printf("\nLL is empty.");
    }
    else
    {
        p = start;
        start = start->next;
        if (p->next != NULL)
        {
            p->next->prev = NULL;
        }
        printf("Deleted node is : %d", p->data);
        free(p);
    }
}
// void deleteatend()
// {
//     if (start == NULL)
//     {
//         printf("\nLL is empty");
//     }
//     else if (start->next == NULL)
//     {
//         p = start;
//         start = start->next;
//         p->next->prev = NULL;
//         printf("Deleted node is : %d", p->data);
//         free(p);
//     }
//     else
//     {
//         p = start;
//         while (p->next != NULL)
//         {
//             p = p->next;
//         }
//         q = p->prev;
//         q->next = NULL;
//         printf("Deleted node is : %d", p->data);
//         free(p);
//     }
// }

void deleteatend()
{
    if (start == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    if (start->next == NULL)
    {
        printf("Deleted node: %d\n", start->data);
        free(start);
        start = NULL;
        return;
    }

    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }

    q = p->prev;
    q->next = NULL;
    printf("Deleted node: %d\n", p->data);
    free(p);
}

void deleteatlocation()
{
    if (start == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Enter location: ");
    scanf("%d", &loc);

    if (loc == 1)
    {
        deleteatstart();
        return;
    }

    p = start;
    int i = 1;
    while (i < loc && p != NULL)
    {
        p = p->next;
        i++;
    }

    if (p == NULL)
    {
        printf("Invalid location\n");
        return;
    }

    if (p->next != NULL)
    {
        p->next->prev = p->prev;
    }

    if (p->prev != NULL)
    {
        p->prev->next = p->next;
    }

    printf("Deleted node: %d\n", p->data);
    free(p);
}