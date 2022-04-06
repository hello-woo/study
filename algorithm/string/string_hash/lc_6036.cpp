typedef long long LL;
typedef unsigned long long ULL;
const int N = 100010, P = 13331;

class Solution {
public:
    ULL h[N], p[N];

    //得到区间【l,r】的哈希值
    ULL get(int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    // 原串的前缀[1, len] 是否与 s.substr(base, len) 相等
    bool check(int base, int len) {
        return get(1, len) == get(base, base + len - 1);
    }

    LL sumScores(string s) {
        int n = s.size(); s = ' ' + s;
        p[0] = 1;
        for(int i = 1; i <= n; i ++) {
            h[i] = h[i - 1] * P + s[i];
            p[i] = p[i - 1] * P;
        }

        LL res = 0;
        for(int i = n; i >= 1; i --) {
            int l = 0, r = n - i + 1;       // 二分长度
            while(l < r) {
                int mid = l + r + 1 >> 1;
                if(check(i, mid)) l = mid;
                else r = mid - 1;
            }
            res += r;
        }
        return res;
    }
};
/*
作者：chn-DK
链接：https://leetcode-cn.com/problems/sum-of-scores-of-built-strings/solution/zi-fu-chuan-ha-xi-shui-guo-by-chn-dk-zmws/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


typedef long long ll;
typedef unsigned long long ULL;

const int B  = 13331; //多项式
const int MOD = 1e8 + 7;
const int N = 1e5 + 10;

ULL hash_val[N];
ULL b_val[N];//计算区间哈希时，f[l,r] = f[r] - f[l -1 ] * b^(r - l + 1);


ULL getHashLR(int l ,int r){
    return (hash_val[r] - hash_val[l - 1] * b_val[r - l  + 1]% MOD + MOD ) % MOD;
}

//[1,len] 和[start,start + len - 1]比较是否相等
bool check(int start ,int len){
   // cout << getHashLR(1,len)<< " 1"<<endl;
    //cout << getHashLR(start,start + len - 1) << " len : " <<endl;
    return getHashLR(1,len) == getHashLR(start,start + len - 1);
}

class Solution {
public:
    ll sumScores(string s) {
        ll ans = 0;
        int n = s.size();
        s = ' ' + s;

        b_val[0] = 1;
        for(int i = 1 ; i <= n; i++){
            hash_val[i] = (hash_val[i - 1] * B + s[i]) % MOD ;
            b_val[i] = (b_val[ i - 1] * B) % MOD; 
        }

        //枚举每一个后缀i, 二分区间长度mid，比较和原字符串1，mid是否相等，相等长度增加，
        
        for(int i = n ;i >= 1;i--){
            ll l = 0 ,r = n - i + 1;
            while(l < r){
                ll mid = (l + r + 1) >> 1;

               // cout <<  "mid  :" <<mid<<endl;
                if(check(i,mid)){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
           // cout << r <<endl;
            ans += r;
        }
        return ans;

    }
};