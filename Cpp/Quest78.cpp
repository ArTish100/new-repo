#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    int min(int a, int b){
        if(a<b)
            return a;
        return b;
    }
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int dlen = tops.size();
        if(dlen==1)
            return 0;
        int count;
        int tops_count;
        int bottoms_count;
        int subcount;
        for(int i=1;i<7;i++){
            count=0;
            tops_count=0;
            bottoms_count=0;
            subcount=0;
            for(int j=0;j<dlen;j++){
                if(i==tops[j] || i==bottoms[j]){
                    count++;
                    if(i==tops[j] && i==bottoms[j])
                        subcount++;
                    if(i==tops[j])
                        tops_count++;
                    if(i==bottoms[j])
                        bottoms_count++;
                    
                }
                // cout<<i<<" "<<j<<" "<<tops_count<<" "<<bottoms_count<<" "<<count<<" "<<subcount<<endl;
                if(count!=j+1)
                    break;
                if(count==dlen && tops_count+bottoms_count-subcount==count)
                    return min(tops_count-subcount,bottoms_count-subcount);

            }
        }
        return -1;
    }
};

int main(){
    Solution S;
    vector<int> T={1,2,1,1,1,2,2,2};
    vector<int> B={2,1,2,2,2,2,2,2};
    cout<<S.minDominoRotations(T,B);
}