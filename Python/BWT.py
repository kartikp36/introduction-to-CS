# Burrows Wheeler Transform
def bwt(string):
    cycles = sorted(string[i:] + string[:i] for i in range(len(string)))
    last_column = [row[-1:] for row in cycles]
    return "".join(last_column)


b = bwt("codespeedy$")
print(b)

def ibwt(r):
    table = [""] * len(r)
    for i in range(len(r)):
        table = sorted(r[i] + table[i] for i in range(len(r)))
    s = [row for row in table if row.endswith("$")][0]
    return s

print(ibwt(b))