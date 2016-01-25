def f(n):
    ret=1.0
    for i in range(n):
        ret = ret*(365.0-i)/365.0
    return 1-ret

for i in range(366):
    print i, f(i)
