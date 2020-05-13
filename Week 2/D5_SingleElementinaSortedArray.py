"""
#Solution
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.
"""
#Solution
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l=0
        r=len(nums)-1
        while(l<r):
            mid=l+(r-l)//2
            #print("l,r,mid",l,r,mid)
            if(nums[mid+1]==nums[mid]):
                #print(nums[mid+1],nums[mid])
                if((r-mid)%2==0):
                    l=mid+2
                else:
                    r=mid-1
            elif(nums[mid]==nums[mid-1]):
                #print(nums[mid-1],nums[mid])
                if((r-mid)%2==0):
                    r=mid-2
                else:
                    l=mid+1
            else:
                return nums[mid]
        return nums[l]
