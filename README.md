# hackerrank

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
