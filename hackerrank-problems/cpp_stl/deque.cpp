#include <iostream>
#include <bits/stdc++.h>
#include <deque> 
#include <algorithm>

using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
	deque<int> mydeque;
	int i=0;

	mydeque.push_front(i);

	for(i=1;i<k;i++) {
        if(arr[i]>arr[i-1]) {
            mydeque.pop_front();
            mydeque.push_front(i);
        }
    }

	std::cout<<"result of first window"<<arr[mydeque[0]]<<endl;

	for(i=k;i<n;i++){
		if(arr[i]>arr[i-1]) {
			mydeque.pop_back();
			mydeque.push_back(i);

			//check if front of deque is max
			if(arr[mydeque[0]]<arr[mydeque[mydeque.size()-1]]) {
				mydeque.pop_front();
			}
			//check if front of deque lies in current window
			if((i-mydeque[0])>=k) {
				mydeque.pop_front();
			}
		}
		else {
			mydeque.push_back(i);

			//check if front of deque lies in current window
			if((i-mydeque[0])>=k) {
				mydeque.pop_front();
			}
		}
		std::cout<<" "<<arr[mydeque[0]];
	}
	std::cout<<endl;
	return;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}