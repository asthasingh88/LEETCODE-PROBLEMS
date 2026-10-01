class Solution {
    private:
    // void DFS(vector<vector<char>>&grid,int r,int c){
    //     int m=grid.size();
    //     int n=grid[0].size();
    //     grid[r][c]='0';
          
    //     if(r-1>=0 && grid[r-1][c]=='1')
    //     DFS(grid,r-1,c);
    //     if(c+1<n && grid[r][c+1]=='1')
    //     DFS(grid,r,c+1);
    //     if(r+1<m && grid[r+1][c]=='1')
    //     DFS(grid,r+1,c);
    //     if(c-1>=0 && grid[r][c-1]=='1')
    //     DFS(grid,r,c-1);

    // }

    void BFS(vector<vector<char>>&grid,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        q.push({r,c});
        grid[r][c]='0';
        while(!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            if(r-1>=0 && grid[r-1][c]=='1'){
                grid[r-1][c]=0;
                q.push({r-1,c});
            }
            if(r+1<m && grid[r+1][c]=='1'){
                grid[r+1][c]=0;
                q.push({r+1,c});
            }
            if(c-1>=0 && grid[r][c-1]=='1'){
                grid[r][c-1]=0;
                q.push({r,c-1});
            }
            if(c+1<n && grid[r][c+1]=='1'){
                grid[r][c+1]=0;
                q.push({r,c+1});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0)
        return 0;
        int count=0;
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(grid[r][c]=='1'){
                    // DFS(grid,r,c);
                    BFS(grid,r,c);
                    count++;
                }
            }
        }
        return count;
    }
};