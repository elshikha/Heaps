#include <iostream>
using namespace std;
template<class T>
class Node{
public:
    Node(T info){
        this->info=info;
    }
    T info;
    Node* next{};
};

template<class T>
class Queue{

public:
    Node<T>* head{};
    Node<T>* tail{};
    int noe=0;//number of elements
    bool isEmpty(){
        return head==nullptr;
    }
    void enqueue(T val){
        Node<T> * ptr= new Node<T>(val);
        if(head==nullptr && tail==nullptr){
            head=tail=ptr;
            ptr->next=nullptr;
            noe++;
        }else{
            Node<T>* curr=head;
            while(curr->next != nullptr) curr=curr->next;
            curr->next=ptr;
            ptr->next=nullptr;
            tail=ptr;
            noe++;

        }
    }
    T dequeue(){
        if(head== nullptr){
            throw "the queue is empty";
        }
        else if(head==tail){
            T tmp=head->info;
            delete head;
            head = tail = nullptr;
        }else{
            T tmp=head->info;
            Node<T>* ptr=head;
            head=head->next;
            delete ptr;
            noe--;
            return tmp ;
        }
    }
    void print(){
        if(head==NULL){
            cout<<"Empty\n";
            return;
        }
        Node<T>* ptr=head;
        while(ptr != nullptr){
            cout<<ptr->info<<" ";
            ptr = ptr->next;
        }
    }
    T getHead(){
        return head->info;
    }
    T getTail(){
        return tail->info;
    }
    bool ifFound(T val){
        Node<T>* ptr=head;
        while(ptr != NULL){
            if(ptr->info==val)return true;
            ptr=ptr->next;
        }
        return false;
    }
    void clear(){
        while(!isEmpty())dequeue();
    }
};


int main() {
    
    return 0;
}
