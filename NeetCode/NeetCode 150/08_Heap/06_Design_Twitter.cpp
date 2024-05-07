//https://leetcode.com/problems/design-twitter/description/


/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
 

Example 1:

Input
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
Output
[null, null, [5], null, null, [6, 5], null, [5]]

Explanation
Twitter twitter = new Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
*/


/*
Approach - There will be no use of the heap in this approach, basically beacuse we will use a vetor. 
    So we need to mentain a follower list ie 
    hash map: {user -> people they follow(this will be a set for easily searching)...}
    and we need to store the tweets as they have a userId and a tweetId ie
    pairs: [user, tweet]

    So How this will work is : 
        1. We need to show the user the 10 latest tweets from his own or the list of the followers
        2. So the main function will be getNewsFeed(int userId)
            So we will recieve the userId from this function call, and we need to get all the tweets from the follower list of this userId 
            and the own tweets of this userId.
            Also the tweets should be latest to oldest
        3. So the mentain the order of the tweets we can either use a heap + map to mentain a count with the tweets or we can use a vector
        using a vector is much simplier as we will simply pushBack all the tweets in a vector and then we will access them from the end.
        then we will automatically have the tweets in the latest order

    So lets first implement the follow and unfollow function :
        Follow :
            Simply mentain the list of all the user and the list of other users they follow
            so that will be a map of {int to a set}
        UnFollow : 
            Simply access the userId and remove the other user from the list of the followers
            but can also check that the user exist in the follower list beforehand

        That's it form these 2 Functions

        Now we have add tweet function with parameter {int userId, int tweetId}
        simply ek vector bana lena sare tweets ko store karne ke lye and then last se access kar lena latest tweets ke lye

        So add tweet function mai bas vector mai pair{userId, tweetId} pushBack kar dena

    Now the Most important function 
    getNewsFeed(UserId)
        This function will return the vector of 10 latet tweets which can be tweets from the person itself or the follower list 
            so we have the userId which is the id of the person
            we also have a map which maps userId -> with set of the followers they have

            tho Kaise karenge ise : 
                Tweets wale vector par ulta itrate karenge and waha se hume 2 cheeze milengi :
                    pairs: [userId, tweetId]

                ek unordered_set aur nikal lenge : 
                    woh set hoga given userId ke follower ka set

                now 2 conditions check karenge :
                    1. ya toh tweets wali userId same have input function wali userId ke ( this means ki tweet us user ka khud ka hai)
                    2. ya fir tweets wali userId ko find karenge followers ke set mai, and agar != end ata hai that means ki kisi follower ne tweet kara hai
                        se use hi apne result vector mai add kar lenge
                    
                    Ek count variable mentain kar lena so that only 10 time hi yeh kare and after that loop break ho jae
                    outside the loop return the result vector
                    


*/