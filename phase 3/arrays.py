# ARRAYS
# ======
# A collection of elements stored in contiguous memory.
# Each element is the same data type, accessed instantly by index.

# Big O Notation
# O(1)      - Constant time - array access by index
# O(n)      - Linear time - looping through array
# O(n^2)    - Quadratic time - nested loops
# O(log n)  - Logarithmic time - binary search

# Array Operation Complexities
# Access by index  - O(1) - direct memory jump
# Search for value - O(n) - may check every element
# Insert at end    - O(1) - just add to end
# Insert at middle - O(n) - everything after must shift
# Delete at middle - O(n) - everything after must shift

# enumerate() gives both index and value when looping
# for i, num in enumerate(numbers) -> i is index, num is value

# ── Examples ──────────────────────────────────────────

numbers = [10, 20, 30, 40, 50]

# O(1) - direct access
print(numbers[2])

# O(n) - search
target = 30
for i, num in enumerate(numbers):
    if num == target:
        print(f"Found at index {i}")
        break

#output:
# Found at index 2, and direct access will print 30 

# Two pointer technique - O(n)
def find_pair(nums, target):
    left = 0
    right = len(nums) - 1
    
    while left < right:
        current_sum = nums[left] + nums[right]
        if current_sum == target:
            return (left, right)
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    
    return None

nums = [1, 3, 5, 7, 9]
print(find_pair(nums, 10))

#this code is trying to find pairs and it sets left to 0 and right to the amount of nums there are subtracted by 1
#if left is greater than right we want to add the left number and the right number to the sum 
#if the sum is the same number as the target then we rteurn both left and right
#if the sum is less than the target then we add one to the left if not we subtract one to the right
#since we have nums 1,3,5,7,9 we are going to do that list and the target is 10
#left is 0 and right is 5-1 which is 4. since left is less than right then we will add both the first index and the fourth index
#that will make the current sum 1+9 which is 10 and since that is our target number we will go ahead and return (0,4)

# Sliding window - O(n)
def max_sum_subarray(nums, k):
    window_sum = sum(nums[:k])
    max_sum = window_sum
    
    for i in range(k, len(nums)):
        window_sum += nums[i] - nums[i - k]
        max_sum = max(max_sum, window_sum)
    
    return max_sum

nums = [2, 1, 5, 1, 3, 2]
print(max_sum_subarray(nums, 3))
# SLIDING WINDOW - O(n)
# Used to find max/min sum of a subarray of size k
# Instead of recalculating the whole window each time,
# slide it by adding the new right element and removing the old left element

# Formula: window_sum = window_sum + nums[i] - nums[i - k]
# i = current right edge of window
# i - k = element falling off the left edge

# Trace for nums = [2, 1, 5, 1, 3, 2], k = 3
# Initial window: nums[:3] = [2, 1, 5] -> window_sum = 8, max_sum = 8
# i=3: window_sum = 8 + nums[3] - nums[0] = 8 + 1 - 2 = 7, max(8,7) = 8
# i=4: window_sum = 7 + nums[4] - nums[1] = 7 + 3 - 1 = 9, max(8,9) = 9
# i=5: window_sum = 9 + nums[5] - nums[2] = 9 + 2 - 5 = 6, max(9,6) = 9
# Output: 9 (window [5, 1, 3])

# TWO POINTER - O(n)
# Used to find pairs in a sorted array that sum to a target
# left starts at 0, right starts at end
# if sum < target -> move left pointer right
# if sum > target -> move right pointer left
# if sum == target -> found the pair

# Trace for nums = [1, 3, 5, 7, 9], target = 10
# left=0, right=4: 1+9=10 == target -> return (0, 4)

#exercise 1

def find_max(nums):
    start = nums[0]
    for num in nums:
        if num > start:
            start = num
    
    return start 

first = [1,2,3,4,5,6]
print(find_max(first))

#this is O(n) because itll have to go through each number in the list till we get to the largest 
#the output is 6 and its O(n)

def has_duplicate(nums):
    seen = [ ]
    for num in nums:
        if num not in seen:
            seen.append(num)
        else:
            return True
    
    return False

first = [1,2,3,4,5,5,6]
print(has_duplicate(first))

def has_duplicate(nums):
    seen = set()
    for num in nums:
        if num in seen:
            return True
        seen.add(num)
    
    return False

first = [1,2,3,4,5,5,6]
print(has_duplicate(first))

#remember set is an unordered collection of unique items, no duplicates
#time complexity is O(n^2) since it has to go through the list and check seen but if i used a set it would be O(n)
#space complexity is also O(n) has ive created a new list inside the function to store results 

#exercise 3

def two_sum(nums, target):
    seen = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in seen:
            return (seen[complement], i)
        seen[num] = i

#if we have a list [2,7,11,15] and the target is 9
# we first will do 9 - 2 which is the first number which is 7
#we check if 7 is in the dictionary seen if it is well return that number and its index 
#and we store that number as the key and its index as the value so when we later find a complement we can look up where it was 

def find_complement(nums, target):
    seen = set()
    for num in nums:
        if (target - num) in seen:
            return True
        else:
            seen.add(num)
    
    return False

first = [3,5,8,2]
print(find_complement([3,5,8,2], 10))

def find_first_duplicate(nums):
    seen = set()
    dup = set()
    for num in nums:
        if num in seen:
            return num
        else:
            seen.add(num)
        
    return -1

first = [3,1,4,2,3,5]
print(find_first_duplicate(first))

def longest_unique_subarray(nums):
    left = 0
    window = set()
    max_length = 0

    for right in range(len(nums)):
        while nums[right] in window: #if this number is a duplicate
            window.remove(num[left]) #why? what does this have to do with what were doing 
            left += 1 #i understand this as itd change the index
        window.add(nums[right])
        max_length = max(max_length, right - left + 1)


def longest_unique_subarray(nums):
    start = 0
    window = set()
    max_length = 0

    for current in range(len(nums)):
        while nums[current] in window: #this number is a duplicate
            window.remove(nums[start])
            start += 1
        window.add(nums[current]) #adding that number since there is no longer a duplicate
        max_length = max(max_length, current - start + 1)


#Pattern 1: Use a set or dictionary when you need O(1) lookup. Never use a list for membership checking in interview problems.
#Pattern 2: Two pointers work on sorted arrays. Sliding window works on subarrays where you need to track a window of elements.
#Pattern 3: Always state both time AND space complexity in interviews. One without the other is an incomplete answer.
#Pattern 4: The while loop inside a sliding window shrinks from the left until the conflict is resolved. if/else only handles it once — not enough.
