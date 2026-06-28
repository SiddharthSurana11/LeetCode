class Solution {
    bool solutionPossible(vector<int>& nums, int mid, int k){
        int ans=0;
        int count=1;
        for(int i=0;i<=nums.size()-1;i++){
            if((nums[i]+ans)<=mid){
                ans=ans+nums[i];
            }
            else{
                count++;
                if(nums[i]>mid || count>k){
                    return false;
                }
                ans=nums[i];
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int start=0;
        int output=-1;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=ans+nums[i];
        }
        int end=ans;
        int mid=start+(end-start)/2;
        
        while(start<=end){
        if(solutionPossible(nums, mid,k)){
            output=mid;
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=start+(end-start)/2;
        }
    return output;    
    }
};