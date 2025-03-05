//{ Driver Code Starts
// Initial Template for C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for linked list nodes
struct node
{
    int data;
    NODE *next;
};
typedef struct node NODE;
// Function to create a new node
NODE *newNode(int data)
{
    NODE *node = (NODE *)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(NODE *head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n~\n");
}

// Function to insert a node in a sorted manner
NODE *insertSorted(NODE *head, int data)
{
    NODE *new_node = newNode(data);
    if (!head || head->data >= data)
    {
        new_node->next = head;
        return new_node;
    }

    NODE *current = head;
    while (current->next && current->next->data < data)
    {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}

// } Driver Code Ends

// User function Template for C

NODE *sortedMerge(NODE *head1, NODE *head2)
{
    // code here
    NODE *p = head1;
    NODE *q = head2;
    NODE *dummy = (NODE *)malloc(sizeof(NODE));
    NODE *start = dummy;
    while (p != NULL && q != NULL)
    {
        if (p->data < q->data)
        {
            dummy->next = p;
            p = p->next;
        }
        else
        {
            dummy->next = q;
            q = q->next;
        }
        dummy = dummy->next;
    }
    if (p != NULL)
    {
        dummy->next = p;
    }
    if (q != NULL)
    {
        dummy->next = q;
    }
    return start->next;
}

//{ Driver Code Starts.

// Driver program to test the above functions
int main()
{
    int T;
    scanf("%d", &T);
    getchar(); // To consume newline after reading T
    while (T--)
    {
        int n1, n2, tmp;
        NODE *head1 = NULL, *head2 = NULL;
        char input1[100001], input2[100001];

        fgets(input1, 100001, stdin); // Read the entire line for the LL1 elements
        char *token = strtok(input1, " ");
        while (token)
        {
            sscanf(token, "%d", &tmp);
            head1 = insertSorted(head1, tmp);
            token = strtok(NULL, " ");
        }

        fgets(input2, 100001, stdin); // Read the entire line for the LL2 elements
        token = strtok(input2, " ");
        while (token)
        {
            sscanf(token, "%d", &tmp);
            head2 = insertSorted(head2, tmp);
            token = strtok(NULL, " ");
        }

        NODE *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends