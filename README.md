# hackerrank

Here I enter some progress stuff while working on the HackerRank challenges.

## Caesar Cipher

**10/29/2021**

When starting on the Caesar Cipher code, I first put in a for loop, then introduced an integer variable called ascValue to store the ASCII values, and aLetter to turn said values back into characters. Here is my code so far. I have not finished my answer yet.

```code
string caesarCipher(string s, int k) {
    //int lengthOfString; 
    // Build an array that has the 
    int ascValue;
    char aLetter;
    for (int i = 0; i < s.size(); i++) {
        //check if the letter is upper case or lower case
        
        ascValue=int(s.at(i))+k;
        
        aLetter=int(s.at(i))+k;
        
        s.at(i) = s.at(i)+k;
    }
}
```

**11/2/2021**

I have learned how to convert variables to ASCII values, after finding some souce code. In order to turn characters into their ASCII integer forms, the user enters (int) before a character variable like this.

```cpp
int c = 97;
cout << char(c); //prints a
```

And for turning integers into their ASCII character forms, the user enters "char" before an integer variable like this, and put that integer variable in brackets. Like so:

```cpp
char c = 'a';
cout << int(c) //prints 97
```

Here is my code so far. I decided to redo it and define an empty string value called "output", which is where the ciphered ascii characters go in to create a ciphered version of string s. I have created a for loop to iterate through the string, and an if statement for if the string's characters are labelled from capital A to capital Z. If this is so, then the integer ASCII values of said characters which are less than or equal to 90 are added to integer k, the rotation factor, and then converted back into characters and added to my output variable. Other integer ASCII values have 90 subtracted from them and are turned into characters, then put in output.

```cpp
string caesarCipher(string s, int k) {
    string output="";
    for (int i = 0; i < s.size(); i++) {
        if (((int)s.at(i) >= 65 && (int)s.at(i) <= 90)) {
            if ((int)s.at(i)+k <= 90) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char((int)s.at(i)+k-90);
            }
        }
        
    }
}
```

Note that 65 in ASCII character value is A, and for 90, it's Z. I have decided to do the same thing with the lowercase characters. Lowercase a in ASCII integer is 97, and for Lowercase z, it's 122.
This is my code now.

```cpp
string caesarCipher(string s, int k) {
    string output="";
    for (int i = 0; i < s.size(); i++) {
        if (((int)s.at(i) >= 65 && (int)s.at(i) <= 90)) {
            if ((int)s.at(i)+k <= 90) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char((int)s.at(i)+k-90);
            }
        }
        else if (((int)s.at(i) >= 97 && (int)s.at(i) <= 122)) {
            if ((int)s.at(i)+k <= 122) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char((int)s.at(i)+k-122);
            }
    }
}
}
```

However when I noticed that the second else statement would cause an error at some cases, I commented it out. In fact, I commented out all the if statements and just left the output statement in the lowercase feature of the method.

```cpp
string caesarCipher(string s, int k) {
    string output="";
    for (int i = 0; i < s.size(); i++) {
        if (((int)s.at(i) >= 65 && (int)s.at(i) <= 90)) {
            if ((int)s.at(i)+k <= 90) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char((int)s.at(i)+k-90);
            }
        }
        else if (((int)s.at(i) >= 97 && (int)s.at(i) <= 122)) {
            output+= char((int)s.at(i)+k);
    }
}
return output;
}
```

You know what? I'm just going to undo and keep those if statements. And since that's not enough I edited line 25, or the output incrementation in the uppercase if statement, if the integer form of the characters are more than 90.
What I did was add 65 to the integer and then subtract 1 from it. It's for crossing Z and returning from A again.

```cpp
string caesarCipher(string s, int k) {
    string output="";
    for (int i = 0; i < s.size(); i++) {
        if (((int)s.at(i) >= 65 && (int)s.at(i) <= 90)) {
            if ((int)s.at(i)+k <= 90) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char(65+(int)s.at(i)+k-90-1); //the portion to cross the Z, go back from A again
            }
        }
        else if (((int)s.at(i) >= 97 && (int)s.at(i) <= 122)) {
            if ((int)s.at(i)+k <= 122) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char((int)s.at(i)+k-122);
            }
    }
}
return output;
}
```

