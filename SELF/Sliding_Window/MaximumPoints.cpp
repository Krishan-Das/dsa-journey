#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Maximum points you can obtain from n cards
int maxPoints(int* arr, int n, int k){
    int leftSum = 0, rightSum = 0, ans = INT_MIN;
    // First window
    for(int i = 0; i<k; i++){
        leftSum += arr[i];
    }
    
    ans = max(leftSum, ans);
    
    int right = n-1;
    int left = k-1;
    while(left>=0){
        leftSum -= arr[left];
        left--;
        rightSum += arr[right];
        right--;
        ans = max(ans, leftSum+rightSum);
    }
    return ans;
}

int main() {
    
    int arr[] = {2,1,3,4,5,7,6,9,8};
    int n = sizeof(arr)/ sizeof(int);
    
    int ans = maxPoints(arr, n, 4);
    cout << ans;

    return 0;
}