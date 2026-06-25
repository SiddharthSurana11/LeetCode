class Solution {
    bool isPossible(vector<int>& nums, int mid, int k){
        int studentCount=1;
        int pageSum=0;

        for(int i=0;i<nums.size();i++){
            if(pageSum+nums[i]<=mid){
                pageSum=pageSum+nums[i];
            }
            else{
                studentCount++;
                if(studentCount>k || nums[i]>mid){
                    return false;
                }
                pageSum=nums[i];
            }
        }
        return true;
}
public:
    int splitArray(vector<int>& nums, int k) {
        int start=0;
        int sum=0;
        for(int i=0; i<nums.size();i++){
            sum=sum+nums[i];
        }
        int end=sum;
        int mid=start+(end-start)/2;
        int ans=-1;

        while(start<=end){
            if(isPossible(nums,mid,k)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
            mid=start+(end-start)/2;
        } 
        return ans;
    }
};