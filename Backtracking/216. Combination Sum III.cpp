class Solution {
public:
    vector<vector<int> >ans;
    
    void backtrack(vector<int> &current,int i,int &size,int target){
        if(target==0){
            if(current.size()==size)
                ans.push_back(current);
            return ;
        }
        
        for(int j=i+1;j<=9;j++){
            current.push_back(j);
            backtrack(current,j,size,target-j);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>current;
        
        backtrack(current,0,k,n);
        return ans;
    }
};