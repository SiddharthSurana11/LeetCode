class Solution {
    int Pivot_Index(vector<int>& nums){
        int start = 0;
        int end = nums.size()-1;
        int mid=start+(end-start)/2;
        
        if(nums[start]<nums[end]){
            return start;
        }
        
        while(start<end){
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else{
                end=mid;
            }
            mid=start+(end-start)/2;
        }
        return mid;
    }

    int BinarySearch(vector<int>& nums, int start, int end, int target){

        int mid=start+(end-start)/2;
        while(start<=end){
                if(nums[mid]>target){
                    end=mid-1;
                }
                else if(nums[mid]<target){
                    start=mid+1;
                }
                else if(nums[mid]==target){
                    return mid;
                }
                mid=start+(end-start)/2;
            }
            return -1;
    }

public:
    int search(vector<int>& nums, int target) {

        int PivotElement=Pivot_Index(nums);

        if(nums[PivotElement]<=target && target<=nums[nums.size()-1]){
            return BinarySearch(nums,PivotElement,nums.size()-1,target);
        }
        else{
            return BinarySearch(nums,0,PivotElement-1,target);
        }
    }
};