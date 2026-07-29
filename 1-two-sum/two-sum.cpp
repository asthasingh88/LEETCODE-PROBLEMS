class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int>ans;
        // map<int,int>d;
        // for(int i=0;i<nums.size();i++){
        //     int t=target-nums[i];
        //     if(d.find(t)!=d.end()){
        //         ans.push_back(d[t]);
        //         ans.push_back(i);
        //         break;
        //     }d[nums[i]]=i;
        // }return ans;
    //    int  n=nums.size();
    //     vector<int>ans;
    //     unordered_map<int,int>m;
    //     for(int i=0;i<n;i++){
    //     int first=nums[i];
    //     int sec=target-first;
    //     if(m.find(sec)!=m.end()){
    //         ans.push_back(i);
    //         ans.push_back(m[sec]);
    //         break;
    //        }
    //     m[first]=i;
    //     }return ans;
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]+nums[j]==target){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    // Sums
    return {};

    }
};