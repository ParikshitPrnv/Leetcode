class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int n=arr.size();
        for(int i=1;i<n;i++)
            arr[i]+=arr[i-1];
        for(int i=0;i<n;i++){
           
            for(int j=1;i+j<=n;j+=2){
                if(i==0)
                    sum+=arr[i+j-1];
                else
                    sum+=arr[i+j-1]-arr[i-1];
            
            }
            
        }
        return sum;
    }
    
};