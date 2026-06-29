/*
    704. Binary Search
    Difficulty: Easy

    Approach:
    - Since the array is sorted, we can apply Binary Search.
    - Calculate the middle index.
    - If nums[mid] == target, return mid.
    - If nums[mid] > target, search in the left half.
    - Otherwise, search in the right half.
    - If the target is not found, return -1.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
       int low = 0, high = nums.size() - 1, mid;

       while(low <= high){
        mid = low + (high - low)/2;

        if(nums[mid] == target){
            return mid;
        }else if(nums[mid]>target){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
       } 

       return - 1;
    }
};