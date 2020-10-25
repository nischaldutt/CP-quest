#include<bits/stdc++.h>
#include<string>

using namespace std;

int main() {
    unsigned long long n, len=0, result=0, acount=0;
    string str;

    getline(cin, str);
    cin>>n;

    len = str.size();
    //cout<<"length = "<<len<<endl;
    for (int i = 0; i < len; i++) {
        if(str[i] == 'a') {
            acount++;
        }
    }
    //cout<<"acount = "<< acount<<endl;
    unsigned long long primary = n/len;
    //cout<<"primary = "<< primary<<endl;
    result += primary * acount;
    //cout<<"result = "<< result<<endl;

    unsigned long long secondary = n%len;
    //cout<<"secondary = "<< secondary<<endl;
    if(secondary > 0) {
        acount=0;
        for (int i = 0; i <= secondary-1; i++) {
            if(str[i] == 'a') {
                acount++;
            }
        }
        //cout<<"last acount = "<<acount<<endl;
        result += acount;
    }
    cout<<result;
    return 0;
}