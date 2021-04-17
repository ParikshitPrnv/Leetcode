class Solution {
public:
    
    int nthUglyNumber(int n) {
        set<long long int>s;
        s.insert(1);
        int count=1;
        while(count!=n)
        {
            auto it=s.begin();
            long long int x=*it;
            s.erase(it);
            s.insert(x*2);
            s.insert(x*3);
            s.insert(x*5);
            count++;
        }
        return *s.begin();
    }
};