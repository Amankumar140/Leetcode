// use kmp +lps and find min char for adding and add revers substr that required

class Solution {
public:
    int lpsfind(string s){
      vector<int>lps(s.size(),0);
      int pre=0;
      int suf=1;
      while(suf<s.size()){
          if(s[pre]==s[suf]){
              lps[suf]=pre+1;
              suf++;pre++;
          }
          else{
              if(pre==0) suf++;
              else {
                  pre=lps[pre-1];
              }
          }
          
      }
      return lps[s.size()-1];
  }
    string shortestPalindrome(string s) {
        string str=s;
        reverse(str.begin(),str.end());
        string newstr=s+"$"+str;
        int x=s.size()-lpsfind(newstr);
        return str.substr(0,x)+s;
    }
};