After I ran the file, I noticed that I converted a part of a sample input correctly, except that I forgot to include a special character of the said correct output. So, I added an else statement which just appends the character into "output".

```cpp
string caesarCipher(string s, int k) {
    string output="";
    for (int i = 0; i < s.size(); i++) {
        if (((int)s.at(i) >= 65 && (int)s.at(i) <= 90)) {
            if ((int)s.at(i)+k <= 90) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char(65+(int)s.at(i)+k-90-1); //the portion to cross the Z, go back from A again
            }
        }
        else if (((int)s.at(i) >= 97 && (int)s.at(i) <= 122)) {
            if ((int)s.at(i)+k <= 122) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char((int)s.at(i)+k-122);
            }
    }
    else{
        output+=s.at(i);
        
    }
}
return output;
}
```

This time I actually included the special character in the correct output, except that I missed a lowercase letter which was near Lowercase a. I just need one final touch to the code, in the else statement. If the string has a z in it, then it should return to a and then finish counting by its rotation to cipher. For example, z in a string in rotation 2 should land on b, so in the cipher translation, the b is in place of the z in the original string.

```cpp
string caesarCipher(string s, int k) {
    string output="";
    for (int i = 0; i < s.size(); i++) {
        if (((int)s.at(i) >= 65 && (int)s.at(i) <= 90)) {
            if ((int)s.at(i)+k <= 90) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char(65+(int)s.at(i)+k-90-1); //the portion to cross the Z, go back from A again
            }
        }
        else if (((int)s.at(i) >= 97 && (int)s.at(i) <= 122)) {
            if ((int)s.at(i)+k <= 122) {
                output+= char((int)s.at(i)+k);
            }
            else {
                output+= char(97+(int)s.at(i)+k-122-1);
            }
    }
    else{
        output+=s.at(i);
        
    }
}
return output;
}
```

It worked on the run, but it didn't work for other answers. The reason why it didn't work for the other answers was because if the rotation number was insanely large, or more than 26, then the code would not work. So, I made a new integer called newK to store the remainder of the large rotation numbers divided by 26. I then replaced the other "k"'s with my newK variable. Here is my working method.

```code
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
```

## Grid

I started with a for loop iterating through the vector in the parameter brackets, then inside that for loop, iterate through the vector's items. I have not finished this method yet.

```cpp
string gridChallenge(vector<string> grid) {
    vector<string>grid2;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].length(); j++) {
            
        }
    }
}
```
**11/5/2021**

I had to make major changes to my code. First, I sorted the items in the vector named "grid", then introduced a new string called workString, to store the letters. I decided to put most of the function into an iterator of the entire grid vector. Inside the for loop for the vector, the first for loop would check if the number inputs were ASCII letters when converted. If the workString was still empty, then the for loop would continue. If the workString characters were sorted, then the loop would also continue. It would continue until none of those functions happened, in which case the function would return "no."
```cpp
string gridChallenge(vector<string> grid) {
    
    std::sort(grid.begin(), grid.end());
    string workString="";
    for (string s:grid)
    {
        for (int i = 0; i < s.size(); i++) {
            if (int(s.at(i)) >= 97 && int(s.at(i)) <= 122) {
                workString+=s.at(i);
            }
        }
        if (workString.size()==0){
            continue;
        }
        if (is_sorted(workString.begin(), workString.end())) {
            continue;
        }
        else {
            return "NO";
        }
        
    }
    return "YES";

}
```

UPDATE: Since the entire code did not work, I had to start over. I was supposed to have the vertical columns of the vector be in alphabetical order to return "yes", not the horizontal ones.
Here is my code. Here, I made two boolean variables to go through the first and second lines of the grid. I started with the grid, then looked for the first and second lines, and also converted the characters of the grid items into integers. I am currently woring on filling up the newGrid which I have created. 

```cpp
string gridChallenge(vector<string> grid) {   
    bool firstLineEncounter=false;
    bool secondLineEncounter=false;
    int numCase=0;
    int numLineColumn=0;
    for (string s:grid)
    {
       if (firstLineEncounter==false && secondLineEncounter==false)
       {
           numCase=stoi(s);
           firstLineEncounter=true;
       }
       else if (firstLineEncounter==true && secondLineEncounter==false)
       {
           numLineColumn=stoi(s);
           secondLineEncounter=true;
       }
       else
       break;
    }
    std::vector<vector<string>> newGrid(numLineColumn, vector<string> (numLineColumn));
    //fill up the newGrid
    
    
    
    
    return "YES";

}
```

