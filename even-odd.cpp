#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::vector;
using std::string;
using str = string;
using ll = long long;

int main(){
    string n;
    cin >>n;
    reverse(n.begin(),n.end());
    if((n[0] - '0')%2 ==0)
    {
        cout <<"even";
    }
    else
    {
        cout<<"odd";
    }
}
//in this code its read iput as a string and see the last digit if it %2 ==0 that's mean the num's even else it's odd 
// like 1...........8 is even caz 8%2 =0 
