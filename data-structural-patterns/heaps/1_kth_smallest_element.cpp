// Find the kth smallest element in the given array.

#include <bits/stdc++.h>
#include <queue>
#define null nullptr

using namespace std;

void kthSmallestElement(int* arr, int size, int k) {
  priority_queue<int> maxHeap;
  for(int i = 0; i < size; i++) {
    maxHeap.push(arr[i]);
    if(maxHeap.size() > k) {
      maxHeap.pop();
    }
  }
  cout<<maxHeap.top();
  return;
}

int main() {
  int n;
  cin>>n;
  int arr[n], k;
  for(int i = 0; i < n; i++) cin>>arr[i];
  cin>>k;
  int size = sizeof(arr) / sizeof(arr[0]);
  kthSmallestElement(arr, size, k);
  return 0;
}