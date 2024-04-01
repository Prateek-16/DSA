// https://leetcode.com/problems/minimum-number-of-refueling-stops/description/

// Minimum Number of Refueling Stops

/*
Approach - So we will use Greedy approach Here
we will cover the maximum distance possible with total current fuel and will store all the stations {fuel,position} in between
if our distance is not covered we will refuel and redine our dis and fuel

*/
class Solution
{
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>> &stations)
    {
        int stops = 0;
        int dist = 0;
        int i = 0;
        int fuel = startFuel;
        priority_queue<pair<int, int>> pq;
        while (true)
        {
            while (i < stations.size())
            {
                if (stations[i][0] <= dist + fuel)
                {
                    pq.push({stations[i][1], stations[i][0]});
                    // {fuel,pos} fuel is at first
                    // because we need to build the
                    // max heap using fuel ans by default
                    // it will be sorted based on first
                    // item of the pair
                }
                else
                {
                    break;
                }
                i++;
            }

            // Now Covering the Max Distance

            dist += fuel;
            fuel = 0;

            if (dist >= target)
            { // Destination reached
                break;
            }

            if (pq.empty())
            { // Destination Not Reached and No Stations available
                stops = -1;
                break;
            }
            // Destination is nOt Reached and Stations are available
            // so we will refuel and reposition ourself on the station and will update the distance and the fuel
            auto &it = pq.top();
            fuel = (dist - it.second) + it.first;
            dist = it.second;
            pq.pop();
            stops++;
        }
        return stops;
    }
};