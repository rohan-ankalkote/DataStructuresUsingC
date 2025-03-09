#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    struct Node *previous;
    struct Node *next;
};

class DoubleLinkedList
{
private:
    Node *start;

public:
    DoubleLinkedList()
    {
        start = NULL;
    }

    void DisplayList()
    {
        if (start == NULL)
        {
            cout << "\nList is Empty!";
            return;
        }

        printf("\nList : ");

        Node *ptr = start;

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }

    void DisplayListReverse()
    {
        if (start == NULL)
        {
            cout << "\nList is Empty!";
            return;
        }

        cout << "\nList : ";
        Node *ptr = start;

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->previous;
        }
    }

    // Previous of start points to new node.
    // New node points to start
    // Start points to its previous (new node).
    void InsertNodeAtStart(int data)
    {
        Node *temp = new Node();
        temp->data = data;
        temp->next = NULL;
        temp->previous = NULL;

        if (start == NULL)
        {
            start = temp;
            return;
        }

        start->previous = temp;
        temp->next = start;
        start = start->previous;
    }

    // Traverse till end
    // Last node points to new node.
    // New nodes previous points to last node.
    void InsertNodeAtEnd(int data)
    {
        Node *temp = new Node(), *ptr = start;
        temp->data = data;
        temp->previous = temp->next = NULL;

        if (start == NULL)
        {
            start = temp;
            return;
        }

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = temp;
        temp->previous = ptr;
        return;
    }

    // Traverse till one element before the location.
    // New node points to next node.
    // New nodes previous points to current node.
    // Next nodes previous points to new node.
    // Current node points to new node.
    void InsertAtLocation(int location, int data)
    {
        Node *temp = new Node(), *ptr = start;
        temp->data = data;
        temp->previous = temp->next = NULL;
        int i = 1;

        if (location == 1)
        {
            return InsertNodeAtStart(data);
        }

        if (location < 1 || start == NULL)
        {
            cout << "\nCannot insert at this location.";
        }

        while (i < location - 1)
        {
            ptr = ptr->next;
            i++;
        }

        temp->next = ptr->next;
        temp->previous = ptr;
        temp->next->previous = temp;
        ptr->next = temp;

        return;
    }

    // Move start to next
    // Make starts previous as NULL
    void DeleteNodeAtStart()
    {
        Node *ptr = start;

        if (start == NULL)
        {
            cout << "\nList is Empty!!";
        }

        start = start->next;
        start->previous = NULL;

        free(ptr);

        return;
    }

    // Traverse till last node.
    // Make second last nodes next as NULL
    void DeleteNodeAtEnd()
    {
        Node *ptr = start;

        if (start == NULL)
        {
            cout << "\nList is Empty!!";
        }

        if (ptr->next == NULL)
        {
            start = NULL;
            free(ptr);
            return;
        }

        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->previous->next = NULL;

        free(ptr);
        return;
    }

    // Traverse at the location.
    // Make previous node point to next node.
    // Make next nodes previous point to previous.
    void DeleteNodeAtLocation(int location)
    {
        Node *ptr = start;

        if (location == 1)
        {
            return DeleteNodeAtStart();
        }

        if (location < 1 || start == NULL)
        {
            cout << "\nCannot delete";
        }

        int i = 1;
        while (i < location)
        {
            if (ptr == NULL)
                return;

            ptr = ptr->next;
            i++;
        }

        ptr->previous->next = ptr->next;

        if (ptr->next != NULL)
            ptr->next->previous = ptr->previous;

        free(ptr);
        return;
    }
};

int main()
{
    int option, data, location;
    DoubleLinkedList doubleLinkedList;

    do
    {
        cout << "\n==================================================";
        cout << "\n0) Exit";
        cout << "\n1) Display List";
        cout << "\n2) Display List Reverse";
        cout << "\n3) Insert Node At Start";
        cout << "\n4) Insert Node At Location";
        cout << "\n5) Insert Node At End";
        cout << "\n6) Delete Node At Start";
        cout << "\n7) Delete Node At Location";
        cout << "\n8) Delete Node At End";
        cout << "\n9) Create a linked list.";
        cout << "\n==================================================";
        cout << "\nSelect option : ";
        cin >> option;

        switch (option)
        {
        case 1:
            doubleLinkedList.DisplayList();
            break;

        case 2:
            doubleLinkedList.DisplayListReverse();
            break;

        case 3:
            cout << "\nEnter the elemnent to insert: ";
            cin >> data;

            doubleLinkedList.InsertNodeAtStart(data);
            break;

        case 4:
            cout << "\nEnter the element to insert: ";
            cin >> data;

            cout << "\nEnter the location : ";
            cin >> location;

            doubleLinkedList.InsertAtLocation(location, data);
            break;

        case 5:
            cout << "\nEnter the element to insert: ";
            cin >> data;
            doubleLinkedList.InsertNodeAtEnd(data);
            break;

        case 6:
            doubleLinkedList.DeleteNodeAtStart();
            break;

        case 7:
            cout << "\nEnter location : ";
            cin >> location;
            doubleLinkedList.DeleteNodeAtLocation(location);
            break;

        case 8:
            doubleLinkedList.DeleteNodeAtEnd();
            break;

        case 9:
            cout << "\nEnter element count :";
            cin >> location;
            data = 1;
            while (data <= location)
            {
                doubleLinkedList.InsertNodeAtEnd(data * 10);
                data++;
            }
            break;
        }
    } while (option != 0);
    return 0;
}