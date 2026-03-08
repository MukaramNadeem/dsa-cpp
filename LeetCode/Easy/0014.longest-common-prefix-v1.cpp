/*
  Problem: #14 Longest Common Prefix
  Difficulty: Easy
  Topics: String, Array
  Time: O(n * m) | Space: O(n * m)

  Approach:
  Find the shortest string length to limit comparisons.
  Flatten all characters column-by-column into string `s`,
  then check each column if all chars match the first string's
  char at that position. Stop as soon as a mismatch is found.

  n = number of strings, m = length of shortest string
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string> &strs){
        int min = 200;
        //loop to get minimum string's length
        for(string s : strs){
            if(s.length()<min){
                min = s.length();
            }
        }
        //get all first chars of all strings.
        string s;
        for(int i = 0;i<min;i++){
            for(int j= 0;j<strs.size();j++){
                s+=strs[j][i];
            }
        }

        //LOOP to get result...
        string result;
        for(int i = 0; i < min; i++){
            char key = strs[0][i]; // keys are obtained from 1st string till chars length equals min.
            bool isEqual = true;
            for(int j = 0; j < strs.size(); j++){
                int index = (i * strs.size()) + j;    //to get index in `s` to be compared.
                cout<<index;
                if(key != s[index]){
                    isEqual = false;
                    break;
                }
            }
            cout<<endl;
            if(isEqual){
                result+=key;
            } 
            else {
                break; 
            }
        }
        return result;
    }
};

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    Solution s1;
    cout << s1.longestCommonPrefix(strs);
    return 0;
}