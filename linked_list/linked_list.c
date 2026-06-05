#include <stdio.h>
#include <stdlib.h>
/*
A file to showcase a singly linked list
*/
typedef struct Node
{

    int value;
    struct Node *next;
} Node;

Node *initalise(int size)
{
    /*
    Summery:
        Initalise an array of given size with iterating value as default
    Example:
        >>> Node * n = initalise(int size)
        makes node lol
    */
    Node *head = (Node *)malloc(sizeof(Node));
    head->value = 0;

    Node *current = head;

    for (int i = 1; i <= size; i++)
    {
        // had to use AI to help with this conversion logic.
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->value = i;
        temp->next = NULL;

        current->next = temp;
        current = temp;
    }
    return head;
};

Node *read(Node *node)
{
    /*
    Summery:
        iterates through given nodes and prints their values
    Example:
        >>>read(nodes)
        Node: 1
        Node: 2
        ...
    */
    Node *current = node;
    while (current->next != NULL)
    {

        printf("Node: %d\n", current->value);
        current = current->next;
    }
    printf("Node: %d\n", current->value);
    return node;
};

Node *find(int target, Node *node)
{
    /*
    Summery:
        returns target node if it exists
    Example:
        >>> Node * n = initalise(10)
        >>> find(3, n)
        Found: 3
        >>> find(100, n)
        Errof: 100 not in node
    */
    Node *current = node;
    while (1)
    {
        if (current->value == target)
        {
            printf("Found: %d\n", current->value);
            return current;
        }
        current = current->next;
    }
    printf("Error: %d not in node", target);
    return NULL;
}

Node *delete(int target, Node *node)
{
    /*
    Summer:
        returns nodes with target excluded
    Example:
        >>> Node * n = initalise(4)
        >>> delete(2, n)
        0
        1
        3
        >>> delete(2, n)
        Error: 2 not in node
        */
    while (1)
    {
        if (node->value == target)
        {
            node->next = node->next->next;
            return node;
        }
        node = node->next;
    }
    printf("Error: %d not in node", target);
    return node;
}

Node *append(int val, Node *node)
{
    /*
    Summery:
        returns nodes with new value at the end
    Example:
        >>> Node * n = initalise(3)
        append(4, n);
        1
        2
        3
        4
        */
    Node *current = node;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;
    while (1)
    {
        current = current->next;
        if (current->next == NULL)
        {

            current->next = newNode;
            return current;
        }
    }
}

Node *insert(int val, int position, Node *node)
{
    /*
    summery:
        returns nodes with new value added in specific point
    Example:
        >>> Node * n = initalise(4)
        >>> insert(5, 1, n)
        1
        2
        3
        5
        4
    */
    Node *current = node;
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = NULL;
    int i = 0;
    while (1)
    {
        if (i == position - 1 || current->next == NULL)
        {
            Node *head = current;
            Node *tail = current->next;
            newNode->next = tail;
            current->next = newNode;
            return current;
        }
        current = current->next;
        i++;
    }
}

int main()
{
    int size = 10;
    Node *nodes = initalise(size);
    printf("--- Created Nodes ---\n");
    read(nodes);
    printf("--- Found Nodes ---\n");
    find(4, nodes);
    read(nodes);
    printf("--- Deleted Nodes ---\n");
    delete(3, nodes);
    size--;
    read(nodes);
    printf("--- Appended Nodes ---\n");
    append(12, nodes);
    read(nodes);
    printf("--- Insert Nodes ---\n");
    insert(13, 3, nodes);
    read(nodes);
    free(nodes);
    return 0;
}