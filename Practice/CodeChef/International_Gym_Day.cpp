#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int d, x, y;
        cin >> d >> x >> y;
        int session = 0;
        bool possible = false;
        while(y-session>=0)
        {
            double discount = (x*(100-d*session))/100.0;
            if(y-session>=discount)
            {
                possible = true;
                break;
            }
            session++;
            
        }
        if(possible) cout<<session<<endl;
        else cout<<-1<<endl;
        
     
    }
    
    return 0;
}
