//using monotonic subarray
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int> >st;
        int n=T.size();
        vector<int>ans;
        for(int i=n-1;i>=0;i--)
        {
            //cout<<"\n"<<T[i]<<"\n";
            while(!st.empty() && st.top().second<=T[i])
            {
              //  cout<<st.top().second<<" ";
                st.pop();
            }
            if(st.empty())
                ans.push_back(0);
            else
                ans.push_back(abs(i-st.top().first));
            st.push(make_pair(i,T[i]));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};