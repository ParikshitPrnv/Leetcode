class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n=arr.size();
        for(int i=1;i<n;i++)
            arr[i]=arr[i]^arr[i-1];
        int ans=0;
        for(int i=1;i<n;i++){
            
            for(int j=-1;j<i-1;j++){
                int x1;
                if(j==-1)
                    x1=arr[i-1];
                else
                    x1=arr[i-1]^arr[j];
                for(int k=i;k<n;k++){
                    int x2=arr[k]^arr[i-1];
                    if(x1==x2)
                        ans++;
                }
            }
        }
        return ans;
    }
};


/*************Alternative:************************************************
class Solution {
public:
    int countTriplets(vector<int>& arr) {
          int x;
            int res=0;
          for(int i=0;i<arr.size();i++){
                  x=arr[i];
                  for(int j=i+1;j<arr.size();j++){
                          x=x^arr[j];
                          if(x==0){
                                  res+=j-i;
                                  //here doing (j-i) because [2,3,4]=>2^3^4=0 so two possible triplates for this=>(2,(3,4)) and ((2),3,4)
                          }
                  }
          }

            return res;
    }
};
********************************************************************/