#include <bits/stdc++.h>
using namespace std;

// Backtracking function
void solve(int index, string &s, vector<string> &dict, vector<string> &path, vector<string> &ans) {

    // If we reached the end of the string
    if (index == s.size()) {
        string sentence = "";

        // Join words stored in path
        for (int i = 0; i < path.size(); i++) {
            sentence += path[i];
            if (i != path.size() - 1)
                sentence += " ";
        }

        // Store one valid sentence
        ans.push_back(sentence);
        return;
    }

    // Try every word in dictionary
    for (int i = 0; i < dict.size(); i++) {
        string word = dict[i];

        // Check if current word matches from current index
        if (index + word.size() <= s.size() &&
            s.substr(index, word.size()) == word) {

            // Choose
            path.push_back(word);

            // Explore further
            solve(index + word.size(), s, dict, path, ans);

            // Backtrack (remove last word)
            path.pop_back();
        }
    }
}

// Main word break function
vector<string> wordBreak(string s, vector<string> &dict) {
    vector<string> ans;   // Stores final answers
    vector<string> path;  // Stores current words

    solve(0, s, dict, path, ans);

    return ans;
}

int main() {
    string s = "catsanddog";
    vector<string> dict = {"cat", "cats", "and", "sand", "dog"};

    vector<string> result = wordBreak(s, dict);

    if (result.empty()) {
        cout << "No valid segmentation found\n";
    } else {
        for (string sentence : result) {
            cout << sentence << endl;
        }
    }

    return 0;
}
