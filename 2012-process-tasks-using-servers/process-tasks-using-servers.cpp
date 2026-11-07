
class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            free;

        priority_queue<tuple<long long, int, int>,
                       vector<tuple<long long, int, int>>,
                       greater<tuple<long long, int, int>>>
            busy;

        int n = servers.size();
        int m = tasks.size();

        for (int i = 0; i < n; i++) {
            free.push({servers[i], i});
        }

        vector<int> ans(m);
        long long time = 0;

        for (int i = 0; i < m; i++) {

            time = max(time, (long long)i);

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [t, w, idx] = busy.top();
                busy.pop();
                free.push({w, idx});
            }

            if (free.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [t, w, idx] = busy.top();
                    busy.pop();
                    free.push({w, idx});
                }
            }

            auto [w, idx] = free.top();
            free.pop();

            ans[i] = idx;

            busy.push({time + tasks[i], w, idx});
        }

        return ans;
    }
};
