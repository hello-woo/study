#include<bits/stdc++.h>

using namespace std;

const int N = 500005;
int seat[N][2];
int flag[N];//flag 0 :
vector<int>ans;

void sovle(int n,string s,int m ,string people){
    for(int i = 0 ; i < n ;i++){
        if(s[i] == '0'){
            seat[i][0] = 0;
            seat[i][1] = 0;
            flag[i] = 0;
        }else if(s[i] == '1'){
            seat[i][0] = 1;
            seat[i][1] = 0;
            flag[i] = 1;
        }else if(s[i] == '2'){
            seat[i][0] = 1;
            seat[i][1] = 1;
            flag[i] = 2;
        }
    }
    for(int i = 0 ;i < m;i++){
        //男士，优先一个位置，然后空位
        if(people[i] == 'M'){
            //先遍历一遍有没有只有一个位置的
            int index = -1;
            for(int j = 0 ;j < n ;j++){
                if(flag[j] == 1){
                    index = j;
                    break;
                }
            }

            //说明没有只有一个的位置，只能空位
            if(index == -1){
                for(int j = 0 ;j < n;j++){
                    if(flag[j] == 0){
                        index = j ;
                        break;
                    }
                }
            }

            ans.push_back(index);
            //如果没有一个人的位置，找空位
            if(flag[index] == 0){
                seat[index][0] = 1;
                seat[index][1] = 0;
                flag[index ] = 1;
            //有一个人的位置
            }else if(flag[index] == 1){
                seat[index][1] = 1;
                flag[index] = 2;
            }
        //女士，优先空位，没有则一个位置的
        }else{
            //先遍历一遍有没有空位的
            int index = -1;
            for(int j = 0 ;j < n ;j++){
                if(flag[j] == 0){
                    index = j;
                    break;
                }
            }

            //说明没有空位了，只能做有一个人的位置
            if(index == -1){
                for(int j = 0 ;j < n;j++){
                    if(flag[j] == 1){
                        index = j ;
                        break;
                    }
                }
            }

            ans.push_back(index);
            //如果没有一个人的位置，找空位
            if(flag[index] == 0){
                seat[index][0] = 1;
                seat[index][1] = 0;
                flag[index ] = 1;
            //有一个人的位置
            }else if(flag[index] == 1){
                seat[index][1] = 1;
                flag[index] = 2;
            }
            
        }
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n ;
        cin >> n;
        string s;
        cin >> s;
        int m;//排队的人数
        cin >> m;
        string people;
        cin >> people ;
        sovle(n,s,m,people);
        for(auto p : ans){
            cout << p + 1<<endl;
        }
    }
    return 0;
}