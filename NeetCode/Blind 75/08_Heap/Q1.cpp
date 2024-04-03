//https://leetcode.com/problems/find-median-from-data-stream/description/


/*

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 
Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]

Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

*/

/*
Approach -  
Step 1 - Take the Input : 
    So we will divide the input stream such that ( Max Heap - Meadian - Min Heap )
    initially median will be 0
    maxHeap will have elements smaller than the median
    minHeap will have elements greater than the median

    we would like these heaps to have equal size , or a maximum size differece of 1,
    In even case ( both size are equal ) - Midian will be average of top elements of both heaps
    In odd case ( one heap greater ) - Median will be top element of greater heap

Step 2 - Now for each Input we will decide if it will go in the Max heap or the Min heap
    1.  if Size of Max Heap == Min Heap 
        1.  if input if less than median, go left ie Max heap
            else go right ie Min heap
        2.  Now Median for this case will be :
            in which ever heap the input is added, that heaps top element...

    2. if Size of Max Heap > Min Heap
        1.  if input is more than the median:
            simply add input in Min heap.
            Else we should add the input to Max heap but it is already greater, so 
            take the top element of max heap and push it into Min heap and pop it from max heap.
            Then add the input to Max heap.
        2.  Now Median will be the average of top elements of both heaps

    3. if Size of Max Heap < Min Heap
        1.  if input is less than the median:
            simply add input in Max heap.
            Else we should add the input to Min heap but it is already greater, so 
            take the top element of Min heap and push it into Max heap and pop it from min heap.
            Then add the input to Min heap.
        2.  Now Median will be the average of top elements of both heaps
*/