Notice that the first line of the string is the number of the cases, and the second one is the number of columns. The third one will be the actual grid, and it will return "yes" if all of its vertical lines are in alphabetical order. For example, this input should return "yes". It is one of the test runs in Hackerrank.

>>> 1
>>>
>>>5
>>>
>>>eabcd
>>>
>>>fghij
>>>
>>>olkmn
>>>
>>>trpqs
>>>
>>>xywuv

**11/6/2021**

I have recently updated my code by once again using the sort function on the grid, as well as making a new vector called "newGrid". There, I was to store all the vertical lists from the grid vector. I first iterated through the original grid and inserted the grid items inside the newGrid vector. I also bought back the workString empty string to store each vertical line, and if it was sorted, then it would turn back into an empty string as the program continues iterating through newLineColumn. However if none of the lists were sorted, the program would return "NO". If the program found all the lines in alphabetical order, it would return "YES".

```cpp
string gridChallenge(vector<string> grid) {   
    bool firstLineEncounter=false;
    bool secondLineEncounter=false;
    int numCase=0;
    int numLineColumn=0;
    for (string s:grid)
    {
       if (firstLineEncounter==false && secondLineEncounter==false)
       {
           numCase=stoi(s);
           firstLineEncounter=true;
       }
       else if (firstLineEncounter==true && secondLineEncounter==false)
       {
           numLineColumn=stoi(s);
           secondLineEncounter=true;
       }
       else
       break;
    }
  //  std::vector<vector<string>> newGrid(numLineColumn, vector<string> (numLineColumn));
    //fill up the newGrid
    
    
    
    std::sort(grid.begin()+2, grid.end());
    vector<string> newGrid(numLineColumn); //new grid
    for (int i = 0; i < grid.size(); i++) {
        if (i<2)
        {
            continue;
            }
        else {
            newGrid[i]=grid.at(i);
        }
    }
    string workString="";
    for (int i=0;i<numLineColumn;i++) {
        for (string s:newGrid)
        {
            workString+=s[i];
            
            
                 
        }
       if (is_sorted(workString.begin(), workString.end())) {
           workString="";
           continue;
           
       } 
       else {
           return "NO";
       }
    }
    
    
    return "YES";

}
```

I ran this code but got some errors; the stoi did not compile. I made some updates to try to fix the code.

```cpp
string gridChallenge(vector<string> grid) {   
    bool firstLineEncounter=false;
    bool secondLineEncounter=false;
    int numCase=0;
    int numLineColumn=0;
    for (string s:grid)
    {
       if (firstLineEncounter==false && secondLineEncounter==false)
       {
           if (any_of(s.begin(), s.end(), ::isdigit))
           {
           numCase=stoi(s);
           firstLineEncounter=true;
           }
       }
       else if (firstLineEncounter==true && secondLineEncounter==false)
       {
           if (any_of(s.begin(), s.end(), ::isdigit)) {
           numLineColumn=stoi(s);
           secondLineEncounter=true;
           }
       }
       else
       break;
    }
  //  std::vector<vector<string>> newGrid(numLineColumn, vector<string> (numLineColumn));
    //fill up the newGrid
    
    
    
    std::sort(grid.begin()+2, grid.end());
    vector<string> newGrid(numLineColumn); //new grid
    for (int i = 0; i < grid.size(); i++) {
        if (i<2)
        {
            continue;
            }
        else {
            newGrid[i]=grid.at(i);
        }
    }
    string workString="";
    for (int i=0;i<numLineColumn;i++) {
        for (string s:newGrid)
        {
            workString+=s[i];
            
            
                 
        }
       if (is_sorted(workString.begin(), workString.end())) {
           workString="";
           continue;
           
       } 
       else {
           return "NO";
       }
    }
    
    
    return "YES";

}
```

That didn't work either, because I noticed that I misunderstood the entire question.
I had to remove all instances of the newGrid vector and more things, and here is my code so far.

