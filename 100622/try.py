cur=2
d=[]
d.append(cur)
cnt =0
while 1:
    cur=(cur*2)%528
    print cur
    cnt += 1
    if cur in d:
        print cnt
        break;
    d.append(cur)
