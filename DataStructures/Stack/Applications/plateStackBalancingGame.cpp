#include <iostream>
using namespace std;
#include <vector>
#define Size 50 //enough for 5 players increase if needed...


// basic old stack
struct Stack{
   int top = -1;
   int stack[Size] = {0};


   // push function
   void push(int val){
       // Overflow condition.
       if (top >= Size - 1){
           throw invalid_argument("Overflow");
       }
       else{
           top++;
           stack[top] = val;
       }
   }


   // pop function
   int pop(){
       // Underflow condition.
       if (top == -1){
           cout << "Cannot pop. The stack is already empty!" << endl;
           return 0;
       }
       else{
           int temp = stack[top];
           stack[top] = 0;
           top--;
           return temp;
       }
   }


   // peek function
   int peek(){
       // empty stack condition.
       if (top == -1){
           return 0;
       }
       else{
           return stack[top];
       }
   }


   // print Stack Function.
   void print(){
       cout << "_________________________" << endl;
       cout << "Stack" << endl;
       for (int i = 0; i <= top; i++){
           cout << stack[i] << "  ";
       }
       cout<<endl;
       // Number of plates display.
       cout << "Number of Plates : " << top + 1 << endl;
       cout << "_________________________" << endl;
   }
};






// Print Scores of all playes.
void printScores(vector<int> &scores){
   cout << "_________________________" << endl;
   cout << "Scores" << endl;
   for (int i = 0; i < scores.size(); i++){
       cout <<"Player "<<i+1<<" score is : " << scores[i] <<".   ";
   }
   cout <<endl;
}








int main(){
   // Stack object.
   Stack s1;
   // input number of players
   int numberOfPlayers;
   cout << "Enter Number of Players : ";
   cin >> numberOfPlayers;


   // store the scores of players in a vector array of size ==`numberOfPlayers`.
   vector<int> scores(numberOfPlayers, 0);
  
   //outer loop for 10 attempts of each player
   for (int j = 0; j < 10; j++){
      
       int playerNumber = 1;
      
       //inner loop for each turn of all the total number of players.
       for (int i = 0; i < numberOfPlayers; i++){
           int val = 0;
           //Input from the player.
           cout << "______________________________________________________" << endl;
           cout << "Player " << playerNumber << " turn" << endl;
           cout << "Stack Top value is : " << s1.peek() << endl;
           cout << "Enter a value to push.Otherwise, Enter 0 to pop  a value : ";
           cin >> val;


           //player choose to pop().
           if(val == 0){
               if(s1.pop() != 0){
                   scores[i] -= 1;// score of that player will be reduced by 1.
               }
           }


           //player choose to push().
           if (val > 0){
               if (s1.top == -1 || val <= s1.peek()){
                   s1.push(val);
                   scores[i] += 2; // score of that player will be increased by 2.
               }
               //If a heavier plate is placed on a lighter one.
               else{
                   cout << "Pushed Weight is greater than the stack`s top value!!! " << endl;
                  
                   cout << "Total Scores of all players : "<<endl;
                   printScores(scores);
                   cout << "Total Number of Plates : " << s1.top + 1 << endl;
                  
                   exit(0);//game ends
               }
           }
          
           playerNumber++;


           printScores(scores);
          
           //winning condition check!!!
           for (int k = 0; k < numberOfPlayers; k++){
               if (scores[k] >= 10){     //if 5 plates are placed by a player than his/her score will be 10 or greater. Ultimately he/she will win.
                  
                   cout << "Player : " << k + 1 << " Win!!!" << endl; //thus that player with `k+1` index in the scores array will win the game.
                   cout << "Total Scores of all players" << endl;
                   printScores(scores);
                   cout << "Total Number of Plates : " << s1.top + 1 << endl;
                   exit(0);
               }
           }
       }
       //print stack at the end of inner loop.
       s1.print();
   }
   return 0;
}
