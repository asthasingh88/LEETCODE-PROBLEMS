class Solution { 
public: 
    int maxDepth(string s) { 
        int l = s.length(); 
        int maxCount = 0;
        int currCount = 0;

        for(int i = 0; i < l; i++) { 
            if(s[i] == '(') {
                currCount++;
                maxCount = max(currCount, maxCount);
            }
            else if(s[i] == ')') {
                currCount--;
            }
        }

        return maxCount;
    } 
};