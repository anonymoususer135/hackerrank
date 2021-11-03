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

And for turning integers into their ASCII character forms, the user enters (char) before an integer variable like this.

```cpp
char c = 'a';
cout << int(c) //prints 97
```
