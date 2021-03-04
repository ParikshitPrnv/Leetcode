class Solution:
    def simplifyPath(self, path: str) -> str:
        mylist=path.split('/')
        s=[]
        print(mylist)
        for i in mylist:
            if i=="." or i=="":
                continue;
            elif i=="..":
                if len(s)>=1:
                    s.pop()
            else:
                s.append(i)
        if len(s)==0:
            return "/"
        path=""
        for i in s:
            path+="/"+i
        return path
        