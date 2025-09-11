class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if sum(gas)-sum(cost)<0:
            return -1
        res,start_index=gas[0]-cost[0],0
        for i in range(1,len(gas)):
            if res<0:
                res=0
                start_index=i
            res+=gas[i]-cost[i]
        return start_index


