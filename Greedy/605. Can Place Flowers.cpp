class Solution {
public:
    int min(int a,int b)
    {
        return a<b?a:b;
    }
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    bool canPlaceFlowers(vector<int>& flowerbed, int total) {
        int n=flowerbed.size();
        int i=0;
        int count=0;
        while(i<n)
        {
            if(flowerbed[i]==0 && flowerbed[max(i-1,0)]==0 && flowerbed[min(i+1,flowerbed.size()-1)]==0)
            {
                count++;
                flowerbed[i]=1;
            }
            i++;
        }
        
        return count>=total;
    }
};