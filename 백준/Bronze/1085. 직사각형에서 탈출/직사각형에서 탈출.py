x,y,w,h = input().split()
x = int(x)
y = int(y)
w = int(w)
h = int(h)

distances = []
distances.append(x)
distances.append(y)
distances.append(w - x)
distances.append(h - y)
distances.sort()
print(distances[0])