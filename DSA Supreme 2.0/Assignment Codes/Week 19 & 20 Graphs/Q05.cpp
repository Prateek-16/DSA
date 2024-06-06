//https://www.geeksforgeeks.org/problems/word-ladder-ii/1


/*

Given two distinct words startWord and targetWord, and a list denoting wordList of unique words of equal lengths. 
Find all shortest transformation sequence(s) from startWord to targetWord. You can return them in any order possible.

Keep the following conditions in mind:

    ~ A word can only consist of lowercase characters.
    ~ Only one letter can be changed in each transformation.
    ~ Each transformed word must exist in the wordList including the targetWord.
    ~ startWord may or may not be part of the wordList.
    ~ Return an empty list if there is no such transformation sequence.

Example 1:

Input:
startWord = "der", targetWord = "dfs",
wordList = {"des","der","dfr","dgt","dfs"}

Output:
der dfr dfs
der des dfs

Explanation:
The length of the smallest transformation is 3.
And the following are the only two ways to get
to targetWord:-
"der" -> "des" -> "dfs".
"der" -> "dfr" -> "dfs".

Example 2:

Input:
startWord = "gedk", targetWord = "geek", 
wordList = {"geek", "gefk"}

Output:
"gedk" -> "geek"

*/

/*
Approach :
Short : 1. BFS Traversal karenge
2. Queue mai vector of string store karenge so set of transformation bataega
3. ek Important cheez Prev question mai jaise hi word find ho raha tha hum stack se delete kar rahe the but yaha hume immediately delete nahi karna stack se
    beause ek word jo find hua hai woh same word same level par kisi durse word se bhi toh find ho sakta hai
    for eg Hit - So HAT and HOT can both find word HIT
    islye ek level integer mentain karna hoga jo yeh note kare ki same level par jab tak hai tab tak word delete na kare set se
    next level par chale gye toh erase kar de , 
    uske liye hume current level pare sare use hue words ko store karna pdhega.
4. so ek Vector bana lenge usedWords nam ka and woh vector same level par find hye newWords ko store karega
5. jab bhi new level par jaenge then usedWords par itrate karke sare word set se erase kar denge
6. par pata kaise chalega new level hai ?
    dekho jo vector hume q top se milega agar us vector ka size ek level nam ka variable mentain karenge usse xyada ho gya then
    we will say this is new level so level++
    and erase the usedwords

So yahi crux hai main 
then ans return karte time :
    if qtopword == endword :
        then check if ans is empty , then push directly
        if not empty then only push if the size of the vector we are abou to push is equal to the previous vector in the answer array.
    
FLow OF CODE :
    1. initialise a vector<string> queue 
    2. Initialise a Set for wordList
    3. Initialise a vector<string> usedWords
    4. Initialise a variable level = 0;

    5. push source word into the queue
    6. push source word into usedWords

    Loop until queue is empty :
        1. get top vector in the queue and pop()
        2. check if vector size is more than the level
            if true : Means we need to increase the level and erase all usedWords from the set
        3. store the last word of your top vector
        4. Check if this last word == end Word
            if True : then see if the answer vector is empty or not
                if empty : then push the top vector
                if Not empty : then onlu push top vector if its size is equal to ans[0].size()
        5. Now Do regular double for loop to check each character and replacing it with 'a' to 'z'
        6. if newWord is found in the set :
            push newWord into Usedwords
            push NewWord into top vector
            push Top vector into the queue
            pop() top vector (we are Popping the top vector beacause other words can also be reach here at the same level)
    7. If Outside the while loop means : 
        return -1;
*/