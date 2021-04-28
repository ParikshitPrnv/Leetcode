//using binary search and priority queue
//good question
class Solution {
public:
    vector<int>diff;
    bool isPossible(int n,int bricks,int ladders){
        priority_queue<int>pq;
        
        for(int i=0;i<=n;i++){
           
            if(diff[i]>0){
                pq.push(diff[i]);
            }
        }
        while(!pq.empty()){
            
            if(ladders>0)
                ladders--;
            else if(bricks>=pq.top())
                 bricks-=pq.top();
            else if(bricks<pq.top())
                break;
            pq.pop();
           
        }
        return pq.empty();
    }
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
     int low=0,high=heights.size()-1;
        for(int i=1;i<=high;i++){
            
            diff.push_back(heights[i]-heights[i-1]);
            //cout<<diff.back()<<" ";
        }
        int ans=0;
       
        high--;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            
            if(isPossible(mid,bricks,ladders))
            {
               
                ans=max(ans,mid+1);
                low=mid+1;
            }
            else{
               
                high=mid-1;
            }
        }
        return ans;
    }
};

//alter https://leetcode.com/problems/furthest-building-you-can-reach/discuss/924237/C++-Priority-Queue-+-Greedy-Solution-with-Explain