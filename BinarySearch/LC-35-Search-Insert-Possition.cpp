/*
  LC 35.Search Insertion Position

  Approach:
  1. Apply Binary Search since the array is sorted.
  2. Compute the middle index.
  3. If nums[mid] == target, return mid.
  4. If nums[mid] < target, search in the right half.
  5. Otherwise, search in the left half.
  6. If the target is not found, low will point to the correct insertion position. Return low.


  Time Complexity: O(log n)
  Space Complexity: O(1)

*/


#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;

        while(low<=high){
            mid = low + (high - low)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid]<target){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return low;
    }
};
