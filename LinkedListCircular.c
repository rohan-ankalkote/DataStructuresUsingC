#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *START = NULL;

void DisplayCircularLinkedList(struct node *);
struct node *InsertNodeAtStart(struct node *, int);
struct node *InsertNodeAtLocation(struct node *, int, int);
struct node *InsertNodeAtEnd(struct node *, int);
struct node *DeleteNodeAtStart(struct node *);
struct node *DeleteNodeAtLocation(struct node *, int);
struct node *DeleteNodeAtEnd(struct node *);

int main()
{
    int option, data, loc;

    do
    {
        printf("\n==================================================");
        printf("\n0) Exit");
        printf("\n1) Display List");
        printf("\n2) Insert Node At Start");
        printf("\n3) Insert Node At Location");
        printf("\n4) Insert Node At End");
        printf("\n5) Delete Node At Start");
        printf("\n6) Delete Node At Location");
        printf("\n7) Delete Node At End");
        printf("\n==================================================");
        printf("\nSelect option : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            DisplayCircularLinkedList(START);
            break;
        case 2:
            printf("Enter the element to insert: ");
            scanf("%d", &data);

            START = InsertNodeAtStart(START, data);
            break;

        case 3:
            printf("Enter the element to insert :");
            scanf("%d", &data);

            printf("\nEnter the location : ");
            scanf("%d", &loc);

            START = InsertNodeAtLocation(START, data, loc);
            break;

        case 4:
            printf("Enter the element to insert: ");
            scanf("%d", &data);

            START = InsertNodeAtEnd(START, data);
            break;
        case 5:
            START = DeleteNodeAtStart(START);
            break;
        case 6:
            printf("\nEnter location: ");
            scanf("%d", &loc);

            START = DeleteNodeAtLocation(START, loc);
            break;
        case 7:
            START = DeleteNodeAtEnd(START);
            break;
        }
    } while (option != 0);

    return 0;
}

// Traverse til end
// new node points to existing first node
// start points to new node
// Last points to new start
struct node *InsertNodeAtStart(struct node *start, int data)
{
    struct node *ptr = start;
    struct node *temp = (struct node *)malloc(sizeof(struct node *));
    temp->data = data;

    if (start == NULL)
    {
        start = temp;
        temp->next = start;

        return start;
    }

    while (ptr->next != start)
    {
        ptr = ptr->next;
    }

    temp->next = start;
    start = temp;
    ptr->next = start;

    return start;
}

// Traverse till end
// New node points to start
// Last node points to new node.
struct node *InsertNodeAtEnd(struct node *start, int data)
{
    struct node *ptr = start, *temp = (struct node *)malloc(sizeof(struct node *));

    temp->data = data;

    if (start == NULL)
    {
        start = temp;
        temp->next = start;

        return start;
    }

    while (ptr->next != start)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;

    return start;
}

// Traverse till the element before location
// New node points to next node of ptr
// ptr points to new node.
struct node *InsertNodeAtLocation(struct node *start, int data, int location)
{
    if (location < 1)
    {
        printf("Cannot insert at this location");
        return start;
    }

    if (location == 1)
    {
        return InsertNodeAtStart(start, data);
    }

    if (start == NULL)
    {
        printf("Cannot insert at this location");
        return start;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node *)), *ptr = start;
    temp->data = data;
    int i = 1;

    while (i < location - 1)
    {
        ptr = ptr->next;
        i++;
    }

    temp->next = ptr->next;
    ptr->next = temp;

    return start;
}

// If only one element, make it null.
// Tranverse till last
// Increment start and point last element to new start.
struct node *DeleteNodeAtStart(struct node *start)
{
    if (start == NULL)
    {
        printf("\nList is Empty!!");
        return start;
    }

    struct node *ptr = start, *freePtr = start;

    if (ptr->next == start)
    {
        start = NULL;
        free(ptr);
        return start;
    }

    while (ptr->next != start)
        ptr = ptr->next;

    start = start->next;
    ptr->next = start;

    free(freePtr);

    return start;
}

// Traverse till the location with prepointer
// Make prePointer point to next node of current pointer.
struct node *DeleteNodeAtLocation(struct node *start, int location)
{
    if (start == NULL)
    {
        printf("\nCannot delete");
        return start;
    }

    if (location == 1)
    {
        return DeleteNodeAtStart(start);
    }

    struct node *prePtr = start, *ptr = start;
    int i = 1;

    while (i < location)
    {
        i++;
        prePtr = ptr;
        ptr = ptr->next;
    }

    prePtr->next = ptr->next;

    free(ptr);

    return start;
}

// Traverse tii last second
// Make this element point to next of next element.
struct node *DeleteNodeAtEnd(struct node *start)
{
    if (start == NULL)
    {
        printf("\nList is Empty!!");
        return start;
    }

    struct node *ptr = start, *freePtr;

    while (ptr->next->next != start)
    {
        ptr = ptr->next;
    }

    freePtr = ptr->next;

    ptr->next = freePtr->next;

    free(freePtr);

    return start;
}

void DisplayCircularLinkedList(struct node *start)
{
    struct node *ptr = start;

    if (start == NULL)
    {
        printf("\nList is Empty!");
    }
    else
    {
        printf("\nElements : ");

        do
        {
            printf("%d ", ptr->data);

            ptr = ptr->next;
        } while (ptr != start);
    }
}