```cpp
string gridChallenge(vector<string> grid) {   
 
  //  std::vector<vector<string>> newGrid(numLineColumn, vector<string> (numLineColumn));
    //fill up the newGrid
    
    
    
    std::sort(grid.begin(), grid.end());
    string workString="";
    for (int i=0;i<grid.size();i++) {
        for (string s:grid)
        {
            workString+=s[i];
        }
       if (is_sorted(workString.begin(), workString.end())) {
           workString="";
           continue;
           
       } 
       else {
           return "NO";
       }
    }
    
    
    return "YES";

}
```

I ran my code for the first two sample test cases and it worked, but as for the official test cases, it didn't work. This is because again, I didn't understand the question well. The user was supposed to enter a number for the number of cases, then another number for the size of the array. The number of cases means that for example if the user enters 3, then they were to enter three arrays, but they can make a different size for each array they make.

```cpp
string gridChallenge(vector<string> grid) {   
 
  //  std::vector<vector<string>> newGrid(numLineColumn, vector<string> (numLineColumn));
    //fill up the newGrid
    
    
   
    for (int i = 0; i < grid.size(); i++) {
        sort(grid.at(i).begin(), grid.at(i).end()); //sort by itself in place

    }
    string workString="";
    for (int i=0;i<grid.size();i++) {
        for (string s:grid)
        {
            workString+=s[i];
            
            
                 
        }
       if (is_sorted(workString.begin(), workString.end())) {
           workString="";
           continue;
           
       } 
       else {
           return "NO";
       }
    }
    
    
    return "YES";

}
```
The code ended up working. In order to flip a 2-D vector, the user is to make an empty string and iterate through the vector, and then add each character of the vector's items in the empty string via this method, inside a for loop iteration of the vector.

```cpp
for (type) s : (vector name)
{
emptyString = s[i];
}
```

I don't know if this is correct, I will have to try and learn it via the online C++ compiler.

## Recursive functions

All I can say here is a few things.
This is how to turn a character into an integer, without using the ASCII methods.

```cpp
int = char - 48
```

**11/7/2021**

This is my answer for the Recursive function. I noticed I had to assign each character before subtracting 48 from them, as well as multiply k to the long sum, since other test answers contained an insanely long number. 

```cpp
int superDigit(string n, int k) {
    long sum=0;
    for (int i=0;i<n.size();i++)
    {
        sum+=int(n.at(i))-48;       
    }
    sum*=k;
    if (sum<10)
    {
        return sum;
    }
    else {
        return superDigit(to_string(sum), 1);
    }
    
    
    
}
```

<<<<<<< HEAD
## Queue

This is my recent code on this challenge. I recieved errors when running the code.

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int numberOfQuery;
    int numberOfChoice;
    int enqueue;
    string query;
    vector <int> inStack;
    vector <int> outStack;
    cin >> numberOfQuery;
   // std::iostream::getline( numberOfChoice, enqueue );
    for (int i = 0; i < numberOfQuery; i++) {
        cin >> noskipws >> query;
        if (query.at(0) == 1) {
            inStack.push_back(query.at(1));
        }
        else if (query.at(0) == 2) {
            outStack.pop_back();
        }
        else if (query.at(0)== 3) {
            cout << inStack.at(0);
        }
    }  
    
    return 0;
}
```

I just changed some things in my code, especially in the query choices parts, where I added more if statements. I also noticed that the erase function removes a certain item from the vector, and the nosipws part would allow the user to enter an item with a space. 

```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int numberOfQuery;
    int numberOfChoice;
    int enqueue;
    string query;
    vector <int> inStack;
    vector <int> outStack;
    cin >> numberOfQuery;
   // std::iostream::getline( numberOfChoice, enqueue );
    for (int i = 0; i < numberOfQuery; i++) {
        cin >> noskipws >> query;
        if (query.at(0) == 1) {
            inStack.push_back(query.at(1));

        }
        else if (query.at(0) == 2) {
            if (outStack.size() == 0) {
                  if (inStack.size() > 0) {
                    outStack.push_back(inStack.at(0));
                    inStack.erase(inStack.begin());
                  }
            }
            if (outStack.size() > 0) {
                outStack.pop_back();
            }
            //outStack.pop_back();
        }
        else if (query.at(0)== 3) {
            if (inStack.size() > 0) {
                cout << inStack.at(0);
            }
        }
    }  
    
    return 0;
}

