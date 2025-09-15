#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            int alen = answers.size()-1;
            if(alen==0)
                return answers[0]+1;
            if(alen==-1)
                return 0;
            sort(answers.begin(),answers.end());
            int count = 0;
            for(int i=0;i<=alen;i++){
                cout<<count<<endl;
                if(answers[i+1]==answers[i]){
                    i+=1;
                    count+=answers[i]+1;//1 1 1 2 2 3
                }else{
                    count+=answers[i]+1;
                }
                if(answers[i+1]==answers[i] && i==alen-1){
                    count=answers[i]+1;
                    if(answers[i]>=alen+1)
                        return count;
                }
                    
            }
            return count;
        }
};

int main(){
    Solution S;
    vector<int> V = {5,5,5,5};
    cout<<S.numRabbits(V);
}