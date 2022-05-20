/*
author:lanben
date:2022/5/17
*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> ordermap;
        int i=1;
        for(char c:order){
            ordermap[c]=i;
            i++;
        }
        int n=words.size();
        for(int i=1;i<n;i++){
            bool flag=cmp(words[i-1],words[i],ordermap);
            if(flag) continue;
            else return false;
        }
        return true;
    }
    bool cmp(string word1,string word2,unordered_map<char,int> map){
        int n1=word1.length();
        int n2=word2.length();
        int n=min(n1,n2);
        for(int i=0;i<n;i++){
            if(map[word1[i]]==map[word2[i]]) continue;
            if(map[word1[i]]<map[word2[i]]) return true;
            else return false;
        }
        //i=n,谁长谁大
        if(n1>n2) return false;
        else return true;
    }
};