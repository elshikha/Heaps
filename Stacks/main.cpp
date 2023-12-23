#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Node{
public:
    T info;
    Node* next{};
    Node(T val = T()) : info(val) {}
    ~Node() {
        delete next;
    }
};

template <class T>
class Stack{
private:
    Node<T> *Top{};
    int capacity;
    int numOfElements;
public:
    Stack(int val = 0) : capacity(val), numOfElements(0) {}
    bool isEmpty() {
        return Top == nullptr;
    }

    void push(T val) {
        Node<T> *ptr = new Node<T>(val);
        if (Top == nullptr) {
            Top = ptr;
        } else {
            ptr->next = Top;
            Top = ptr;
        }
        numOfElements++;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return T();
        }

        Node<T> *ptr = Top->next;
        T tmp = Top->info;
        Top->next = nullptr;
        delete Top;
        Top = ptr;
        numOfElements--;
        return tmp;
    }

    T top() {
        if (isEmpty()) {
            cout << "Error: Stack is empty" << endl;
            return T();
        }
        return Top->info;
    }

    void display() {
        Node<T> *ptr = Top;
        while (ptr != nullptr) {
            cout << ptr->info << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};
bool prck(char first , char last){
    if (first == '{' && last == '}') {
        return true;
    } else if (first == '[' && last == ']')return true;
    else if (first == '(' && last == ')')return true;
    return false;
}

bool Balanced(string exp){
    Stack<char> stack;
    for(int i =0 ;i <exp.length();i++){
        if(exp[i]=='[' || exp[i]=='{' || exp[i]=='('){
            stack.push(exp[i]);
        }
        else if (exp[i]==']' || exp[i]=='}' || exp[i]==')'){
            if(stack.isEmpty())return false;
            else if(!(prck(stack.top(),exp[i]))){
                return false;
            }
            stack.pop();
        }
    }
    return stack.isEmpty();
}

int main() {
     
    if(Balanced("(){}{}()()()()()(){}[][][][]"))
        cout<<"Valid";
    else
        cout<<"Invalid";
    return 0;
}
