# 자물쇠와 열쇠

def rotate_right(key):
    M = len(key)
    result = [[0 for col in range(M)] for row in range(M)]
    
    for i in range(M):
        for j in range(M):
            result[j][M-1-i] = key[i][j]
        
    return result

def is_unlockable_precisely(key_resized, lock):
    N = len(lock)

    for i in range(N):
        for j in range(N):
            if key_resized[i][j] == lock[i][j]:
                return False
    return True

def check_with_move(key, lock):
    N = len(lock)
    M = len(key)
    for row in range(N+M-1):
        for col in range(N+M-1):
            key_extended = [[0 for a in range(2*N+M-2)] for b in range(2*N+M-2)]
            for i in range(M):
                for j in range(M):
                    key_extended[row+i][col+j] = key[i][j]
            key_resized = []
            for i in range(N):
                key_resized.append(key_extended[M-1+i][M-1:M-1+N])
            if is_unlockable_precisely(key_resized, lock):
                return True
    return False
            
    
def solution(key, lock):
    for _ in range(4):
        if (check_with_move(key, lock)):
            return True
        key = rotate_right(key)
    return False

def main():
    print(solution([[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]	))

if __name__ == "__main__":
	main()