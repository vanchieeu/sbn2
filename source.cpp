#include <iostream>
#include <map>
using namespace std;

typedef long long int ll;
ll a[100001];

void setup(ll *a) {
    a[1] = 0;
    a[2] = 1;
    for (int i = 3; i <= 100000; i++)
        a[i] = a[i-1]+i-1;
}

int main() {
    setup(a);
    int n;
    cin >> n;
    map <int, int> b;
    map <int, bool> c;
    int arr[n];
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        b[arr[i]]++;
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (c[arr[i]] == true)
            continue;
        else {
            sum += a[b[arr[i]]];
            c[arr[i]] = true;
        }
    }

    cout << sum;
    return 0;
}