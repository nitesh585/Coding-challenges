/*
Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Example 1:

Input:
N = 11
a[] = {1,3,5,8,9,2,6,7,6,8,9}
Output: 3
Explanation: First jump from 1st element,
and we jump to 2nd element with value 3.
Now, from here we jump to 5h element with
value 9. and from here we will jump to
last.

Example 2:

Input:
N = 6
a[] = {1,4,3,2,6,7}
Output: 2

Your Task:
Complete the function minimumJump() which takes an array and N (number of elements) as input parameters and returns the answer(if no answer possible return -1)

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 10^7
0 <= ai <= 10^7

*/

Given an array of integers where each element represents the max number of steps that can be made forward from that element. The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, then cannot move through that element.

Example 1:

Input:
N = 11
a[] = {1,3,5,8,9,2,6,7,6,8,9}
Output: 3
Explanation: First jump from 1st element,
and we jump to 2nd element with value 3.
Now, from here we jump to 5h element with
value 9. and from here we will jump to
last.

Example 2:

Input:
N = 6
a[] = {1,4,3,2,6,7}
Output: 2

Your Task:
Complete the function minimumJump() which takes an array and N (number of elements) as input parameters and returns the answer(if no answer possible return -1)

Expected Time Complexity : O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 107
0 <= ai <= 107
