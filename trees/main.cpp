#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Node {
public:
    T info;
    Node<T>* right;
    Node<T>* left;

    Node(T info, Node<T>* right = nullptr, Node<T>* left = nullptr) : info(info), right(right), left(left) {}
};

template <class T>
class BST {
private:
    Node<T>* root;

public:
    bool isEmpty(){return root == nullptr;}
    Node<T>* insert(Node<T>* Root, T value) {
        if (Root == nullptr) {
            Root = new Node<T>(value);
        } else if (value < Root->info) {  // insert to left
            Root->left = insert(Root->left, value);
        } else {  // insert to right
            Root->right = insert(Root->right, value);
        }
        return Root;
    }

    void insert(T val) {
        root = insert(root, val);
    }

    void display(Node<T>* Root) {
        if (Root == nullptr)
            return;
        cout << Root->info << "\t";
        display(Root->left);
        display(Root->right);
    }

    void display() {
        display(root);
    }

    Node<T>* search(Node<T>* Root , T key)
    {
        if(Root== nullptr)return nullptr;
        else if (Root->info == key)return Root;
        else if(key<Root->info)
        {
            return search(Root->left,key);
        }
        else
        {
            return search(Root->right,key);
        }
    }
    bool search(T key){
        Node<T> * res= search(root,key);
        if (res != nullptr)return true;
        else
        {
            insert(key);
            return false;
        }
    }
    Node<T>* FindMin(Node<T>* Root){
        if(!Root)return nullptr;
        else if ( !(Root ->left))return Root;
        else return FindMin(Root->left);
    }
    Node<T>* FindMax(Node<T>* Root){
        if(!Root)return nullptr;
        else if ( !(Root ->right))return Root;
        else return FindMax(Root->right);
    }
    Node<T>* DeleteLeaf(Node<T>* Root, T val, Node<T>* prv = nullptr) {
        if (Root == nullptr) {
            return nullptr;
        }

        if (Root->info == val && Root->left == nullptr && Root->right == nullptr) {
            // Found a leaf node to delete
            if (prv) {
                if (prv->left == Root) {
                    delete prv->left;
                    prv->left = nullptr;
                } else {
                    delete prv->right;
                    prv->right = nullptr;
                }
            } else {
                delete Root;
                Root = nullptr;
            }
            return nullptr;  // Return nullptr as the current node is deleted
        }

        if (val < Root->info) {
            Root->left = DeleteLeaf(Root->left, val, Root);
        } else if (val > Root->info) {
            Root->right = DeleteLeaf(Root->right, val, Root);
        }

        return Root;
    }

    void DeleteLeaf(T val) {
        Node<T>* test = DeleteLeaf(root, val);
        if (test) {
            cout << "Node found but not a leaf.\n";
        } else {
            cout << "Node deleted if it was a leaf.\n";
        }
    }
    void Traverse(){
        queue<Node<T>*> q;
        q.push(root);
        while (!q.empty()) {
            Node<T>* temp = q.front();
            q.pop();
            cout << temp->info << " ";

            if (temp->left != nullptr)
                q.push(temp->left);

            if (temp->right != nullptr)
                q.push(temp->right);
        }
    }

};




int main() {
    BST<int> Tree{};
    Tree.insert(6);
    Tree.insert(5);
    Tree.insert(8);
    Tree.insert(9);
    Tree.insert(10);
    Tree.display();
    Tree.DeleteLeaf(4);
    cout<<"\n";
    Tree.display();
    cout<<"\n";
    Tree.Traverse();
    return 0;
}
