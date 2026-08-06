class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
       for(int x:nums){
        mp[x]++;
       }
       for(auto it:mp){
        if(it.second==1)
        return it.first;
       }
       return -1;


        
    }
};