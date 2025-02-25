#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};

struct node *START = NULL;

void DisplayList(struct node *start);

int main()
{
    struct node *temp, *ptr;
    int option = -1, data, index, i;

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
            DisplayList(START);
            break;

        case 2:
            printf("\nEnter Value: ");
            scanf("%d", &data);

            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = data;

            temp->next = START;
            START = temp;

            printf("\nInserted!");
            break;

        case 3:
            printf("\nEnter Location: ");
            scanf("%d", &index);

            printf("\nEnter Value: ");
            scanf("%d", &data);

            if (index <= 1)
            {
                printf("Index must be more than 1.");
            }
            else if (index > 1)
            {
                temp = (struct node *)malloc(sizeof(struct node));
                temp->data = data;

                ptr = START;
                i = 1;
                while (ptr != NULL && i < index - 1)
                {
                    ptr = ptr->next;
                    i++;
                }

                if (ptr == NULL)
                {
                    printf("Index out of bound.");
                }
                else
                {
                    temp->next = ptr->next;
                    ptr->next = temp;
                }
            }
            break;

        case 4:
            printf("\nEnter Value: ");
            scanf("%d", &data);

            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = data;
            temp->next = NULL;

            if (START == NULL)
            {
                START = temp;
            }
            else
            {
                ptr = START;
                while (ptr != NULL && ptr->next != NULL)
                {
                    ptr = ptr->next;
                }

                ptr->next = temp;
            }

            break;

        case 5:
            if (START != NULL)
            {
                ptr = START;
                START = START->next;
                ptr = NULL;
                free(ptr);
            }
            break;

        case 6:
            printf("\nEnter Location: ");
            scanf("%d", &index);

            i = 1;
            ptr = START;
            while (ptr != NULL && i < index - 1)
            {
                ptr = ptr->next;
                i++;
            }

            if (ptr == NULL)
            {
            }
            else
            {
                struct node *tempPtr = ptr->next;

                ptr->next = tempPtr->next;
                tempPtr->next = NULL;
            }

            break;

        case 7:
            if (START != NULL)
            {
                if (START->next == NULL)
                {
                    START = NULL;
                }
                else
                {
                    ptr = START;
                    while (ptr->next->next != NULL)
                    {
                        ptr = ptr->next;
                    }

                    ptr->next = NULL;
                }
            }
            break;
        }
    } while (option != 0);

    return 0;
}

void DisplayList(struct node *start)
{
    if (start == NULL)
    {
        printf("\nList is EMPTY!!");
    }
    else
    {
        printf("\nList : ");
        while (start != NULL)
        {
            printf("%d ", start->data);
            start = start->next;
        }
    }
}