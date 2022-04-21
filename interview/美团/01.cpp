// #include<bits/stdc++.h>

// using namespace std;

// long long  cnt = 0x3f3f3f3f3f;

// void getNum(int a,int b,long long  curval){
//     int temp = 0;

//     if(a == b){
//         if(curval < cnt){
//             cnt = curval;
//             return;
//         }
//     }
//     if(a > b) swap(a,b);
//     if(curval < cnt){
//         getNum(a + 1,b,curval + 1);
//         getNum(a * 2 ,b, curval + 1);
//         getNum(a,b / 2,curval + 1);
//     }else return ;
// }

// int main(){
//     int a,b;
//     cin >> a >> b;
//     /*
//     if(a> b) swap(a,b);
//     int temp = b;
//     int cnt = 0;
//     int ans1 = 0;
//     //比a小的一次
//     while(temp >  a){
//         temp /= 2;
//         cnt++;
//     }
//     ans1 += cnt ;
    
//     ans1 += min(abs(temp- a) ,abs(temp * 2- a) - 1);
    
//     int ans2 = b - a;
//     cout << min(ans1,ans2) << endl;
    
//     int tp = a;
//     int cnt1 = 0;
//     int ans3 = 0;
//     while(a  < b){
//         a *= 2;
//         cnt1++;
//     }
//     ans3 += cnt1;
    
//     ans3 += min(abs())*/
//     getNum(a,b,0);
//     cout << cnt<< endl;
    
    
//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

const int N = 50005;

int father[N];
int val[N];

int l[N];
int r[N];

bool vis[N];

int query(int l,int r){
    memset(vis,false,sizeof(vis));
    vector<int>path;
    int temp = l;
    int ans = 0;
    while(l != 0){
        vis[l] = true;
        l = father[l];
    }
    
    while(r != 0 && vis[r] == false ){
        path.push_back(val[r]);
        r = father[r];
    }

    cout << " root :" << r << endl;
    path.push_back(val[r]);
    
    while(temp != r){
        path.push_back(val[temp]);
        temp = father[temp];
    }

   cout << "p : [" ;
    for(auto p : path){
        ans ^= p;
        cout <<  p << " ," ;
    }
    cout << "]" << endl;
    return ans ;
}

int main(){
    int n;
    cin >> n;
    father[1] = 0;
    for(int i = 2 ;i <= n;i++){
        int temp ;
        cin >> temp;
        father[i] = temp;
    }
    
    for(int i = 1 ;i <= n;i++){
        int tep;
        cin >> tep;
        val[i] = tep;
    }
    int m;
    cin >> m;
    //cout << query(2,3);

    for(int i = 1 ;i <= m;i++){
        cin >> l[i];
    }
    for(int i = 1 ;i <= m;i++){
        cin >> r[i];
    }
    
    for(int i = 1 ;i <= m;i++){
        cout << query(l[i],r[i]) <<" ";
    }
    return 0;
}