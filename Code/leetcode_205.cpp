class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char,char> charmap;
        set<char> charset;
        int len = s.length();
        for(int i = 0;i<len;++i){
            if(charmap.find(s[i]) == charmap.end() && charset.find(t[i]) == charset.end()){
                charmap[s[i]] = t[i];
                charset.insert(t[i]);
            }
            if((charmap.find(s[i]) == charmap.end() || charmap[s[i]] != t[i]))
                return false;
        }
        return true;
    }
};