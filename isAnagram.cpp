bool areAnagram(string &str1, string &str2){
    // Write your code here.
    if(str1.length()!=str2.length()) return false;
    unordered_map<char, int> mp;
    for(char c:str1) mp[c]++;
    for(char c:str2){
        mp[c]--;
        if(mp[c]<0) return false;
    } 
    return true;
}
