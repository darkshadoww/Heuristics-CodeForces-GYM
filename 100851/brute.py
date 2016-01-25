def getdec(s):
    ans=0
    cur=1

    for i in s:
        if i=='1':
            ans += cur
        cur = cur*10

    return ans

def getbin(s):
    ans=0
    cur=1

    for i in s:
        if i=='1':
            ans += cur
        cur = cur*10

    return ans



for i in range(1, 1<<11):
    x=bin(i)
    y=getdec(x[2:][::-1])
    l=len(str(y))
    xx=bin(y)
    if xx[-l::]==str(y):
        p=y
        ans=0
        cur=1
        while p:
            if p%10:
                ans +=cur
            cur = cur*2
            p/=10
        tempy=y
        y/=10
        while y%10==0 and y:
            y/=10
        print tempy,ans,str(y)[::-1]
