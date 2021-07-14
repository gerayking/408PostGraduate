#include<bits/stdc++.h>
using namespace std;
// leetcode 41.缺失的第一个整数
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            while(nums[i]!=i+1&&nums[i]<=n&&nums[i]>0){
                if(nums[i]==nums[nums[i]-1])break;
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};