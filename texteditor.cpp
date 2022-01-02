#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;
 
class TextEditor {
    private:
    vector <string> s1;
    vector <string> removedStrings;
    int previousAction;
    int appendCount;
    int deleteCount;
    //vector <string> s2;
    public:
    void append(string s) {
        appendCount = s.size();
        s1.push_back(s);
        previousAction = 1;
    }
    void deleteString(int s) {
        deleteCount = s;
        for (int i = s1.size()-s; i < s1.size(); i++) {
            removedStrings.push_back(s1.at(i));
        }
        for (int i = 0; i < s; i++) {
            s1.pop_back();
        }
        previousAction = 2;
    }
    void printString(int s) {
        cout << s1.at(s) << endl;
    }
    void undo() {
        if (previousAction == 1) {
            for (int i = 0; i < appendCount; i++) {
                s1.pop_back();
            }
        }
        else if (previousAction == 2) {
            for (int j = 0; j < deleteCount; j++) {
                for (int i = 0; i < removedStrings.size(); i++) {
                    s1.push_back(removedStrings.at(i));
                }
            }
        }
    }
};
int main() {
    int numberOfAction;
    int choice;
    string st;
    vector <string> undoVector;
    int index;
    string txt = "";
    string temp="";
    string txtBackup = "";
    cin >> numberOfAction;
//    cin >> choice;
    for (int i = 0; i < numberOfAction; ++i) {
        if (i==0)
           getline(cin, st);
        getline (cin, st); //how to cin with a space
        //cout << st << endl;
        std::istringstream stream(st);
        std::string type;
        std::string element;
        string temp;
        int lastNChar;
        stream >> type >> element;
        choice = atoi(type.c_str());
        switch(choice) {
            case 1:
                txtBackup = txt;
                undoVector.push_back(txt);
                txt=txt+element;
//                cout << txt << endl;
                break;
            case 2:
                txtBackup = txt;
                lastNChar = atoi(element.c_str());
                temp = "";
                undoVector.push_back(txt);
                txt = txt.substr(0, txt.size()-lastNChar);
             /*   for (int j=0;j<txt.size()-lastNChar; j++) {
                    temp+=txt.at(j);
                }
                txt = temp;*/
                //txt.deleteString();
                break;
            case 3:
                lastNChar = atoi(element.c_str());
                //cout << "a number " << lastNChar << endl; 
                 if (txt.size() >= lastNChar) {
                cout << txt.at(lastNChar-1) << endl;
                }
                //txtBackup = txt;
               // txt.printString(index);
                break;
            case 4:
                if (undoVector.size() > 0) {
                    txt = undoVector.back(); //stores the old stuff
               //     cout << txt << endl;
                    undoVector.pop_back();
                }

                
                //txt.undo();
                break;
            default:
                continue;
        }
    }
    
    return 0;
}

