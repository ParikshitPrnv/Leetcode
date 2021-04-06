class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        mylist=text.split()
        newlist=[]
        for index in range(len(mylist)-2):
            if mylist[index]==first and mylist[index+1]==second:
                newlist.append(mylist[index+2])
        return newlist