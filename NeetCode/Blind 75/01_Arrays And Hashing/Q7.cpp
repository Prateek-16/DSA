//https://neetcode.io/problems/string-encode-and-decode

/*
Design an algorithm to encode a list of strings to a single string. The encoded string is then decoded back to the original list of strings.

Please implement encode and decode

Example 1:

Input: ["neet","code","love","you"]

Output:["neet","code","love","you"]
*/

/*
Approch - So we need to design a encode and decode so what we decide is 
Input ["neet","code","love","you"]   Decoded string - [4#neet4#code4#love3#you]  format - ' str.length + "#" + str '

so we do this incoding beacuse we will get to know how many characters are the in the string and then we can move that many characters and return or store that string

so encoding is easy :
simply itrate on the input vector and encode the given vector<string> 
in this format - ' str.length + "#" + str ' for each individual string.

Now decoding :
so we know 1st we need a number so one loop will be this end of the string length and another loop until we find the symbol #
we will use the substr function to get the length number then and convert it to integer type.
then we will from another subtring of the above length which will be over decoded string.
*/