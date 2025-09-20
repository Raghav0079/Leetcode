''' Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition. '''

class Solution(object):
    def isValidSudoku(self,board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        rows = {}
        cols = {}
        boxes = {}

        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    num = board[i][j]
                    box_index = (i // 3) * 3 + j // 3

                    if (i, num) in rows or (j, num) in cols or (box_index, num) in boxes:
                        return False

                    rows[(i, num)] = True
                    cols[(j, num)] = True
                    boxes[(box_index, num)] = True

        return True
        
        