```
Here is my updated code, after some changes. 
```cpp
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>      // std::istringstream
using namespace std;
  
  
int main() {
    int firstTime=1;
    int numberOfQuery;
 //   int numberOfChoice;
 //   int enqueue;
    string query;
    vector <string> inStack;
    vector <string> outStack;
    cout << "Enter number of queries" << endl;
    cin >> numberOfQuery;
   // std::iostream::getline( numberOfChoice, enqueue );
    for (int i = 0; i < numberOfQuery; i++) {
        cout << "Enter query" << endl;
        if (firstTime==1)
        {
            getline(cin,query);
            firstTime=0;
        }
        getline(cin,query);
        cout << "Original string: " << query << endl;
            std::istringstream stream(query);
            std::string type;
            std::string element;


            stream >> type >> element;

        cout << "hi "<< type << endl;
        if (type == "1") {
            inStack.push_back(element);
            cout << "hello "<<inStack.at(0) << endl;
  
        }
        else if (type == "2") {
            if (outStack.size() == 0) {
                  if (inStack.size() > 0) {
                    outStack.push_back(inStack.at(0));
                    inStack.erase(inStack.begin());
                  }
            }
            if (outStack.size() > 0) {
                outStack.pop_back();
            }
            //outStack.pop_back();
        }
        else if (type== "3") {
            if (inStack.size() > 0) {
                cout << inStack.at(0) << endl;
            }
        }
    }
    
    return 0;
}

```

## Text Editor

Requirement:
Implement a simple text editor. The editor initially contains an empty string, . Perform  operations of the following  types:

append - Append string  to the end of .
delete - Delete the last  characters of .
print - Print the  character of .
undo - Undo the last (not previously undone) operation of type  or , reverting  to the state it was in prior to that operation.
Example



operation
index   S       ops[index]  explanation
-----   ------  ----------  -----------
0       abcde   1 fg        append fg
1       abcdefg 3 6         print the 6th letter - f
2       abcdefg 2 5         delete the last 5 letters
3       ab      4           undo the last operation, index 2
4       abcdefg 3 7         print the 7th characgter - g
5       abcdefg 4           undo the last operation, index 0
6       abcde   3 4         print the 4th character - d
The results should be printed as:

f
g
d
Input Format

The first line contains an integer, , denoting the number of operations.
Each line  of the  subsequent lines (where ) defines an operation to be performed. Each operation starts with a single integer,  (where ), denoting a type of operation as defined in the Problem Statement above. If the operation requires an argument,  is followed by its space-separated argument. For example, if  and , line  will be 1 abcd.

Constraints

The sum of the lengths of all  in the input .
The sum of  over all delete operations .
All input characters are lowercase English letters.
It is guaranteed that the sequence of operations given as input is possible to perform.
Output Format

Each operation of type  must print the  character on a new line.

Sample Input

STDIN   Function
-----   --------
8       Q = 8
1 abc   ops[0] = '1 abc'
3 3     ops[1] = '3 3'
2 3     ...
1 xy
3 2
4 
4 
3 1
Sample Output

c
y
a
Explanation

Initially,  is empty. The following sequence of  operations are described below:

. We append  to , so .
Print the  character on a new line. Currently, the  character is c.
Delete the last  characters in  (), so .
Append  to , so .
Print the  character on a new line. Currently, the  character is y.
Undo the last update to , making  empty again (i.e., ).
Undo the next to last update to  (the deletion of the last  characters), making .
Print the  character on a new line. Currently, the  character is a.

I had to include a struct, and some functions on appending, deleting, and undoing in the textfile. This is my current code:

```cpp
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

```
=======
## New Year Chaos

I had to iterate through the queue size, and subtract i+1 from each number in the queue. If it was greater than 0, then the bribe would subtract 1. Unless it was too chaotic, or the result of the i-1 subtracted from the queue number was greater than 2, it would print out the bribe.

```cpp
void minimumBribes(vector<int> q) {
int bribe=0;
for (int i=0;i<q.size();i++){
    if (q.at(i)-i-1>2){
        cout << "Too chaotic" << endl;
        return;
 //       bribe+=q.at(i)-i+1;
    }
    if (q.at(i)-i-1 >0)
        bribe+=q.at(i)-i-1;
}

    cout << bribe << endl;

    
    

}
```
>>>>>>> 95b99ca274737264b2b51b6cf971b1c89628992d
