#include <iostream>
using namespace std;

//node data structure with ID , name and Status fields.
struct Node{
    int participantID;
    string name;
    string  registrationStatus;

    Node* next = NULL;
};

//linked list with required functions.
struct LinkedList{
    Node* head = NULL;
    //register new participants with its ID , name and status.
    void registerParticipants(int participantID, string name,string  registrationStatus){
        //check if the ID already exist.If so, print error message and return.
        Node* temp = head;
        while(temp!=NULL){
            if(temp->participantID==participantID){
                cout<<"Participant with same ID already exist!!!"<<endl;
                return;
            }
            temp=temp->next;
        }
        //If its a unique ID then create a new Node and fill its fields with the data provided by user. 
        Node* new_node = new Node;
        new_node->participantID = participantID;
        new_node->name = name;
        new_node->registrationStatus = registrationStatus;

        //Add the new Node to the Linkedlist.
        //IF its a First Node.
        if(head==NULL){
            head = new_node;
        }
        //IF its a second node or so on.
        else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    //Display all Participants added in the list for debug.
    void displayAllParticipants(){
        cout<<"____________________________________"<<endl;
        Node *temp = head;
        while (temp != NULL) {
            cout <<"ID : "<<temp->participantID<<"  ";
            cout <<"Name : "<<temp->name<<"  ";
            cout <<"Status : "<<temp->registrationStatus<<endl;
            temp = temp->next;
        }
        cout<<"____________________________________"<<endl;
    }

    //Update Registration Status function implemeted using ID.
    void updateRegistrationStatusByID(int participantID,string registrationStatus){
        Node* temp = head;
        bool isFound = false; //to check if ID not found after loop
        while(temp!=NULL){
            if(temp->participantID==participantID){
                cout<<"Updating "<<temp->name<<"`s status to "<<registrationStatus<<endl;
                temp->registrationStatus=registrationStatus;
                isFound = true; //ID found
            }
            temp=temp->next;
        }
        //ID not Found.
        if(isFound==false){
            cout<<"ID not found to Update the status"<<endl;
        }

    }
    //Remove all cancelled registrations.
    void removeCanceledRegistrations(){
        cout<<"Removing cancelled Registrations..."<<endl;
        //if its a head pointing to NULL, just return.
        if(head == NULL){
            return;
        }
        //if the head points to cancelled participant`s node.
        else if(head -> registrationStatus == "cancelled"){
            //loop until all the "cancelled participant`s nodes" come at the head place.
            while(head != NULL && head->registrationStatus == "cancelled"){
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        //for all other nodes.
        else{
            Node* current = head;
            Node* prev = head;

            while(current != NULL){
                if(current->registrationStatus=="cancelled"){
                    Node* temp = current;

                    prev->next = current->next;
                    current = current->next;

                    delete temp;
                }
                else{    
                    prev = current;
                    current = current->next;
                }
            }
            
        }
    }

    //All confirmed participants display function.
    void displayAllConfirmedParticipants(){
        cout<<"All Confirmed Participants are :"<<endl;
        
        Node *temp = head;
        while (temp != NULL) {
            if(temp->registrationStatus == "accepted"){
                cout <<"ID : "<<temp->participantID<<"  ";
                cout <<"Name : "<<temp->name<<"  ";
                cout <<"Status : "<<temp->registrationStatus<<endl;
               
            }
            temp = temp->next;
        }
    }

    //destructor for memory safety.
   ~LinkedList(){
    Node* temp = head;
    while(temp != NULL){
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}
    


};

int main(){
    LinkedList l1;
    l1.registerParticipants(94843,"Ahmad","pending");
    //Duplicate IDs : will not added.
    l1.registerParticipants(94843,"Ahmad","pending");

    l1.registerParticipants(27421,"Ali","cancelled");
    l1.registerParticipants(68344,"Talha","accepted");
    l1.registerParticipants(24783,"Zohaib","pending");
    l1.registerParticipants(24235,"Arslan","cancelled");

    l1.displayAllParticipants();

    l1.removeCanceledRegistrations();

    l1.displayAllParticipants();

    l1.updateRegistrationStatusByID(24783,"accepted");
    //ID not exist...
    l1.updateRegistrationStatusByID(000000,"peding");
    
    l1.displayAllParticipants();

    l1.displayAllConfirmedParticipants();

    return 0;
}