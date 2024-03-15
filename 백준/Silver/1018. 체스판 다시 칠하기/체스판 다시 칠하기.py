def CheckBlack(samplelist):
    count = 0
    for i in range(0,8,2):
        for j in range(0,8,2):
            if samplelist[i][j] == 'W':
                count += 1
    for i in range(0,8,2):
        for j in range(1,8,2):
            if samplelist[i][j] == 'B':
                count += 1
    for i in range(1,8,2):
        for j in range(0,8,2):
            if samplelist[i][j] == 'B':
                count += 1
    for i in range(1,8,2):
        for j in range(1,8,2):
            if samplelist[i][j] == 'W':
                count += 1
    return count
                
def CheckWhite(samplelist):
    count = 0
    for i in range(0,8,2):
        for j in range(0,8,2):
            if samplelist[i][j] == 'B':
                count += 1
    for i in range(0,8,2):
        for j in range(1,8,2):
            if samplelist[i][j] == 'W':
                count += 1
    for i in range(1,8,2):
        for j in range(0,8,2):
            if samplelist[i][j] == 'W':
                count += 1
    for i in range(1,8,2):
        for j in range(1,8,2):
            if samplelist[i][j] == 'B':
                count += 1
    return count




r, c = map(int, input().split())
board = [input() for _ in range(r)]
res = r * c
for i in range(r - 7):
    for j in range(c - 7):
        sample = [row[j:j+8] for row in board[i:i+8]]
        b = CheckBlack(sample)
        w = CheckWhite(sample)
        
        temp = min([b,w])
        if temp < res:
            res = temp

print(res)    

    
