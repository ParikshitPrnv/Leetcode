bool cmp(int &c,int &d)
{
    int a=c,b=d;
    int counta=0,countb=0;
    while(a>0 && b>0)
    {
        a=a&(a-1);
        b=b&(b-1);
        counta++;
        countb++;
    }
    while(a>0)
    {
        a=a&(a-1);
        counta++;
    }
    while(b>0)
    {
        b=b&(b-1);
        countb++;
    }
    if(counta==countb)
        return c<d;
    return counta<countb;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),cmp);
        return arr;
    }
};