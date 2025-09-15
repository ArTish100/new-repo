import copy

def find_pos(S):
    n = len(S)
    for i in range(n):
        for j in range(len(S[0])):
            if S[i][j] == 0:
                return [i,j]

def move_zero(S,i):
    if i == 0:
        up(S)
    if i == 1:
        down(S)
    if i == 2:
        left(S)
    if i == 3:
        right(S)

def up(S):
    pos=find_pos(S)
    try:
        i = pos[0]
        j = pos[1]
    except TypeError:
        print("Not Found")
        return
    if i > 0:
        S[i][j] = S[i-1][j]
        S[i-1][j] = 0

def down(S):
    pos=find_pos(S)
    try:
        i = pos[0]
        j = pos[1]
    except TypeError:
        print("Not Found")
        return
    if i < 2:
        S[i][j] = S[i+1][j]
        S[i+1][j] = 0

def left(S):
    pos=find_pos(S)
    try:
        i = pos[0]
        j = pos[1]
    except TypeError:
        print("Not Found")
        return
    if j > 0:
        S[i][j] = S[i][j-1]
        S[i][j-1] = 0

def right(S):
    pos=find_pos(S)
    try:
        i = pos[0]
        j = pos[1]
    except TypeError:
        print("Not Found")
        return
    if j < 2:
        S[i][j] = S[i][j+1]
        S[i][j+1] = 0


def solve_puzzle(S,G):
    queue = []
    visited = set()  # Using set to store visited states
    
    queue.append(S)
    visited.add(tuple(map(tuple, S)))  # Convert to tuple for hashing
    
    while queue:
        puzzle = queue.pop(0)
        
        if puzzle == G:
            print("Found")
            print(puzzle)
            return  # Stop searching once the goal is found
        
        for i in range(4):
            S2 = copy.deepcopy(puzzle)
            move_zero(S2,i)
            # print(S2)
            # Convert to tuple for hashing
            S2_tuple = tuple(map(tuple, S2))
            # print(S2_tuple)
            if S2_tuple not in visited:
                visited.add(S2_tuple)
                queue.append(S2)
                
    print("Goal not found")
    return
    

def main():
    S = [[1,2,3],[8,0,4],[7,6,5]]
    G = [[2,8,1],[0,4,3],[7,6,5]]
    solve_puzzle(S,G)

main()
