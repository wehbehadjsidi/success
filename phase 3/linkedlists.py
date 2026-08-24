#linked lists
#a linked list is a sequence of nodes where each node contains two things
#a value and a pointer to the next node
#unlike arrays, the elements are not stored in contiguous memory
#they can be anywhere in memory, connected only by pointers
#if you need to insert or delete its O(1) bc you have a pointer to the next node but access is O(n) because you have to you have to go through each element 

class Node:
    def __init__(self, val):
        self.val = val #the actual data 
        self.next = None  # pointer to next node

class LinkedList:
    def __init__(self):
        self.head = None  # points to first node

# head
#  |
# [1] -> [2] -> [3] -> [4] -> None

#Access by index O(n) - must go through it 
#Insert at head O(1) - just update the head pointer
#insert at tail O(n) - must go through each element to the end
#delete at head O(1) - just update head point 
#Search O(n) - must traverse 

#a linked list is a sequence of nodes where each node is connected and has a pointer that connects to the next node and this is different from an array since it is not in continous memory and each element is on its node 
#the main tradeoff here is accessing elements as you must go ahead and go through the whole node to access specific indexes

#linked lists
#.  head
#.   |
# [val:1 | next:•]——>[val:2 | next:•]——>[val:3 | next:•]——>[val:4 | next:None]
# (at address 100)   (at address 580)   (at address 212)   (at address 847)

#Inserting at position 2 in an array:

#Before: [1, 2, 3, 4]
#Insert 9 at index 1:
#       [1, 9, 2, 3, 4]  ← 2, 3, 4 all had to shift right

#Inserting at head of linked list:

#Before: [1]→[2]→[3]→None
#Insert   9 at head:
#After:  [9]→[1]→[2]→[3]→None  ← just update one pointer, nothing shifts

#Linked list wins on insertion and deletion at the head — O(1) vs array's O(n)
#Array wins on access by index — O(1) vs linked list's O(n)
#if you lose the head you lose the entire list and theres no entry point 
#node.next gives you the entire next node object. node.next.val gives you just the value stored in that next node.

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

# Building a linked list manually: 1 -> 2 -> 3 -> None
head = Node(1)
head.next = Node(2)
head.next.next = Node(3)

# Traversing
current = head
while current:
    print(current.val)
    current = current.next

#explaination 
#what we first did is set the head to be the root and we set that value to 1 
#we then did the pointer and set the next node to be 2 and .next points to the next value
#same thing with the third node so itls now 3

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def insert_at_head(head, val):
    new_node = Node(val)
    new_node.next = head
    return new_node

head = Node(1)
head.next = Node(2)
head.next.next = Node(3)

head = insert_at_head(head, 0)

current = head
while current:
    print(current.val)
    current = current.next

#this has started off with assigning the value and the next to be none so thats empty
#this program has created a function called insert at head with no parameters the head and the value or the root and the value.
#it has made the new node the current value and the next new node the head so its making whatever they are trying to insert the root 
#what has happened is the head is 1 and the pointer to the next value is 2 and the pointer after that value is 3
#now its inserting 0 at the head
#then it has a while loop saying while we are at that value so while we are at the root or the head as you would like to say print the current value and then go ahead and change that current value to the next node using the pointer so itll keep going 
#the output is new node is 0 and new node next is 1 so itll print 
#0 
#and make current 1 
# 0 1 2 3

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def delete_head(head):
    if head is None:
        return None
    return head.next

head = Node(1)
head.next = Node(2)
head.next.next = Node(3)

head = delete_head(head)

current = head
while current:
    print(current.val)
    current = current.next

#what this code first does is create the class node and steps up the current value and the next which is our pointer to none so right now its emppty
#then we have a function called delete head so im assuming we want to delete the root and the only parameter is the head
#the function has an if statement that if head is empty well return none but if theres a value return the next node so the pointer using .next so the next value
#we have made our node 1 then 2 then 3 
#it calls the fuction to delete teh head so we are deleting 1
#the while loop will go ahead and print the current value but sinxe head isnt none we will return the next value which is.2
#the while loop will return 2 and make current 2 

