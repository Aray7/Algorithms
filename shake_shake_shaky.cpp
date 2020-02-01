#include <bits/stdc++.h>
using namespace std;

int n , k;
long long  v[50005];

int ok(int num)
{
    int students = k;
    for (int i = 0; i < n; ++i) {
        if(students <= 0)
            return 1;
        students -= v[i] / num;
    }
    if(students <= 0)
        return 1;
    return  0;
}
long  long solve()
{
    long long st = 0 , en = 1000000000;
    long long mid;
    while (st < en){
         mid = (st + en +1) / 2;
        if(ok(mid))
        {
            st = mid;
        } else{
            en = mid-1;
        }
    }
    return  st;
}
int main() {
    int T;
    cin >>T;
    while(T--)
    {

        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
        }
        cout << solve() << endl;
    }
    return 0;
}