bool cmp(string &a,string &b)
{
    return a.length()>b.length();
}
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
            return "0";
        vector<string>v;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int carry=0;
        for(int i=0;num1[i];i++)
        {
            int mul=num1[i]-'0';
            string s="";
           // cout<<mul<<":\n";
            for(int j=0;j<i;j++)
                s+='0';
            for(int j=0;num2[j];j++)
            {
                int total=(mul*(num2[j]-'0')+carry);
                s.push_back((total%10)+'0');
                carry=total/10;
            }
            if(carry)
            { s.push_back(carry+'0');
            }
            v.push_back(s);
           // reverse(s.begin(),s.end());
            carry=0;
           //cout<<s<<"\n";
        }
       sort(v.begin(),v.end(),cmp);
        carry=0;
        string ans="";
        for(int i=0;i<v[0].length();i++)
        {
            int total=carry;
            for(auto j:v)
            {
                if(i>=j.length() || j[i]==' ')
                    break;
                
                total+=(j[i]-'0');
               
            }
            ans.push_back((total%10)+'0');
            carry=total/10;
        }
        if(carry)
            ans.push_back(carry+'0');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};