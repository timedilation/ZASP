use std::io;
use std::cmp::min;
use std::collections::LinkedList;

const INT_MAX: i32 = 987654321;
const DIRECTIONS: [(i32, i32); 8]  = [
    (1, 2), (1, -2), (2, 1), (2, -1), 
    (-1, 2), (-1, -2), (-2, 1), (-2, -1), 
];

fn read_two_usize() -> (usize, usize) {
    let mut input_text = String::new();
    io::stdin().read_line(&mut input_text).expect("failed to read from stdin");
    let mut substr_iter = input_text.split_whitespace();
    let mut next_num = || -> usize {
        let str = substr_iter.next().expect("Not enough input numbers")
                           .parse().expect("Input is not a number");
        str
    };
    let next_x = next_num();
    let next_y = next_num();
    
    return (next_x, next_y)
}

fn bfs(board_length: usize, start: (usize, usize), dest: (usize, usize)) -> i32{
    let mut visited = vec![vec![false; board_length]; board_length];
    let mut states = vec![vec![INT_MAX; board_length]; board_length];
    let mut queue: LinkedList<(usize, usize)> = LinkedList::new();

    queue.push_back(start);
    states[start.0][start.1] = 0;

    while ! queue.is_empty() {
        let curr_pos = queue.pop_front().unwrap();
        if curr_pos == dest {
            return states[curr_pos.0][curr_pos.1];
        }
        
        for iter in &DIRECTIONS {
            let next_x: i32 = curr_pos.0 as i32 + iter.0;
            let next_y: i32 = curr_pos.1 as i32 + iter.1;
            let limit = board_length as i32;
            let nx: usize = next_x as usize;
            let ny: usize = next_y as usize;
            if 0 <= next_x && next_x < limit && 0 <= next_y && next_y < limit {
                if ! visited[nx][ny] {
                    queue.push_back((nx, ny));
                    visited[nx][ny] = true;
                    states[nx][ny] = min(states[nx][ny], states[curr_pos.0][curr_pos.1] + 1);
                }
            }
        }
    }
    
    return 0;
}


fn main() {
    let mut input_text = String::new();
    io::stdin()
        .read_line(&mut input_text)
        .expect("failed to read from stdin");
    
    let testcases: u32 = input_text.trim().parse().expect("Invalid input");
    
    for _ in 0..testcases {
        let mut input_text = String::new();
        io::stdin().read_line(&mut input_text).expect("failed to read from stdin");
        let board_length: usize = input_text.trim().parse().expect("Invalid input");
        
        let start_xy = read_two_usize();
        let dest_xy = read_two_usize();
        
        let min_count: i32 = bfs(board_length, start_xy, dest_xy);
        println!("{}", min_count);
    }
}