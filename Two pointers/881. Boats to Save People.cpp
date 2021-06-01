class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n=people.size();
        int start=0,end=n-1;
        int count=0;
        while(start<=end){
            if(start==end){
                count++;
                break;
            }
            if(people[start]+people[end]<=limit){
                count++;
                start++;
                end--;
            }
            else{
                end--;
                count++;
            }
        }
        return count;
    }
};