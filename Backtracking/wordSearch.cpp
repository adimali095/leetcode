class Solution {
public:
    bool solve(vector<vector<char>>& board, string &word,vector<vector<bool>> &visited,int start,int &end,int &m,int &n,int mi,int ni)
    {       
        if(start == end )
        {
            return true;
        }
        //cout<<"\n[ "<<mi<<" ][ "<<ni<<" ]";
        if( mi < 0 || ni < 0 || mi >= m || ni >= n || visited[mi][ni] || board[mi][ni] != word[start] )
        {  
            return false;
        }
        visited[mi][ni] = true;
        bool found = (
        solve(board,word,visited,start+1,end,m,n,mi+1,ni) ||
        solve(board,word,visited,start+1,end,m,n,mi,ni+1) ||
        solve(board,word,visited,start+1,end,m,n,mi-1,ni) ||
        solve(board,word,visited,start+1,end,m,n,mi,ni-1) );
        visited[mi][ni] = false;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m,n,end,i,j;
        m = board.size();
        n = board[0].size();
        end = word.size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        cout<<m<<n;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(solve(board,word,visited,0,end,m,n,i,j))
                {
                    return true;
                }
            }
        }
        return false;          
    }
};
