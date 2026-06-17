

r, c = [int(i) for i in input().split()]
m = []
for _ in range(r):
    m.append([int(i) for i in input().split()])

res_size = -1
res_i = -1
res_j = -1

for i in range(1, r-1):
    for j in range(1, c-1):
        topHeight = i
        bottomHeight = r-i-1
        leftLength = j
        rightLength = c-j-1

        maxLength = min(min(topHeight, bottomHeight), min(leftLength, rightLength))

        size = 0

        for k in range(maxLength+1):
            if m[i][j - k] != m[i - k][j]:
                break

            if m[i - k][j] != m[i][j + k]:
                break

            if m[i][j + k] != m[i + k][j]:
                break

            if m[i + k][j] != m[i][j - k]:
                break
        
            size += 1

        if size > res_size:
            res_size = size
            res_i = i
            res_j = j

print(f"{res_size-1} {res_i+1} {res_j+1}")





