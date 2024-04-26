//https://leetcode.com/problems/car-fleet/description/


/*
There are n cars going to the same destination along a one-lane road. The destination is target miles away.

You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.

 

Example 1:

Input: target = 12, position = [10,8,0,5,3], speed = [2,4,1,1,3]
Output: 3
Explanation:
The cars starting at 10 (speed 2) and 8 (speed 4) become a fleet, meeting each other at 12.
The car starting at 0 does not catch up to any other car, so it is a fleet by itself.
The cars starting at 5 (speed 1) and 3 (speed 3) become a fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
Note that no other cars meet these fleets before the destination, so the answer is 3.
Example 2:

Input: target = 10, position = [3], speed = [3]
Output: 1
Explanation: There is only one car, hence there is only one fleet.
Example 3:

Input: target = 100, position = [0,2,4], speed = [4,2,1]
Output: 1
Explanation:
The cars starting at 0 (speed 4) and 2 (speed 2) become a fleet, meeting each other at 4. The fleet moves at speed 2.
Then, the fleet (speed 2) and the car starting at 4 (speed 1) become one fleet, meeting each other at 6. The fleet moves at speed 1 until it reaches target.
*/


/*
Approach - Using stack ( there is a similar approach also without stack which is less confusing)
    Using Stack : 
        1. pair up position, speed in a vector
        2. sort the vector on based of decresing position
            means the car farthest from the target should be at 0 index
        3. Now we have Position and speed so we can find the time to reach target
        4. if the time of the car behind is less than the car in front then it means they will collide and form a fleet
        else they will not collide
        5. We will mentain a tack for each fleet and at the end return the size of the stack
        6. so suppose we have Car 1 and Car 2 st Car 1 is behind Car 2
            so if T1 > T2 then No collision
            else if T1 < T2 then collision will occur
            so hum stack mai wohi values rakhna chahate hai jab collision nahi ho , so when ever collision happens we need to pop from the stack
        7. So do a for loop on the sorted vector from 0 to n-1
            1. get the Time for this car (Dis/speed)
            2. while( stack is not empty && stack top is less than current time) // this condition means collision will happen and both cars will become same fleet
                pop from the stack
            3. After the while loop we know either the stack is empty or top time is greater than current time
            4. so push the current time in the stack
        8. After the for loop we will return the size of the stack as we know that these are all the fleet witch will not collide with each other
        
*/