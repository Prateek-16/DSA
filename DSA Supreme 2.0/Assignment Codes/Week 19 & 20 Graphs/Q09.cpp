//https://leetcode.com/problems/accounts-merge/description/


/*

Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]

Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.

Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]

Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]

*/


/*
Approach - So Lets understand the question
we are give a dat of person name and its email ids we want to merege the person with same mails in different datablocks

so we know to merge any thing we can using Findparent and unionset funtions, so we will use them

Flow :
1. First we will create a map of String to integer where string is the mail and integer is the index where that mail is found
2. so we will itarate over the account input and then loop from 1st index to end :
    This will give us all the mails for that person 
    we will check if the mail is already present in the map:
    if true : means same person is already present so we will merege these 2 components
        using unionSet in index i and the index where the mail is present in the map ie mp[mail]
    if false : means this person is not present in the map so create a new entry
3. now we will create a <int to set of< string > > map
    this map will be preAns int is the index of the component and set of string will contain all the mails for that component
4. then we will itrate on previouse map using itration it:
        toh it.first will be mail
            it.second will be index 
        hume it.second ka parent node nikalna padhega beacuse maint to parent node hai baki toh uski copy hai
        then is parent node par hum insert kardenge mail (it.first)
5. loop end hone par humara pre answer will be ready but we need to return in string format
6. So we will again loop on this new map :
    it.first will be the index, so is index ke 0th element se hum apna name lenge
        ie accounts[index][0] ; yeh name ek vector of string mai pushback hoga
    it.second will be a set of string :
        so is set firse loop karke mails ko vector of string mai pushback kar denge
    then jab ek it ke lye pura vector string ready ho then we will push this vector<string> in final ans ie vector of vector string
7. return ans.
*/