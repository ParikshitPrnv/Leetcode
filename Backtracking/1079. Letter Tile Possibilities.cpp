class Solution {
public:
    unordered_set<string>Set;
    unordered_set<string>vis;
    void backtrack(string &tiles,int index,string &temp){
       if(index==tiles.length()){
           //cout<<temp<<"\n";
           Set.insert(temp);
           return;
       }
        for(int i=index;i<=tiles.size();i++){
           // backtrack(tiles,i+1,temp);
            temp.push_back(tiles[i]);
            backtrack(tiles,i+1,temp);
            temp.pop_back();
        }
    }
    void permute(string &tiles,int low,int high){
        if(low==high){
            //cout<<tiles<<"\n";
            
            string temp="";
            backtrack(tiles,0,temp);
            return ;
        }
        for(int i=low;i<=high;i++){
            swap(tiles[i],tiles[low]);
            permute(tiles,low+1,high);
            swap(tiles[i],tiles[low]);
        }
    }
    int numTilePossibilities(string tiles) {
        permute(tiles,0,tiles.length()-1);
        //for(auto i:Set)
          //  cout<<i<<" ";
        return Set.size();
    }
};