/*
  Problem: #14 Longest Common Prefix
  Difficulty: Easy
  Topics: String, Array, Matrix
  Time: O(n * m) | Space: O(n * m)

  Approach:
  Find shortest string length, then build a matrix where each row
  holds the i-th character of every string (column-by-column view).
  Traverse each row, if all chars match the first, add to result.
  Stop as soon as a mismatch is found.

  n = number of strings, m = length of shortest string
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:

   void printVector(vector<vector<char>> matrix){
    for (int i = 0; i < matrix.size(); i++){
      for(int j = 0 ; j < matrix[i].size();j++){
          cout << matrix[i][j];
        }
        cout << endl;
    }
  }
  string longestCommonPrefix(vector<string> &strs){
    int min = 200;

    for(string word : strs){
      if(word.length() < min){
        min = word.length();
      }
    }
    
    string s;
    
    for(int i = 0; i<min;i++){
      s+=strs[0][i];
    }
    vector <char> info;
    
    vector<vector<char>> matrix;
    for (int i = 0; i < s.length(); i++){
      vector <char> v;
      for(int j = 0 ; j < strs.size();j++){
        v.push_back(strs[j][i]);
      }
      matrix.push_back(v);
    }


    string ret = "";
    for(int i = 0 ; i < matrix.size() ; i++) {
      bool result =  true;
      char key = matrix[i][0];
      for(int j = 1 ; j < matrix[i].size(); j++){
        if (key != matrix[i][j]) {
          result = false;
        }
      }
      if(result){
        ret.push_back(key);
      }else{
        break;
      }
    }

    printVector(matrix);
    
    return ret;
  }
 
};

int main(){
  vector<string> strs = {"flower", "flow" , "flight"};
  Solution s1;
  cout << s1.longestCommonPrefix(strs);
  return 0;
}