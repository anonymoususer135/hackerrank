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
