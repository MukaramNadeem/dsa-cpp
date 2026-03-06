#include <iostream>
using namespace std;
#include <stdexcept>
#define Size 3

struct doublyCircularQueue{
    int queue[Size] = {};
    int rear = -1;
    int front = -1;

    void enqueue_at_rear(int val){
        //Overflow condition
        if(front == 0 && rear == Size-1 || rear==front-1){  // ` || rear==front-1 ` : extra condition for circular only!!!. 
            throw invalid_argument("Overflow");
        }
        //for first element
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            queue[rear] = val;
        }
        // to mkae it circular!!!
        else if(rear == Size-1 && front!=0){
            rear = 0;
            queue[rear] = val; 
        }
        //for other elements
        else{
            rear+=1;
            queue[rear] = val;
        }
    }


    int dequeue_at_front(){
        //empty
        if(front==-1 && rear==-1){
            throw invalid_argument("Underflow");
        }
        //if queue has only one element then it will become empty(front=rear=-1).
        else if(front==0 && rear==0 || front == rear){
            int val =  queue[front];
            queue[front] = 0;
            front = -1;
            rear = -1;
            return val;
        }
        //to make it circular!!!
        else if(front == Size-1){
            int val = queue[front];
            queue[front] = 0;
            front = 0;
            return val;
        }
        //for other elements
        else{
            int val = queue[front];
            queue[front] = 0;
            front+=1;
            return val;
        }
    }


    //////////////////////////////////////////////////////////////////////////////////////
    
    //for doubly enqueue_at_front() &&  dequeue_at_rear(). Both rear and front moves backward in both cases.
    
    //Add to the front of the queue
    void enqueue_at_front(int val){
        //Overflow condition will remian same.
        if(front == 0 && rear == Size-1 || rear==front-1){  // ` || rear==front-1 ` : extra condition for circular only!!!. 
            throw invalid_argument("Overflow");
        }
        //for first element
        else if(front == -1 && rear == -1){
            front = 0;
            rear = 0;
            queue[front] = val;
        }
        // to mkae it circular!!!     //Few more changes in rear!!!
        else if(front==0){            //change!!!
            front = Size-1;           //change!!!
            queue[front] = val; 
        }
        //for other elements
        else{
            front-=1;                                          //change!!!
            queue[front] = val;
        }
    }


    int dequeue_at_rear(){
        //empty
        if(front==-1 && rear==-1){
            throw invalid_argument("Underflow");
        }
        //if queue has only one element then it will become empty(front=rear=-1).
        else if(front==0 && rear==0 || front == rear){
            int val =  queue[rear];
            queue[rear] = 0;
            front = -1;
            rear = -1;
            return val;
        }
        //to make it circular!!!  Few more changes in rear!!! 
        else if(rear == 0){           //changed!!! 
            int val = queue[rear];
            queue[rear] = 0;
            rear = Size-1;            //changed!!!
            return val;
        }
        //for other elements
        else{
            int val = queue[rear];
            queue[rear] = 0;
            rear-=1;
            return val;
        }
    }

    void printQueue() {
        
        if (front == -1 && rear == -1) {
            cout << "Queue is empty." << endl;
            return;
        }
        
        if (front <= rear) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << "  ";
            }
        }

        else {
            for (int i = front; i < Size; i++) {
                cout << queue[i] << "  ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << "  ";
            }
        }
        cout << endl;
    }
};





int main() {
    doublyCircularQueue q;

    q.enqueue_at_rear(10);
    q.enqueue_at_rear(20);
    q.printQueue(); 

    // 2. Test Wrapped State from Rear (front > rear)
    q.enqueue_at_rear(30);  // Queue is full: [10, 20, 30]
    q.dequeue_at_front();   // Removes 10. Queue: [_, 20, 30], front=1, rear=2
    q.enqueue_at_rear(40);  // Wraps around. Queue: [40, 20, 30], front=1, rear=0
    
    q.printQueue();

    // 3. Test Wrapped State from Front (front > rear)
    q.dequeue_at_front();   // Removes 20
    q.dequeue_at_front();   // Removes 30
    q.dequeue_at_front();   // Removes 40. Queue is now empty.
    
    q.enqueue_at_front(99); // Queue: [99, _, _], front=0, rear=0
    q.enqueue_at_front(88); // Wraps around. Queue: [99, _, 88], front=2, rear=0
    
    q.printQueue();

    return 0;
}