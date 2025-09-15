#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* A;
    A=nums;
    int Asize;
    Asize=numsSize;
    int T;
    T=target;
    int *B;
    B=(int*)malloc((*returnSize)*sizeof(int));
    int i,j;
    // for(i=0;i<Asize;i++){
    //     for(j=i+1;j<Asize;j++){
    //         if(A[i]+A[j] == T){
    //             *(B)=A[i];
    //             *(B+1)=A[j];
    //             return B;
    //         }
    //     }
    // }
    return B;
}

int main(){
    int nums[4]={2,7,11,15};
    int target = 9;
    int returnSize;
    returnSize=2;
    int *Output;
    Output=twoSum(nums,4,target,&returnSize);
    int i;
    for(i=0;i<2;i++){
        printf("Output : %d",i);
    }
    free(Output);
    printf("Works");
    for(i=0;i<2;i++){
        printf("Output : %d",i);
    }
}