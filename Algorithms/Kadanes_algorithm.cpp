/*
  ==================
  Kadane's Algorithm
  ==================

  ## Definition
  Kadane's Algorithm is an **O(n) time** and **O(1) space** algorithm used
  to find the **maximum sum of a contiguous subarray** in an array.

  ## Main Idea
  At every index, decide whether to:
  * Start a new subarray from the current element.
  * Extend the previous subarray by including the current element.

  The algorithm keeps track of:
  * currentSum → Maximum sum of a subarray ending at the current index.
  * maxSum     → Maximum subarray sum found so far.

  ## Algorithm
  1. Initialize:
     * currentSum = arr[0]
     * maxSum = arr[0]

  2. Traverse the array from index 1:
     * currentSum = max(arr[i], currentSum + arr[i])
     * maxSum = max(maxSum, currentSum)

  3. Return maxSum.

  ------------------------------------------------------------

  ## Why It Works
  If the running subarray sum becomes worse than the current element itself,
  it is better to discard the previous subarray and start a new one.

  In other words:
  * Continue the previous subarray if it increases the sum.
  * Otherwise, begin a new subarray from the current element.

  ------------------------------------------------------------

  ## Complexity
  * Time Complexity : O(n)
  * Space Complexity: O(1)

  ------------------------------------------------------------

  ## Applications
  * Maximum Subarray Sum (LeetCode 53)
  * Dynamic Programming problems
  * Financial profit/loss analysis
  * Signal processing
  * Basis for several advanced array algorithms

  ------------------------------------------------------------

  ## Limitations
  * Finds only the maximum **contiguous** subarray sum.
  * Does not find:
      - Maximum subsequence sum
      - Top K subarrays
      - Circular maximum subarray (requires a modified version)
      - 2D maximum submatrix (requires an extension)

  ------------------------------------------------------------

  ## Key Takeaways
  * Uses Dynamic Programming.
  * Makes a local decision at every index:
      - Extend the current subarray.
      - Start a new subarray.
  * Requires only one traversal.
  * Extremely efficient:
      - O(n) time
      - O(1) extra space

*/


// ========== Maximum subarray sum ==========
#include <iostream>
#include<climits> // INT_MIN
#include<algorithm> // max(), min()
using namespace std;

// Bruit force approach.. calculate sum of all the sub arrays and find maximum one.
// Time: O(n3).  Space: O(1)
int maximum = INT_MIN, currSum;
int maxSubarraySum(int* arr, int n){
  for(int i = 0; i<n; i++){
    for(int j = i; j<n; j++){
      currSum = 0;
      for(int k = i; k<=j; k++){
        currSum += arr[k];
      }
      maximum = max(maximum, currSum);
    }
  }
  return maximum;
}


// Better solution
// Time: O(n2).  Space: O(1)
int B_maxSubarraySum(int* arr, int n){
  for(int i = 0; i<n; i++){
    currSum = 0;
    for(int j = i; j<n; j++){
      currSum += arr[j];
      maximum = max(maximum, currSum);
    }
  }
}


// Most optimal solution (Kadanes algo.)
// TIME: O(n)  || SPACE: O(1).
int O_maxSubarraySub(int* arr, int n){
  currSum = 0;
  for(int i = 0; i<n; i++){
    currSum += arr[i];
    if(currSum > maximum){
      maximum = currSum;
    }
    if(currSum < 0){
      currSum = 0;
    }
  }
  return maximum;
}


int main() {

  int arr[] = {1,2,-3,6,4,-8,3,6,-7,-6,-1};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << O_maxSubarraySub(arr, n);

  return 0;
}