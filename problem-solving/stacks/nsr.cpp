// nearest smallest to right

// input
// enter array length: 5
// 4 5 2 10 8
// output:
// 2 2 -1 8 -1

// time complexity: O(n)

#include <iostream>
#include <bits/stdc++.h>
#include <stack>

#define null nullptr

using namespace std;

int main()
{
  int n;
  vector<int> vec;
  stack<int> st;

  cout << "enter array length: ";
  cin >> n;

  int arr[n];

  for (int i = 0; i < n; i++)
  {
    cout << "enter array element: ";
    cin >> arr[i];
  }

  for (int i = n - 1; i >= 0; i--)
  {
    if (st.empty())
    {
      vec.push_back(-1);
    }
    else if (!st.empty() && arr[i] > st.top())
    {
      vec.push_back(st.top());
    }
    else if (!st.empty() && arr[i] <= st.top())
    {
      while (!st.empty() && arr[i] <= st.top())
      {
        st.pop();
      }

      if (st.empty())
      {
        vec.push_back(-1);
      }
      else
      {
        vec.push_back(st.top());
      }
    }
    st.push(arr[i]);
  }

  reverse(vec.begin(), vec.end());

  for (auto i = vec.begin(); i < vec.end(); i++)
  {
    cout << *i << "  ";
  }
  return 0;
}