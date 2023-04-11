#include<iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
}*head;

Node* addNode(Node* head, int data) { // добавление доп элементов 
    Node* t = new Node;
    t->data = data;
    t->next = head;
    return t;
}

void ViewNode(Node* head) // просмотр элеметов
{
    Node* t = head;
    while (t != NULL) {
        cout << " " << t->data << endl;
        t = t->next;
    }

}

void Del_All(Node** head) { // удалить все элементы 
    Node* t = *head;
    while (*head != NULL) {
        t = *head;
        *head = (*head)->next;
        delete t;
    }
}

void Sort_p(Node** p) { // сортировка по указателю  
    Node* t = NULL, * t1, * r;
    *p = addNode(*p, 5);
    if ((*p)->next->next == NULL) return;
    do {
        for (t1 = *p; t1->next->next != t; t1 = t1->next)
            if (t1->next->data > t1->next->next->data) {
                r = t1->next->next;
                t1->next->next = r->next;
                r->next = t1->next;
                t1->next = r;
            }
        t = t1->next;
    } while ((*p)->next->next != t);
    t = *p;
    *p = (*p)->next;
    delete t;
}


void Sort_info(Node* p) { // вторая сортировка 
    Node* t = NULL, * t1;
    int r;
    do {
        for (t1 = p; t1->next != t; t1 = t1->next)
            if (t1->data > t1->next->data) {
                r = t1->data;
                t1->data = t1->next->data;
                t1->next->data = r;
            }
        t = t1;
    } while (p->next != t);
}

void removeMax(Node* head) {
    // Инициализируем переменную max_data первым элементом списка
    int max_value = head->data;

    // Находим максимальное значение в списке
    Node* current = head;
    while (current != nullptr) {
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }

    // Удаляем первый элемент со значением max_data
    current = head;
    if (current->data == max_value) {
        head = head->next;
        delete current;
        return;
    }

    // Удаляем остальные элементы со значением max_data
    while (current->next != nullptr) {
        if (current->next->data == max_value) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return;
        }
        current = current->next;
    }
}


int main() {
    int kod = 0, n = 0, numb = 0;
    while (true) {
        cout << "\n\tCreat - 1.\n\tAdd - 2.\n\tView - 3.\n\tDel - 4.\n\tSort - 5.\n\tSort - 6.\n\tDelMax - 7.\n\tEXIT - 0. : ";
        cin >> kod;
        switch (kod) {
        case 0: return 0;
        case 1:case 2:
        {
            if (kod == 1) Del_All(&head);
            cout << "How many?: ";
            cin >> n;
            for (int i = 1; i <= n; i++) {
                cin >> numb;
                head = addNode(head, numb);
            }
            break;
        }
        case 3:
        {
            ViewNode(head);
            break;
        }
        case 4:
        {
            Del_All(&head);
            break;
        }
        case 5:
        {
            Sort_info(head);
            break;
        }
        case 6:
        {
            Sort_p(&head);
            break;
        }
        case 7:
        {
            removeMax(head);
            break;
        }
        }
    }
}
