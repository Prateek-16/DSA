//https://www.codingninjas.com/studio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047


//Sum of minimum and maximum elements of all subarrays of size “K”


/*
You are given an array consisting of N integers, and an integer, K. 
Your task is to determine the total sum of the minimum element and the maximum element of all subarrays of size K.

Note :

The array may contain duplicate elements.
The array can also contain negative integers.
The size of the array is at least 2.
There exists at least one such subarray of size k.

Sample Input 1 :
1
5 3
1 2 3 4 5

Sample Output 1 :
18

Explanation for sample input 1 :

For the subarray starting from the 0th index and ending at the 2nd index, 
its minimum element is 1 and the maximum element is 3. 
Similarly, for the next subarray starting at the 1st index and ending at the 3rd index, 
the minimum value is 2 and the maximum is 4. And, for the last subarray, the minimum value is 3 and the maximum is 5. 
So, the total sum will be 1 + 3 + 2 + 4 + 3 + 5 = 18.

Sample Input 2 :
1
6 4
2 4 7 3 8 1

Sample Output 2 :
29

Explanation for sample input 2 :

For the subarray starting from the 0th index and ending at the 3rd index, 
its minimum element is 2 and the maximum element is 7. 
Similarly, for the next subarray starting at the 1st index and ending at the 4th index, 
the minimum value is 3 and the maximum is 8. And, for the last subarray, 
the minimum value is 1 and the maximum is 8. So, the total sum will be 2 + 7 + 3 + 8 + 1 + 8 = 29.
*/


/*
Approach - So this is a sliding window Question.

Steps Hote hai kuch 
1. 1st Kth elements ko window mai dalo
2. the Kth se Last element tak window chalao
3. the last element wale ke lye dobara answer find kare beacuse woh reh jata hai.

Now Main step is Elements insert kaise karne hai window mai
Dekh sliding window ki main baat yeh hoti hai ki jo sabse pehele element ata hai window mai woh nikalta hai hai, 
toh agar maximum find karna hai window ka toh dekho agar mai new element dal raha hu toh make sure karna ki isse pehele koi usse chota element na ho,


esa kareke tune first K elements ki window bana li, Now move from K toh nums.size()
Now 3 Operation perform karne hai :
1. queue ke top index ko store kar lo ( yeh 1st window ka maximum / minimum index hoga)
2. Now Because the window is moving forward we need to remove the lements out of the window index
    toh jabtak queue front is less than i - k, pop from front
3. Now New element insert karna hai :
    toh jabtak queue back is less than new element , then pop()
4. Now new element insert kar do

*/


long long maxSlidingWindow(vector<int>& nums, int k) {
        long long ans = 0;
        deque<int> dq;
		deque<int> dq2;
        for (int i = 0; i < k; i++) {

            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
			 while (!dq2.empty() && nums[dq2.back()] >= nums[i]) {
                dq2.pop_back();
            }
            dq.push_back(i);
			dq2.push_back(i);
        }

        for (int i = k; i < nums.size(); i++) {
            //ans.push_back(nums[dq.front()]);
			ans = ans + nums[dq.front()] + nums[dq2.front()];
            // removal
            while (!dq.empty() && i - k >= dq.front()) {
                dq.pop_front();
            }
			while (!dq.empty() && i - k >= dq2.front()) {
                dq2.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
			while (!dq2.empty() && nums[dq2.back()] >= nums[i]) {
                dq2.pop_back();
            }


            // addition
            dq.push_back(i);
			dq2.push_back(i);
        }
        ans = ans + nums[dq.front()] + nums[dq2.front()];
        return ans;
    }


long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
	long long ans = maxSlidingWindow(nums,k);
	return ans;
}