'''Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left-justified, and no extra space is inserted between words.

Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.'''

class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        line=[]
        lines=[]
        line_length=0
    
        for word in words:
            if len(line)+ len(word) + line_length <= maxWidth:
                line.append(word)
                line_length+=len(word)
            else:
                line_length=len(word)
                lines.append(line)
                line=[word]
        lines.append(line)

        result=[]
        for i in range(len(lines)-1):
            line=lines[i]
            total_word_length=sum(len(word) for word in line)
            total_spaces= maxWidth-total_word_length
            num_gaps=len(line)-1
            if num_gaps==0:
                result.append(line[0]+' ' * total_spaces)
            else:
                base_gaps=total_spaces//num_gaps
                extra_spaces = total_spaces%num_gaps
                formatted_line=line[0]
                for j in range(1, len(line)):
                    space= base_gaps + (1 if j<= extra_spaces else 0)
                    formatted_line+= ' '*space + line[j]
                result.append(formatted_line)

        last_line=' '.join(lines[-1])
        result.append(last_line + ' '* (maxWidth-len(last_line)))
        return result
                
    