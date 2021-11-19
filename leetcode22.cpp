class Solution {
public:
    vector<string> combined(vector<string> s){
       vector<string> temp;
       for(int i=0;i<s.size();i++){
            string str;
            for(int j=0;j<s[i].size();j++){
                if(s[i][j] == ')'){// (( ) ) or ()()
                    string t1 = str + "()";
                    for(int k=j;k<s[i].size();k++)
                        t1 += s[i][k];

                    auto it = find(temp.begin(),temp.end(),t1);
                    if(it==temp.end())
                        temp.push_back(t1);
                    
                    string t2 = str + ")";
                    t2 += "()";
                    for(int k=j+1;k<s[i].size();k++)
                        t2 += s[i][k];
 
                    it = find(temp.begin(),temp.end(),t2);
                    if(it==temp.end())
                        temp.push_back(t2);

                    str += ')';
                }else{
                     str += s[i][j];
                }
            }
       }
       return temp; 
    }
    vector<string> generateParenthesis(int n) {
        
        
        vector<string> ans;
        ans.push_back("()");
        
        for(int i=1;i<n;i++)
            ans = combined(ans);
        
        return ans;
    }
};
