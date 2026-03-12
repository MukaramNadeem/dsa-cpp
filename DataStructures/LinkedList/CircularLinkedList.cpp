#include <iostream>
#include <stdexcept>
using namespace std;


struct Node{
    int data = 0;
    Node *next = NULL;
};

struct CircularLinkedList{
    Node *head = NULL;

    void insert_at_front(int val){
        //for 1st element
        if(head == NULL){
            Node *new_node = new Node;
            new_node->data = val;
            head = new_node;
            new_node ->next = head;
        }
        //for other elements
        else{
            Node *temp = head;
            while(temp->next != head){
                temp = temp->next;
            }
            Node *new_node = new Node;
            new_node->data = val;
            new_node->next = head;
            temp ->next = new_node;
            head = new_node;
        }
       
    }

    void insert_at_end(int val){
        //for 1st element same.
        if(head==NULL){
            Node *new_node = new Node;
            new_node-> data = val;
            
            head = new_node;
            new_node->next = head;
        }
        //for other elements
        else{
            Node *temp = head;
            while(temp->next!=head){
                temp = temp->next;
            }
            
            Node *new_node = new Node;
            new_node-> data = val;

            new_node -> next = head;
            temp->next = new_node;
        }
    }

    void delete_from_front(){
        if(head == NULL){
            throw invalid_argument("No node to Delete.");
        }
        else if(head->next == head){
            delete head;
            head = nullptr;
        }
        else{
            Node *p = head;
            Node *q = head;
            
            while (q->next!= head){
                q = q->next;
            }
            head = p->next;
            q->next = head;
            delete p;
        }
    }

    void delete_from_end(){
        if(head == NULL){
            throw invalid_argument("No node to Delete.");
        }

        else if(head -> next == head){
            delete head;
            head = nullptr;
        }

        else{
            Node *p = head;
            Node *q = head;
            while(p->next!=head){
                q = p;
                p = p->next;
            }
            q->next = head;
            delete p;
        }
    }

    void display(){
        if(head == NULL){
            cout << "List is empty." << endl; 
            return;
        }
        Node *temp = head;
        do{
            cout << temp->data << ' ';
            temp = temp->next;
        }while(temp != head);
        cout << endl;
    }
};



int main(){
    CircularLinkedList c1;
    c1.insert_at_end(2);
    c1.insert_at_end(3);
    c1.insert_at_front(1);
    c1.display();            
    c1.delete_from_front();
    c1.display();            
    c1.delete_from_end();
    c1.display();
    c1.insert_at_front(4);
    c1.display();    
    return 0;
}
