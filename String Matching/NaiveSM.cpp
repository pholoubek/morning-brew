/*
 *  This is the naive implementation of a string matching algorithm 
 *  The method NaiveSM returns by value vector of ints, where each int represents
 *  starting index of the pattern from the beginning of the given text. 
 *
 *  The Big O running complexity is O((n-m+1)m)
 *  Where n is the size of the text,
 *  m is the size of the pattern
 *
 *  There's no preprocessing.
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

ostream& operator<<(ostream&, const vector<int>& vec) {
    for(size_t i = 0; i < vec.size(); ++i){
            cout << vec[i] << endl;
    }
}


vector<int> NaiveSM(string t, string p) {
    vector<int> shift; 
    int n = t.size();
    int m = p.size();    
    for(size_t s = 0; s <= n - m; ++s){
        if(p[0] == t[s]) {
            shift.push_back(s);
            for(size_t i = 1; i < m; ++i){
                if(p[i] != t[s + i]){
                    shift.pop_back();
                    break;
                }
            }
        }
    }
    return shift;
}


int main() {
    string text = "aaaabababababbbbaaabbbaaaa";
    string pattern = "bbbbbb";
    vector<int> result = NaiveSM(text, pattern);
    if(result.size() == 0) { cout << "No match!" << endl; }
    for(size_t i = 0; i < result.size(); ++i){
        for(size_t j = result[i]; j < result[i] + pattern.size(); ++j){
            cout << text[j];
        }    
        cout << endl;
    }
}
