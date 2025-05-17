#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    
    if(k>32) cout << "No\n";
    else if(x >= (long long)1<<(k-1)) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
	int t;
	cin >> t;
	while(t--)
	    solve();
}
