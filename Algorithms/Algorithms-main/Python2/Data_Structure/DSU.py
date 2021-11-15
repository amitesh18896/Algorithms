def find(v,dsu):
    if dsu[v] == v: return v
    dsu[v] = find(dsu[v],dsu)
    return dsu[v]

def union(a,b,dsu,size = None):
    a = find(a,dsu)
    b = find(b,dsu)
    if a!=b:
        if size is not None:
            if size[a]<size[b]: a,b = b,a
            size[a]+=size[b]
        dsu[b] = a

