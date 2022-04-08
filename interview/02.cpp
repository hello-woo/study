#include<bits/stdc++.h>

using namespace std;

const int N = 17;
long long  nums[N];


int main(){
    string str;
    cin >> str;
    char maxval = *max_element(str.begin(),str.end());
    int maxv = 0;
    //cout << maxval << endl;
    if(maxval >= '0' && maxval <=  '9') maxv = maxval - '0';
    else if(maxval >= 'A'&& maxval <= 'F') maxv = maxval - 'A' + 10;

    cout << maxv << endl;

    for(int i = maxv + 1 ;i <= 16;i++){
        long long  ans = 0;
        for(int j = 0;j < str.size();j++){
            if(str[j] >='0' && str[j] <= '9')ans += (str[j] - '0') * pow(i,str.size() - j - 1);
            else if(str[j] >= 'A'&& str[j] <= 'F'){
                ans += (str[j] - 'A' + 10) * pow(i,str.size() - j - 1);
            }
        }
        nums[i] = ans;
    }
    sort(nums,nums + 16);
    for(int i = 2 ;i <= 16;i++){
        if(nums[i] !=0) cout << nums[i] << " ," ;
    }
    return 0;
}