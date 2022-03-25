#include<bits/stdc++.h>

using namespace std;

const int N= 3005;

int k[N]; //结出ki西瓜
int a[N]; // 第ai天 ,起始
int b[N]; //终止
int z[N];

struct Node{
  int start;
  int end;
  int cnt;
};
bool cmp (Node& a,Node &b){
    if(a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

void solve(){
    int n ,v;
    cin >> n >> v;
    vector<Node>ve;
    int ans = 0;
    for(int i = 0; i < n ;i++){
        cin >> k[i] >> a[i] >> b[i];
        ve.push_back({a[i],b[i],k[i]});
    }
    sort(ve.begin(),ve.end(),cmp);
    int minday = ve[0].start,maxday = ve[n -1].end;
    
    int flag[N] = {0}; // flag = 0 ,1 , 2;0表示没有操作，1表示摘了v的，2表示没有满的
    int weiman[N] = {0};
    
    //枚举每一个瓜田，
    for(int i = 0 ;i < n ;i++){
        //枚举每个瓜田的起始日期
        for(int j = ve[i].start;j <=ve[i].end ;j++){
            //下一个瓜田的
            if(flag[j] == 2 && weiman[j] == 1 && ve[i].cnt >= v){
                    ans += v - z[j];
                    ve[i].cnt -= (v-z[j]);
                cout << " bu" << endl;
            }
            if(ve[i].cnt >= v && flag[j] == 0) {
                cout << " i" << i<<endl;
                ans += v;
                ve[i].cnt -= v;
                z[j] = v;
                flag[j] = 1;
            }else if(0< ve[i].cnt && ve[i].cnt < v  && flag[j] == 0 && weiman[j] == 0){
                ans +=  ve[i].cnt;
                z[j] = ve[i].cnt;
                ve[i].cnt = 0;
                weiman[j] = 1;
                flag[j] = 2;
                cout << " z" << z[j] <<"j :" <<j <<endl;
                j--;
            }
        }
    }
    cout << ans <<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
