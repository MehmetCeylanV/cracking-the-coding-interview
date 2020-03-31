#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

class Node{
private:
    const static int NUMBER_OF_CHARS = 26;
    Node* children[NUMBER_OF_CHARS];
    int size = 0;

    int getCharIndex(char c){
        return c - 'a';
    }

    Node* getNode(char c){
        return children[getCharIndex(c)];
    }

    void setNode(char c, Node* node){
        children[getCharIndex(c)] = node;
    }

public:
    void add(std::string s, int index){
        size++;
        if (index == s.length()) return;
        char current = s[index];
        Node* child = getNode(current);
        if (child == NULL){
            child = new Node();
            setNode(current,child);
        }
        child->add(s,index + 1);
    }

    int findCount(std::string s, int index){
         if (index == s.length()) return size;
         Node* child = getNode(s[index]);
         if (child == NULL){
             return 0;
         }
         return child->findCount(s,index + 1);
    }

};


int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Node* node = new Node();
    for (int n_itr = 0; n_itr < n; n_itr++) {
        string opContact_temp;
        getline(cin, opContact_temp);

        vector<string> opContact = split_string(opContact_temp);

        string op = opContact[0];

        string contact = opContact[1];

        if (op == "add"){
//            cout << "add: " << contact << endl;
            node->add(contact,0);
        }
        else if (op == "find"){
//            cout << "find: " << contact << endl;
            cout << node->findCount(contact, 0) << endl;
        }
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
