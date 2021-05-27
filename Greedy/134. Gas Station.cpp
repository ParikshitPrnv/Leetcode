class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        
        for(int i=0;i<n;i++){
            int sum=gas[i]-cost[i];
            int current=i+1>=n?0:i+1;
            while(sum>=0 && current!=i){
                sum+=gas[current]-cost[current];
                current++;
                if(current>=n)
                    current=0;
            }
            if(sum>=0)
                return i;
        }
        return -1;
    }
};