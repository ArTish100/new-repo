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
  return

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
  return

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
  return

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
  return


def solve_puzzle(S,G):
  queue = []
  visited = set() 
  S1 = copy.deepcopy(S)
  visited.add(tuple(tuple(row) for row in S1))
  queue.append(S1)
  print("nUMBER",end="\n")
  while queue:
    puzzle = queue.pop()
    #print("work")
    if puzzle == G:
      print("Found")
      print(G)
      return
    for i in range(4):
      S2 = copy.deepcopy(puzzle)
      move_zero(S2,i)
      S2_tuple = (tuple(tuple(row) for row in S2))
      if S2_tuple not in visited:
        visited.add(S2_tuple)
        queue.insert(0,S2)
        #print(queue)
    

def main():
  S = [[1,2,3],[8,0,4],[7,6,5]]
  G = [[2,8,1],[0,4,3],[7,6,5]]
  
  solve_puzzle(S,G)
  # print(S)


if __name__ == "__main__":
  main()