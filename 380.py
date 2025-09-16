'''Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.

'''
class RandomizedSet(object):
    def __init__(self):
        import random
        self.nums=[]
        self.val_to_index={}
        self.random=random
    def insert(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val in self.val_to_index:
            return False
        self.nums.append(val)
        self.val_to_index[val]=len(self.nums)-1
        return True
    def remove(self, val):
        """
        :type val: int
        :rtype: bool
        """
        if val not in self.val_to_index:
            return False
        index=self.val_to_index[val]
        last_element=self.nums[-1]
        self.nums[index]=last_element
        self.val_to_index[last_element]=index
        self.nums.pop()
        del self.val_to_index[val]
        return True
    def getRandom(self):
        """
        :rtype: int
        """
        return self.random.choice(self.nums)
    
        