class Solution {
public:
    void to_lowercase(string &input) {
        for (char &c : input) {
            if ('A' <= c && c <= 'Z') {
                c -= 'A'-'a';
            }
        }
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        map<string, int> vocabulary;
        set<string> banned_set;
        for (string b : banned) {
            banned_set.insert(b);
        }
        const string delimiters{" !?',;."};
        size_t begin = 0, pos = 0;
        
        to_lowercase(paragraph);
        
        // tokenize
        while((begin = (paragraph.find_first_not_of(delimiters, pos))) != string::npos) {
            pos = paragraph.find_first_of(delimiters, begin+1);
            string temp_string = paragraph.substr(begin, pos-begin);
            // cout << begin << " "<< pos << " "<< temp_string << endl; //erase
            if ((banned_set.find(temp_string) != banned_set.end())) {
                continue;
            }
            map<string, int>::iterator it = vocabulary.find(temp_string);
            if (it == vocabulary.end()) {
                vocabulary.insert(pair<string, int>(temp_string, 1));                
            }
            else {
                (it->second)++;
            }
        }
        
        int maximum = 0;
        string maximum_string = "";
        for (pair<string, int> p : vocabulary) {
            if (p.second > maximum) {
                maximum = p.second;
                maximum_string = p.first;
            }
        }
        
        return maximum_string;
    }
};