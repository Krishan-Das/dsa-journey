/*
  Intersection of Two Arrays II
  Platform: LC
  Diff: Easy

  Approach 1:
    1. compare elements of a1 with a2 if found ans.push(elem),
    2. dont compare twice with same elem so skip using brake

    Time complexity: O(n2)
    

  Approach 2:
    1. Store frequencies of elements from nums1 in a hashmap.
    2. Traverse nums2.
    3. If an element is available in the hashmap, add it to the result and decrease its frequency.
    4. Return the result.

  Time Complexity: O(n + m)
  Space Complexity: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> freq;

        for(auto elem: nums1){
            freq[elem]++;
        }

        for(auto x: nums2){
            if(freq[x] > 0){
                ans.push_back(x);
                freq[x]--;
            }
        }

        return ans;
    }
};