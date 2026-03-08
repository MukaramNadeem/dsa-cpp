/*
  Problem: #13 Roman to Integer
  Difficulty: Easy
  Topics: Hash Map, String, Math
  Time: O(n) | Space: O(1)

  Approach:
  Traverse string in reverse, storing last two chars to detect
  subtractive pairs (IV, IX, XL, XC, CD, CM). If a pair matches,
  replace the already-added value with the correct subtracted value.
  Otherwise add the current character's value normally.
*/
#include <iostream>
using namespace std;
#include <map>
#include <string>
class Solution{
public:
  int romanToInt(string s){
    // map for 'key-value' pairs. `key` == roman char , `value` == integer .
    map<char, int> intForRoman;
    intForRoman['I'] = 1;
    intForRoman['V'] = 5;
    intForRoman['X'] = 10;
    intForRoman['L'] = 50;
    intForRoman['C'] = 100;
    intForRoman['D'] = 500;
    intForRoman['M'] = 1000;

    int val = 0;
    string twoChars; // to store two characters to check edge cases.

    for (int i = s.length() - 1; i >= 0; i--){
      twoChars += s[i];
      if (twoChars == "VI"){ // "VI" instead of "IV" because of reverse loop.
        val -= 5;
        val += 4;
        twoChars.clear();
      }
      else if (twoChars == "XI"){
        val -= 10;
        val += 9;
        twoChars.clear();
      }
      else if (twoChars == "LX"){
        val -= 50;
        val += 40;
        twoChars.clear();
      }
      else if (twoChars == "CX"){
        val -= 100;
        val += 90;
        twoChars.clear();
      }
      else if (twoChars == "DC"){
        val -= 500;
        val += 400;
        twoChars.clear();
      }
      else if (twoChars == "MC"){
        val -= 1000;
        val += 900;
        twoChars.clear();
      }
      else{
        val += intForRoman[s[i]];
        twoChars =s[i]; // if not matched then store only one (current `i`) char !!!
      }
    }
    return val;
  }
};

int main(){
  Solution s1;
  cout << s1.romanToInt("MCMXCVI");
}

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000

// I can be placed before V (5) and X (10) to make 4 and 9.
// X can be placed before L (50) and C (100) to make 40 and 90.
// C can be placed before D (500) and M (1000) to make 400 and 900.

// IV IX
// XL XC
// CD CM

// Roman numerals are usually written largest to smallest from left to right.