#excerise 1
#first go ahead and create the class
#we want to go through the whole list and i cant do a for loop so ill do a while loop
#i will do while we are at the head print that value and then go ahead and update current with the next value using the pointer
#we will keep going as long as we have numbers
#the time complexity is O(n) since we have to go through the whole linked list chian
#the space complexity is O(1) since we arent new values and the memory amount isnt changing as we go through the list 


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def print_list(head):
    current = head
    while current:
        print(current.val)
        current = current.next 

head = Node(5)
head.next = Node(10)
head.next.next = Node(15)
head.next.next.next = Node(20)

goahead = print_list(head)


#exercise 2
#we r trying to find the value and we are going to make a function that takes in the root and a value that we are trying to find
#we want to know if it exists and this isnt an array so we cant just go ahead and try to access it so we have to go through it
#and well do an if else to return either true or false
#time complexity is O(n) since we are going thorugh the linked list and and space complexity is O(1) since our data isnt getting bigger with what were looking at

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def find_value(head, target):
    current = head
    while current:
        if current.val == target:
            return True
        current = current.next 
    return False
    
        
head = Node(3)
head.next = Node(6)
head.next.next = Node(9)
head.next.next.next = Node(12)

trial1 = find_value(head, 9)
trial2 = find_value(head, 8)
print(trial1)
print(trial2)

#this exercise wants me to count how many nodes are in that linked list so we will go ahead and set up a counter and do a while loop to update that counter and the value
#O(n) time complexity to do it since we have to go through the whole list and O(1) space complexity since the data isnt changing 
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
    
def count_nodes(head):
    count = 0
    current = head
    while current:
        count += 1
        current = current.next
    return count 

head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

trial1 = count_nodes(head)
print(trial1)


#this exercise we want to return the last node and to do that we will go ahead and go thorugh the whole linked list to get to the last one so the time complexity is O(n)
#now to do this what im thinking is we go ahead and do a while loop and we add all the values to a list
#then we will return the last index of that list. and the space complexity will be O(n) since im creating a new list and adding values to it
#there may be an easier way but my mind if going directly to this
#we also need to account for if the list is empty so thats the first thing well check

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
    
def get_last(head):
    seen = []
    current = head
    if current is None:
        return None
    while current:
        seen.append(current.val)
        current = current.next
    return seen[-1] 

head = Node(7)
head.next = Node(14)
head.next.next = Node(21)
head.next.next.next = Node(28)

print(get_last(head))

#another approach

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def get_last(head):
    if head is None:
        return None
    current = head
    while current.next is not None:
        current = current.next
    return current.val

head = Node(7)
head.next = Node(14)
head.next.next = Node(21)
head.next.next.next = Node(28)

print(get_last(head))

#last exercise so this one whats us to take a head node and reverse the linkied list in place 
#so what we will do is create three pointers. prev is empty. current is the current node we are at. next_node is empty
# what we do is we save the next node before overwriting it and then we will reverse the pointer but making the next node the previous node 
#so next_node since its empty itll be the next value so current.next
#then current.next will become the previous node 
#then the previous node will become the current node we are looking at so the root
#and the current we will be next node so itll move it forward
#and we want to return the prev since its now th enew head.

#prev = None
#current = head
#next_node = None

prev = None
current = [1] -> [2] -> [3] -> None
next_node = None

# While current:
#    next_node = current.next   # save next before overwriting
#    current.next = prev        # reverse the pointer
#    prev = current             # move prev forward
#    current = next_node        # move current forward

next_node = current.next     → next_node = [2]
current.next = prev          → [1].next = None   (reversed!)
prev = current               → prev = [1]
current = next_node          → current = [2]

[2] saves it

None current.next
[1] prev
[2] next_node

#return prev  # prev is now the new head

