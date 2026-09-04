#stacks n queues

#a stack is a collection where the last item added is the first removed. 
#Think of a stack of plates -> you add to the top and remove from the top
#LIFO -> first in first out
#they are used for whne you need to reverse things, track history, or handle nested structures
#queues are used when order matters and things need to be processed in the order they arrived
#stacks n queues can be used by using python lists
#.append() and .pop() is all you need for a stack 
#for a queue you use collections.deque (deque stands for double ended queue so its a data strutcure form puthons collections that allows O(1) for insertion and removal from both ends)
#queues are first in first out

#stacks
stack = []
stack.append(1)   # push
stack.append(2)
stack.append(3)
stack.pop()       # pop → returns 3 (last in, first out)

#queues
from collections import deque
queue = deque()
queue.append(1)    # enqueue
queue.append(2)
queue.append(3)
queue.popleft()    # dequeue → returns 1 (first in, first out)

# STACK (LIFO)          QUEUE (FIFO)
                      
# push →  [3]           enqueue →  [1][2][3]  → dequeue
#         [2]           
#         [1]           first in = first out
        
# last in = first out

#Operation	  | Stack |	Queue
#Push/Enqueue |	O(1). |	O(1)
#Pop/Dequeue  |	O(1). |	O(1)
#Peek (see top)| O(1).|	O(1)
#Search	O(n)   | O(n) |

#dequeue stands for double ended queue it allows o(1) insertion n removal from both ends

from collections import deque
queue = deque()      # creates empty deque
queue.append(1)      # add to right - O(1)
queue.popleft()      # remove from left - O(1)

#deque can be for both stacks n queues 

#pop() always removes n returns the last element 

#popleft() removes from the left -> the front of the queue since its FIFO 

# Using a stack to reverse a string
def reverse_string(s):
    stack = []
    for char in s:
        stack.append(char)
    
    result = ""
    while stack:
        result += stack.pop()
    
    return result

print(reverse_string("hello"))

#this is using a stack to reverse the string 
#we have a functino claled reverse string that takes in the parameter s
#we make an empty list called stack
#we then go ahead and add every char in the s (lets assume the string) to the list
#we then set result to empty quotations marks
#n we add whatever we r popping from the stack to result n then we will remove it from the stack
#we will then go ahead and return the result
#so in this case we have hello
#the stack will have h, e, l, l, o
#then we will go ahead and do o l l e h
#and the result is olleh 

# Using a stack to check balanced parentheses
def is_balanced(s):
    stack = []
    for char in s:
        if char == "(":
            stack.append(char)
        elif char == ")":
            if not stack:
                return False
            stack.pop()
    return len(stack) == 0

print(is_balanced("(())"))
print(is_balanced("(()"))
print(is_balanced(")("))

#in this code we have a function called is_balance and it takes in the parameter s
#then we have a list called stack
#we r then going ahead n checking if the current char we r looking at is ( we add it to the stack
#if not if its ) we go ahead n return false n 