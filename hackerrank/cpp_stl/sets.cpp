#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q,y,x;
    cin>>q;
    set<int> arr;
    set<int>::iterator i;
    while(q--) {
        cin>>y>>x;
        switch(y) {
            case 1: arr.insert(x);
                    break;
            case 2: arr.erase(x);
                    break;
            case 3: if(arr.find(x) != arr.end())
                        cout<<"Yes "<<endl;
                    else 
                        cout<<"No "<<endl;
                    break;
        }
    }   
    return 0;
}