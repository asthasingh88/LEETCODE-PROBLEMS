// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         stack<char>st;
//         for(char c:s){
//             st.push(c);}
//             for(int i=0;i<s.size();i++){
//                 s[i]=st.top();
//                 st.pop();
//         }
//     }
// };

class Solution {
public:
    void reverseString(vector<char>& s) {
   int l=0;
   int r=s.size()-1;
   while(l<=r){
    swap(s[l],s[r]);
    l++;
    r--;

   }

        
    }
};