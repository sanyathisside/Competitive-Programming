class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return NULL;
        int n = s.size();
        int current_len = 1;
        int max_len = 1;
        int visited[256];
        for(int i=0;i<256;i++){
        visited[i] = -1;
        }
        visited[s[0]] = 0;
        for(int i=1;i<n;i++){
            int last_occ = visited[s[i]];
        
            //Expansion 
            if(last_occ==-1||i-current_len>last_occ){
                current_len += 1;
            }
        
            //Expansion + Contraction
            else{
                if(current_len>max_len){
                    max_len = current_len;
                 }
                current_len = i - last_occ;
            }
            visited[s[i]] = i;
        }
        
        if(current_len>max_len){
                max_len = current_len;
    }
    return max_len;
    }
};
