class Solution {
public:
    int a[10]={0};
    vector<string>output;
    void print(int a[])
    {
        int hr=0,min=0;
        for(int i=0;i<10;i++)
        {
            if(a[i]==1)
            {
                if(i<=5)
                {
                    min+=pow(2,i);
                }
                else
                {
                    hr+=pow(2,i-6);
                }
            }
        }
        string hrs=to_string(hr); 
        if(hr>11)
            return;
        if(min>59)
            return;
        string mins="";
        if(min<10)
        {
            mins="0"+to_string(min);
        }
        else
            mins=to_string(min);
        string s=hrs+":"+mins;
        output.push_back(s);
    }
    bool cmp(string a,string b)
    {
        return a<b;
    }
    vector<string> readBinaryWatch(int num,int x=0) {
        if(x==10)
        {
            if(num==0)
            print(a);
            std::sort(output.begin(),output.end());
            return output;
        }
        a[x]=1;
        readBinaryWatch(num-1,x+1);
        a[x]=0;
        readBinaryWatch(num,x+1);
        return output;
    }
   
};