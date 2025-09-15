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


def solve_puzzle(S,E,G):
  queue = []
  visited = []
  S1 = copy.deepcopy(S)
  visited.append(S1)
  queue.append(S1)
  while queue:
    puzzle = queue.pop()
    #print("work")
    if puzzle == G:
      print("Found")
      print(puzzle)
      break
    for i in range(4):
      S2 = copy.deepcopy(puzzle)
      move_zero(S2,i)
      print(S2)
      if S2 not in visited:
        visited.append(S2)
        queue.append(S2)
        #print(queue)
  return
    

def main():
  S = [[1,2,3],[8,0,4],[7,6,5]]
  G = [[2,8,1],[0,4,3],[7,6,5]]
  #G = [[2,8,1],[0,4,3],[7,6,5]]
  E = []
  solve_puzzle(S,E,G)



if __name__ == "__main__":
  main()

