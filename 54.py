''' given a m*n matrix return all the elements of the matrix in spiral order '''

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        if not matrix:
            return []
        res = []
        top, bottom, left, right = 0, len(matrix)-1, 0, len(matrix[0])-1
        while top <= bottom and left <= right:
            for i in range(left, right+1):
                res.append(matrix[top][i])
            top += 1
            for i in range(top, bottom+1):
                res.append(matrix[i][right])
            right -= 1
            if top <= bottom:
                for i in range(right, left-1, -1):
                    res.append(matrix[bottom][i])
                bottom -= 1
            if left <= right:
                for i in range(bottom, top-1, -1):
                    res.append(matrix[i][left])
                left += 1
        return res
    