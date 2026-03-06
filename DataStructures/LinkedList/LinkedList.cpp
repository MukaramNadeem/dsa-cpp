#include <iostream>
using namespace std;

struct Node {
  int data = 0;
  Node *next = NULL;
};

struct LinkedList {

  Node *head = NULL;

  void insert_at_front(int val) {
    Node *new_node = new Node;
    new_node->data = val;
    // for 1st element.
    if (head == NULL) {
      head = new_node;
    }
    // for other elements.
    else {
      new_node->next = head;
      head = new_node;
    }
  }

  void insert_at_end(int val) {
    Node *new_node = new Node;
    new_node->data = val;
    // for 1st element
    if (head == NULL) {
      head = new_node;
    }
    // for other elements
    else {
      Node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = new_node;
    }
  }

  void insert_at_SpecifiedPosition(int position, int val) {
    // sanity check
    if (head == NULL) {
      return;
    } else {
      Node *temp = head;
      while (temp != NULL) {
        if (temp->data == position) {
          Node *new_node = new Node;
          new_node->data = val;

          new_node->next = temp->next;
          temp->next = new_node;
        }
        temp = temp->next;
      }
    }
  }

  void display() {
    Node *temp = head;
    while (temp != NULL) {
      cout << temp->data << ' ';
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList l1;
  l1.insert_at_end(5);
  l1.insert_at_end(10);
  l1.insert_at_end(15);
  l1.insert_at_SpecifiedPosition(10, 44);
  l1.display();

  return 0;
}

// node *p;
// p = (Struct node*)malloc(sizeof(Struct node))
