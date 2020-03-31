#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int* charCount(string a){
    int* alphabet = new int[26]{0};
    for (int i = 0; i < a.length(); i++){
        int index = a[i] - 'a';
        alphabet[index]++;
        cout<< "index " << index << " " << alphabet[index] << endl;
    }
    return alphabet;
}

int delta(int* a, int* b){
    int delta = 0;
    for (int i = 0; i < 26; i++) {
        delta += abs(a[i] - b[i]);
    }
    return delta;
}

int makeAnagram(string a, string b) {
    int* a_count = charCount(a);
    int* b_count = charCount(b);
    return delta(a_count,b_count);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
