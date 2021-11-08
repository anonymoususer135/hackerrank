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
