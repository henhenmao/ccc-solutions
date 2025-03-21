knight_dir = ((-1,2), (1,2), (2,1), (2,-1), (-2, 1), (-2,-1), (1,-2), (-1,-2))
board = [[0 for _ in range(8)] for _ in range(8)]

def inBounds(a):
    return a[0] >= 0 and a[0] <= 7 and a[1] >= 0 and a[1] <= 7

def knightHop():
    current_pos = [int(i)-1 for i in input().split()] + [0]
    end_pos = [int(i)-1 for i in input().split()]

    queue = [current_pos]
    while len(queue) > 0:
        current_pos = queue.pop(0)
        if current_pos[0:2] == end_pos:
            print(current_pos[2])
            break
        for i in knight_dir:
            next_move = [current_pos[0]+i[0], current_pos[1]+i[1], current_pos[2]+1]
            if inBounds(next_move) and board[next_move[0]][next_move[1]] == 0:
                board[next_move[0]][next_move[1]] = 1
                queue.append(next_move)
knightHop()


