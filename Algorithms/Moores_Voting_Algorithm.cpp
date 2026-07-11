/*
  ========================
  Moore's Voting Algorithm
  ========================

  ## Definition
  Moore's Voting Algorithm is an **O(n) time** and **O(1) space** algorithm used to find an element that appears **more than a certain fraction of the array**, most commonly the **majority element** (an element occurring more than `n/2` times).

  ## Main Idea
  The algorithm works on the principle of **pairwise cancellation**.

  * If two different elements are encountered, they cancel each other's vote.
  * Since the majority element appears more than half of the time, it cannot be completely cancelled out.
  * After one traversal, the remaining candidate is the potential majority element.

  ## Algorithm (for Majority Element > n/2)
  1. Initialize:
    * `candidate = 0`
    * `count = 0`
  2. Traverse the array:
    * If `count == 0`, set the current element as the new `candidate`.
    * If the current element equals the `candidate`, increment `count`.
    * Otherwise, decrement `count`.
  3. After the traversal, `candidate` is the potential majority element.
  4. If the problem does **not** guarantee a majority element, perform a second traversal to verify that the candidate appears more than `n/2` times.

  ---

  ## Complexity
  * **Time Complexity:** `O(n)`
  * **Space Complexity:** `O(1)`

  ---

  ## Applications
  * Finding the Majority Element (`> n/2`)
  * Finding all elements occurring more than `n/3` times (extended version with two candidates)
  * Generalized version for elements occurring more than `n/k` times (maintain `k - 1` candidates)

  ---

  ## Limitations
  * The basic algorithm only finds a **candidate**, not the actual frequency.
  * A verification pass is required if a majority element is **not guaranteed**.
  * It is **not suitable** for finding:

    * Most frequent element
    * Top K frequent elements
    * General frequency counting

  ---

  ## Key Takeaways
  * Uses **pairwise cancellation**.
  * Maintains only a **candidate** and a **count**.
  * Extremely memory efficient (`O(1)` space).
  * Best suited for **majority-threshold** problems (`> n/2`, `> n/3`, `> n/k`).

*/


#include <iostream>
using namespace std;

int majorityElement(int* arr, int n){
  if(n == 0) return -1;
  int count = 0, elem = 0;
  for (int i = 0; i < n; i++)
  {
    if(count == 0){
      elem = arr[i];
      count = 1;
    }else if(elem == arr[i]){
      count++;
    }else{
      count--;
    }
  }

  // if not guaranted that majority element is exists.
  count = 0;
  for(int i = 0; i<n; i++){
    if(arr[i] == elem) count++;
  }

  if(count > n/2) return elem;

  return -1;
}


int main() {

  int arr[] = {1,2,2,1,2,3,2,1,4,2,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  int res = majorityElement(arr, n);
  cout << res;

  return 0;
}