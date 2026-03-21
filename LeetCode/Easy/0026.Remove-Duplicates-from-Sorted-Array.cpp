/*
  Problem: #26 Remove Duplicates from Sorted Array
  Difficulty: Easy
  Topics: Array, Two Pointers
  Time: O(n²) | Space: O(1)

  Approaches:
  1. (Brute Force) Mark duplicates as 0 → fails if array contains 0 as valid element.
  2. (Optimized)  Mark duplicates as INT_MAX, then use a write pointer to shift
    unique elements to the front. Return write pointer as new length.
*/

#include <iostream>
#include <vector>
#include <climits> 
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums){
        //sanity check.
        if(nums.size()==0) return 0;
        
        //assign some magic_number to duplicates : INT_MAX marks a duplicate
        for(int i = 0;i<nums.size()-1;i++){
            for(int j = i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    nums[j]=INT_MAX;
                }
            }
        }
        //need to move the unique elements at the start,So
        int counter = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]!=INT_MAX){
                nums[counter] = nums[i];
                counter++;
            }
        }
        return counter;
    }
    
};

int main(){
    vector <int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector <int> nums1 = {1, 2, 3, 4, 5};
    vector <int> nums2 = {-10, -10, -5, 0, 0, 3, 3};
    Solution s1;
    cout<<s1.removeDuplicates(nums)<<endl;
    cout<<s1.removeDuplicates(nums1)<<endl;
    cout<<s1.removeDuplicates(nums2)<<endl;
    

    return 0;
}