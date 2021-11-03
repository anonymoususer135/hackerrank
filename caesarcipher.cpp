#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'caesarCipher' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    string output="";
    int newK = k % 26;
    for (int i = 0; i < s.size(); i++) {
        if (((int)s.at(i) >= 65 && (int)s.at(i) <= 90)) {
            if ((int)s.at(i)+newK <= 90) {
                output+= char((int)s.at(i)+newK);
            }
            else {
                output+= char(65+(int)s.at(i)+newK-90-1); //the portion to cross the Z, go back from A again
            }
        }
        else if (((int)s.at(i) >= 97 && (int)s.at(i) <= 122)) {
            if ((int)s.at(i)+newK <= 122) {
                output+= char((int)s.at(i)+newK);
            }
            else {
                output+= char(97+(int)s.at(i)+newK-122-1);
            }
    }
    else{
        output+=s.at(i);
        
    }
}
return output;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
