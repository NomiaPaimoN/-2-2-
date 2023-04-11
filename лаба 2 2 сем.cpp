#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head, int data) {
    Node* node = new Node;
    node->data = data;
    node->next = *head;
    *head = node;
}

void pushBack(Node** head, int data) {
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

void printStack(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

Node* findMin(Node* head) {
    Node* current = head;
    Node* minNode = head;
    while (current != NULL) {
        if (current->data < minNode->data) {
            minNode = current;
        }
        current = current->next;
    }
    return minNode;
}

Node* copyStack(Node* head, Node* minNode) {
    Node* newHead = NULL;
    Node* current = head;
    while (current != minNode) {
        pushBack(&newHead, current->data);
        current = current->next;
    }
    return newHead;
}

int main() {
    Node* head = NULL;

    cout << "Enter stack values (enter -1 to stop): " << endl;
    int value;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        push(&head, value);
    }

    Node* minNode = findMin(head);
    Node* newHead = copyStack(head, minNode);

    cout << "Original stack: ";
    printStack(head);

    cout << "New stack: ";
    printStack(newHead);

    return 0;
}
