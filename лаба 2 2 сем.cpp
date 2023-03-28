#include <iostream>

using namespace std;

// структура узла списка
struct Node {
    int data;
    Node* next;
};

// структура стека
struct Stack {
    Node* top;
    int size;
};

// инициализация стека
void init(Stack& s) {
    s.top = NULL;
    s.size = 0;
}

// добавление элемента в стек
void push(Stack& s, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = s.top;
    s.top = newNode;
    s.size++;
}

// удаление элемента из стека
void pop(Stack& s) {
    if (s.top == NULL) {
        cout << "Стек пуст!" << endl;
        return;
    }
    Node* temp = s.top;
    s.top = s.top->next;
    delete temp;
    s.size--;
}

// получение верхнего элемента стека
int top(Stack& s) {
    if (s.top == NULL) {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    return s.top->data;
}

// получение минимального значения в стеке
int getMin(Stack& s) {
    if (s.top == NULL) {
        cout << "Стек пуст!" << endl;
        return -1;
    }
    int minVal = s.top->data;
    Node* current = s.top->next;
    while (current != NULL) {
        if (current->data < minVal) {
            minVal = current->data;
        }
        current = current->next;
    }
    return minVal;
}

// перенос элементов из стека в новый стек
void moveElements(Stack& s, Stack& newStack, int minValue) {
    while (top(s) != minValue) {
        push(newStack, top(s));
        pop(s);
    }
    // удаляем элемент с минимальным значением
    pop(s);
}

int main() {
    setlocale(LC_ALL, "RU");
    Stack s;
    init(s);

    cout << "Введите элементы стека (для окончания ввода введите -1):" << endl;
    int input;
    cin >> input;
    while (input != -1) {
        push(s, input);
        cin >> input;
    }

    int minValue = getMin(s);
    cout << "Минимальное значение в стеке: " << minValue << endl;

    Stack newStack;
    init(newStack);

    moveElements(s, newStack, minValue);

    cout << "Элементы, перенесенные в новый стек:" << endl;
    while (newStack.top != NULL) {
        cout << top(newStack) << " ";
        pop(newStack);
    }
    cout << endl;

    return 0;
}
