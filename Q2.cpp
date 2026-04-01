#include <iostream>
using namespace std;

// Define Node class
class Node
{
public:
    int data;
    Node* next;

    // Constructor
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Function to insert node at end
void insert(Node*& head, int value)
{
    Node* newNode = new Node(value);

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        newNode->next = head; // Point to itself (circular)
        return;
    }

    Node* temp = head;

    // Traverse to last node
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head; // Make circular
}

// Function to display circular linked list
void display(Node* head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    cout << "Circular Linked List: ";

    // Traverse until we reach head again
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(back to head)" << endl;
}

int main()
{
    Node* head = NULL;

    // Insert values
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    // Display list
    display(head);

    return 0;
}