next_node = current.next     → next_node = [3]
current.next = prev          → [2].next = [1]   (reversed!)
prev = current               → prev = [2]
current = next_node          → current = [3]

[3] saves it 

[1] current.next
[2] prev
[3] next_node

#im confused here so in the previous iteration we have set next_node = 2, current.next = None, prev = [1], current = [2]

#now we have next_node = [3], currrent.next was initally none but is now 1 and then prev = 3  and current = 0

#Before: 1 -> 2 -> 3 -> None
#Step 1: None <- 1    2 -> 3 -> None
#Step 2: None <- 1 <- 2    3 -> None  
#Step 3: None <- 1 <- 2 <- 3
#Return: head is now 3

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

def reverse_list(head):
    prev = None
    current = head
    next_node = None

    #what we want to do is go ahead and first store what we are looking at, then make the current the previous, then make the next_node the current value we are looking at
    #because we want to go ahead and flip the directions the arrows are pointing
    while current:
        next_node = current.next
        current.next = prev
        prev = current
        current = next_node
    
    return prev #we want to go ahead and return the last node and since the arrows are flipped itll go backwards

#Before: 1 -> 2 -> 3 -> 4 -> 5 -> None
#After:  None <- 1 <- 2 <- 3 <- 4 <- 5


head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

new_head = reverse_list(head)
current = new_head
while current:
    print(current.val)
    current = current.next

#we want to see th eactual values so you have to go through the whole linked list using a while loop 

// ========================================
// LINKED LIST PATTERNS
// ========================================

// Pattern 1: Always use a current pointer to traverse
// Never move head directly or you lose access to the list.
//
// head = starting point
// current = pointer that moves through the list

ListNode current = head;

while (current != null) {
    System.out.println(current.val);
    current = current.next;
}


// Pattern 2: Check for null before accessing .val or .next
// Java uses null (NOT None).
// If current == null, accessing current.val or current.next
// causes a NullPointerException.

if (current != null) {
    System.out.println(current.val);
}

// Most common way to check:
while (current != null) {
    // Safe to access current.val and current.next
    current = current.next;
}


// Pattern 3: Save next before overwriting pointers
// VERY IMPORTANT for reversing a linked list.
//
// Order:
// 1. SAVE the next node
// 2. CHANGE the pointer
// 3. MOVE the pointers

ListNode nextNode = current.next; // 1. Save
current.next = previous;          // 2. Change
previous = current;               // 3. Move
current = nextNode;               // 3. Move


// Pattern 4: Know when to use linked lists vs. arrays
//
// Linked Lists:
// - Good for frequent insertions/deletions
// - Good when you already have a reference to the node
// - Accessing by position is O(n)
//
// Arrays / ArrayList:
// - Good for random access by index
// - Accessing by index is O(1)
// - Example: arrayList.get(500) → O(1)
//
// KEY IDEA:
// Linked List = good at changing connections
// ArrayList = good at accessing positions


// ========================================
// LINKED LIST REVERSAL
// ========================================
//
// Example:
// 1 → 2 → 3 → null
//
// Becomes:
// 3 → 2 → 1 → null
//
// Remember:
// SAVE → CHANGE → MOVE

ListNode previous = null;
ListNode current = head;

while (current != null) {
    ListNode nextNode = current.next; // SAVE
    current.next = previous;          // CHANGE
    previous = current;               // MOVE
    current = nextNode;               // MOVE
}

head = previous;


// ========================================
// BIGGEST THINGS TO REMEMBER
// ========================================
//
// 1. head = starting point, current = moving pointer
// 2. Java uses null, not None
// 3. Save current.next BEFORE changing current.next
// 4. Linked List → good for insertions/deletions
// 5. ArrayList → good for random access by index
// 6. Reversal → SAVE → CHANGE → MOVE

#Question 1: What is the time complexity of inserting at the head of a linked list and why?
#you don't shift anything. You just create a new node, point its next to the current head, and update head to the new node. One pointer update 

