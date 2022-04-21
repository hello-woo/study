#include<bits/stdc++.h>

using namespace std;


const int N = 505;
int dir[8][2] = {1,2,1,-2,-1,-2,-1,2,2,1,2,-1,-2,-1,-2,1};
char board[N][N];
int n,m;

struct node{
  int x,y ,step;  
};

queue<node>que;


int bfs(int x,int y){
    while(!que.empty()){
        node temp = que.front();
        que.pop();
        
        for(int i = 0 ;i < 8;i++){
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            
            if(x < 0 || x > n || y < 0 || y > m || board[x][y] == '0') continue;
            //cout << temp.x << temp.y + 1 << endl;

            if(board[temp.x ][temp.y + 1] == '0' && dir[i][1] == 2) continue; 

            if(board[temp.x][temp.y - 1] == '0' &&dir[i][1] == -2) continue;

            if(board[temp.x + 1][temp.y] == '0' && dir[i][0] == 2) continue;
            
            //cout << "temp :" << temp.x  + 1 << "y :" << temp.y <<endl;

            if(board[temp.x - 1][temp.y] == '0' && dir[i][0] == -2) continue;
            
            
            if(board[x][y] == 'T') return temp.step + 1;
            
            if(board[x][y] == '1'){
                board[x][y] = '0';
                que.push({x,y,temp.step + 1});
            }
        }
    }
    return -1;
}

int main(){
    int t ;
    cin >> t;
    vector<int>ans;
    while(t--){
        cin >> n >> m;
        int sx=0,sy=0;
        for(int i= 1; i <=n;i++){
            for(int j = 1; j <=m;j++){
                cin >> board[i][j];
                if(board[i][j] == 'K'){
                    sx = i;
                    sy = j;
                }
            }
        }     
        //cout << sx <<","<< sy <<endl;
        que.push({sx,sy,0});
        
        int res = bfs(sx,sy);
        ans.push_back(res);
    }
    for(auto p : ans){
        cout << p<< endl;
    }
    return 0;
}