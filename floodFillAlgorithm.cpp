void dfs(vector<vector<int>> &image, int x, int y, int newColor,int iniColor){
    if(x < 0 || x >= image.size() || y < 0 || y >=image[0].size() || image[x][y] != iniColor){
        return;
    }
    image[x][y]=newColor;
    dfs(image,x,y-1,newColor,iniColor);
    dfs(image,x,y+1,newColor,iniColor);
    dfs(image,x-1,y,newColor,iniColor);
    dfs(image,x+1,y,newColor,iniColor);
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
     if(image[x][y] == newColor){
        return image;
    }
    int iniColor=image[x][y];
    dfs(image,x,y,newColor,iniColor);
    return image;
}