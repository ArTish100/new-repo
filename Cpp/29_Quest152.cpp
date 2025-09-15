//29. Divide Two Integers

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string num2binary(int a){
        string ans = "";
        if(a<0)

        while(a!=1){
            ans+='0'+a%2;
            a = a/2;
        }
        ans+="1";
        reverse(ans.begin(),ans.end());
        return ans;
    }
    int divide(int dividend, int divisor) {
        int mul=1;
        long long nume = abs((long long)dividend);
        long long deno = abs((long long)divisor);
        cout<<"nume = "<<nume<<endl;
        cout<<"deno = "<<deno<<endl;
        bool flag = 0;
        if((dividend<0 && divisor>0)||(dividend>=0 && divisor<0))
            flag = 1;
        cout<<"flag = "<<flag<<endl;
        long long ans=0;
        while(nume>=deno){
            int cnt = 0;
            while(nume>=deno<<(cnt+1)){
                cnt++;
            }
            if(ans+(1<<cnt) > INT_MAX && !flag)
                return INT_MAX;
            else if(~(ans+(1<<cnt))+1 < INT_MIN && flag)
                return INT_MIN;
            cout<<"ans = "<<(ans<<1)<<endl;
                ans+=1<<cnt;
            nume -= deno<<cnt;
        }
        
        if(flag)
            return (~ans)+1;
        else
            return ans;
    }
};

int main(){
    Solution S;
    int ans = S.divide(-2147483648, -1);
    cout<<ans<<endl;
}