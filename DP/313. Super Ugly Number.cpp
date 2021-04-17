class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<long long>s;
        s.insert(1);
        int count=1;
        while(count!=n)
        {
            auto it=s.begin();
            long long x=*it;
            s.erase(x);
            for(auto i:primes)
            {
                s.insert(x*i);
            }
            count++;
        }
        return *s.begin();
    }
};