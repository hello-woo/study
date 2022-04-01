#include<bits/stdc++.h>

using namespace std;

const int N = 20005;
//int prices[N][2];//a b 利润
vector<pair<int,int>>pri;
int flag[N];

bool cmp(pair<int,int>& a,pair<int,int> &b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;// b的利润从大到小排序
}

int main(){
    int n,a,b;
    cin >> n >>a >> b;
    for(int i = 0 ;i < n;i++){
        int x ,y;
        cin >> x >> y;
        pri.push_back(make_pair(x, y));
    }
    vector<pair<int,int>>prices = pri;
    sort(prices.begin(),prices.end());
    int ans = 0;
    for(int i = prices.size() - 1;i > prices.size() - 1 - a;i--){
        ans += prices[i].first;
        prices[i].first = 0;
        prices[i].second = 0;
    }
    sort(prices.begin(),prices.end(),cmp);
    for(int i = 0;i < b;i++){
        ans += prices[i].second;
        prices[i].first = 0;
        prices[i].second = 0;
    }
    int res = 0;
    prices = pri;
    for(auto nums : prices){
        cout << nums.first << " ," <<nums.second;
        cout <<endl;
    }
    sort(prices.begin(),prices.end(),cmp);
    for(int i = 0;i < b;i++){
        res += prices[i].second;
        prices[i].first = 0;
        prices[i].second = 0;
    }
    sort(prices.begin(),prices.end());
    cout << " ------ start "<<endl;
    for(auto nums : prices){
        cout << nums.first << " ," <<nums.second;
        cout <<endl;
    }
    cout << " --------end -------"<<endl;
    for(int i = prices.size() - 1;i > prices.size() - 1 - a;i--){
        res += prices[i].first;
        prices[i].first = 0;
        prices[i].second = 0;
    }
    cout << res <<endl;
    ans = max(ans,res);
    cout << ans <<endl;
    return 0;
}