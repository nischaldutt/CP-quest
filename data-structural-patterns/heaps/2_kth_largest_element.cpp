// Find the kth smallest element in the given array.

#include <bits/stdc++.h>
#include <vector>
#include <queue>
#define null nullptr
#define fori for(int i = 0; i < n; i++)
#define forj for(int j = 0; j < m; j++)
#define fork for(int k = 0; k < o; k++)

using namespace std;

typedef pair<int, pair<int, int>> ppi;

void kthLargestElement(int* arr, int n, int k) {
  priority_queue<int, vector<int> ,greater<int>> minHeap;
  fori {
    minHeap.push(arr[i]);
    if(minHeap.size() > k) {
      minHeap.pop();
    }
  }

  while(!minHeap.empty()) {
    cout<<" "<< minHeap.top();
    minHeap.pop();
  }
  return;
}

int main() {
  int n;
  cin>>n;
  int arr[n], k;
  fori cin>> arr[i];
  cin>>k;
  int size = sizeof(arr) / sizeof(arr[0]);
  kthLargestElement(arr, size, k);
  return 0;
}