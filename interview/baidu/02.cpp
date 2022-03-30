#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        int k = 0;
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                k++;
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1) k++;
        
        long long ans = 1;
        for (int i  = 1; i < k; i++) ans *= 2;
        cout<<ans<<endl;
    }
    return 0;
}