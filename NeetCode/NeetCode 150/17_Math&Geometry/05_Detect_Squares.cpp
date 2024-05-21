//https://leetcode.com/problems/detect-squares/description/


/*
You are given a stream of points on the X-Y plane. Design an algorithm that:

Adds new points from the stream into a data structure. Duplicate points are allowed and should be treated as different points.
Given a query point, counts the number of ways to choose three points from the data structure such that the three points and the query point form an axis-aligned square with positive area.
An axis-aligned square is a square whose edges are all the same length and are either parallel or perpendicular to the x-axis and y-axis.

Implement the DetectSquares class:

DetectSquares() Initializes the object with an empty data structure.
void add(int[] point) Adds a new point point = [x, y] to the data structure.
int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] as described above.
 

Example 1:


Input
["DetectSquares", "add", "add", "add", "count", "count", "add", "count"]
[[], [[3, 10]], [[11, 2]], [[3, 2]], [[11, 10]], [[14, 8]], [[11, 2]], [[11, 10]]]
Output
[null, null, null, null, 1, 0, null, 2]

Explanation
DetectSquares detectSquares = new DetectSquares();
detectSquares.add([3, 10]);
detectSquares.add([11, 2]);
detectSquares.add([3, 2]);
detectSquares.count([11, 10]); // return 1. You can choose:
                               //   - The first, second, and third points
detectSquares.count([14, 8]);  // return 0. The query point cannot form a square with any points in the data structure.
detectSquares.add([11, 2]);    // Adding duplicate points is allowed.
detectSquares.count([11, 10]); // return 2. You can choose:
                               //   - The first, second, and third points
                               //   - The first, third, and fourth points
*/


/*
Approach - we need to make 2 functions :
    1. ADD : this is just used to store the {x,y} coordinates to their frequencies
    2. COUNT : Tells how many squares are possible on taking already stored coordinates and the coordinate passed in this function

    
    Deciding the DS for storing the coordinates and their frequencies
        we may use a map of pair to int but its not possible for an unordered map so we will avoid it
        instead we will use Double unordered map 
            {x -> {y -> freq}}      // unordered_map< int, unordered_map < int, int >> points

    1. ADD (vector<int> point) :
        x co-or= point[0]
        y co-or= point[1]
        points[x][y]++;

    2. COUNT (vector<int> point) :
        1. This is the important function and this has a trick
            the trick is :
            to assume all the stored coordinates are a diagonal to the given coordinates, 
            and then find the other 2 points in the map which will be very easy.
            also we have a condition for a diagonal of a square, if we miss this condition we will include rectangles also in this result.

        let result be 0.

        let given co ordinates be :
            Px = point[0];
            Py = point[1];
        
        2. Now itrate over all stored points { x -> { y -> freq }}
            first for is from points.begin() to points.end() with itrator "x"

                x->first is x coordinate
                x->second is a unordered map lets say (y_coordinate)

                Now loop on map y_coordinate begin to end with itrator "y"

                    y->first for is y coordinate
                    y->second for is frequency of {x,y} coordinates

                    so now we have itrative {x,y} coordinates and there frequency
                    now assume this is a diagonal to the given coordinates {Px,Py}

                    conditions given to us :
                        1. Area is more than 0
                        2. Must be a square

                    1. for area to be greater than zero the diagonal points assumed cannot be the same ie Px == x1 || Py == y1
                    2. for 2 diagonal points to form a square the absolute difference between boths x coordinate and y coordinate must be the same
                        then only will be the diagonal linearly increasing otherwise it will be a rectangular diagonal.
                        ie (abs(Px - x1) != abs(Py - y1))

                    so false conditions that our current itrative point cannot be a square diagonal are :
                        if ((abs(Px - x1) != abs(Py - y1)) || Px == x1 || Py == y1 ):
                        if true : then continue.

                    3. Now we have the diagonal points {x,y} and {Px,Py} so geometrically the other 2 points of the square will be :
                        1. {Px,y} 
                        2. {x,Py}
                    
                    So for this function we need to return the number of squares possible, 
                    so we need to multiply the frequencies of each coordinate except the given coordinate {Px,Py}

                    and if any of the point is not in the map its freq will be 0, thus making final result as 0
                    therfore result += points[Px][y1] * points[x1][Py] * points[x1][y1];

                    result is added for all previous itrative values also
        
        Now both for loops ends and we have a result
        so return result
                





*/