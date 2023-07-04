class Solution {
public:
   void dfs(int i,int j,int m,int n,vector<vector<char>>& board,vector<vector<int>>&vis,
   string &word,int ind, bool &flag) {

       if(ind >=word.size()){
           flag = true;
           return;
       }

       if(i>=0 && i<m && j>=0 &&j<n && !vis[i][j] && word[ind] == board[i][j]){
           ind +=1;
           vis[i][j] =1;
           dfs(i,j+1,m,n,board,vis,word,ind,flag);
           dfs(i+1,j,m,n,board,vis,word,ind,flag);
           dfs(i,j-1,m,n,board,vis,word,ind,flag);
           dfs(i-1,j,m,n,board,vis,word,ind,flag);
           vis[i][j] =0;
           // it may happen that we visited in all four direction and we don't able to 
           //find next word in all directions this means we have to unmark it 
           // because it can't form any path 

       }

       else return;

   }
    bool exist(vector<vector<char>>& board, string word) {
        
        int m = board.size();
        int n =board[0].size();

        if(m*n < word.size())return false;

        vector<vector<int>>vis(m,vector<int>(n,0));

        int ind =0;
        bool flag = false;

        for(int i=0;i<m;i++){
            // ind =0;
            for(int j=0;j<n;j++){
                
                
                if(!vis[i][j]) dfs(i,j,m,n,board,vis,word,ind,flag);

            }
        }

        return flag;
       
        
    }
};



/// subarray sum divisible by k


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        mp[0] =1;
        int count =0,sum =0,rem;

        for(auto t:nums){
            sum += t;

            rem = (sum%k+k)%k;


            

            

            if(mp.find(rem) != mp.end()){
                count += mp[rem];
            }

            mp[rem]+=1;
        }

        return count;
        
    }
};