class Solution {
public:
    bool rotateString(string s, string goal) {
        int l=s.length();
        int m=goal.length();
        if(l!=m){
            return false;
        }
        string ans=s+s;
        return (ans.find(goal)!=string::npos);
    }
};