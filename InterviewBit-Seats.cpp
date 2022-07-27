// Link to Problem => https://www.interviewbit.com/problems/seats/

int Solution::seats(string A) {
  
//   Storing all the occupied seats locations in pos array.
    vector<int> pos;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='x')
            pos.push_back(i);
    }
  
//   Finding median occupied seat
    int mid = pos.size()/2;
    int mod = 10000003, ans = 0;
  
//  Calculating the number of moves required by each individual to provided there are some individuals already present in-between.
//  abs(pos[mid]-pos[i])-1 => Signifies distance between the median position and current position.
//  abs(mid-i)-1           => Signifies the number of individuals between current individual and the median position.
    for(int i=0;i<pos.size();i++)
    {
        ans = (ans+(abs(pos[mid]-pos[i])-(abs(mid-i)-1))-1)%mod;
    }
  
    return ans%mod;
}

