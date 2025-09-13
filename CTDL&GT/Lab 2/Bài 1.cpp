#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    stack<char> a; int cnt = 0;
    for (int i=0;i<s.size(); i++) {
    if (s[i]=='(' || s[i]=='{' || s[i]=='[') {a.push(s[i]); cnt++;}
    if (s[i]==')') {
        cnt--;
        if (!a.empty() and a.top()=='(') a.pop();
    }
    if (s[i]==']') {
        cnt--;
        if (!a.empty() and a.top()=='[') a.pop(); 
    }
    if (s[i]=='}') {
        cnt--;
        if (!a.empty() and a.top()=='{') a.pop(); 
    }
    }
    if (a.empty() and cnt == 0) cout << "true"; else cout << "false";
    return 0;
}