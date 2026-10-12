class Solution {
public:
void dfs(int r,int c,vector<vector<int>>&image,int oldcolor,int newcolor){
    image[r][c]=newcolor;
    //.............. NOW COVER NEIGHBOURS............
    if(r-1>=0 && image[r-1][c]==oldcolor){
        dfs(r-1,c, image,oldcolor,newcolor);
    }
    if(r+1<image.size() && image[r+1][c]==oldcolor){
        dfs(r+1,c,image,oldcolor,newcolor);
    }
    if(c-1>=0 && image[r][c-1]==oldcolor){
        dfs(r,c-1,image,oldcolor,newcolor);
    }
    if(c+1<=image[0].size();image[r][c+1]==oldcolor){
        dfs(r,c+1,image,oldcolor,newcolor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
           int oldcolor=image[sr][sc];
           if(oldcolor!=color){
           dfs(sr,sc,image,oldcolor,color);
           }
           return image;
    }
};