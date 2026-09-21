
// class Solution {
// public:
//     string reverseWords(string s) {
//         int n = s.length();
//         string ans="";
//         reverse(s.begin(),s.end());
//         for(int i=0;i<n;i++){
//             string word="";
//             while(i<n && s[i]!=' '){
//                 word+=s[i];
//                 i++;
//             }
//             reverse(word.begin(),word.end());
//             if(word.length()>0){
//                 ans+=" "+word;
//             }
//         }return ans.substr(1);
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans = "";
        string temp = "";

        for(char c : s)
            st.push(c);

        while(!st.empty()) {
            char c = st.top();
            st.pop();

            if(c == ' ') {
                if(!temp.empty()) {
                    reverse(temp.begin(), temp.end());

                    if(!ans.empty())
                        ans += " ";

                    ans += temp;
                    temp = "";
                }
            }
            else {
                temp += c;
            }
        }

        if(!temp.empty()) {
            reverse(temp.begin(), temp.end());

            if(!ans.empty())
                ans += " ";

            ans += temp;
        }

        return ans;
    }
};  