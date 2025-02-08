#include<iostream>
using namespace std;


int t;

int main()
{
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        if(a == b)cout << "Yes" << endl;
        else if(a == 0)cout << "No" << endl;
        else if(b == 0)cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}