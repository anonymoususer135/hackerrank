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
