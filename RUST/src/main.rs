#![feature(new_uninit)]

use std::slice;
use default_allocator::Layout;
use default_allocator::Heap;
use default_allocator::Alloc;

struct MyVec{
    data: Box<[isize]>,
    length: usize,
    capacity: usize
}

impl MyVec{
    fn new() -> Self{

        let ptr = Box::<*mut isize>::new_uninit().as_ptr();

        MyVec{
            data: unsafe{Box::from_raw(slice::from_raw_parts_mut(ptr as *mut _, 0))},
            length:0,
            capacity:0
        }
    }
    fn push(&mut self_piksari, n: isize) {
        if self_piksari.length == self_piksari.capacity {
            if self_piksari.capacity == 0{
                self_piksari.capacity = 1;
            }
            let new_capacity = self_piksari.capacity * 2;
            let mut new_data = unsafe {
                let ptr = Heap::default()
                    .alloc(Layout::array::<isize>(new_capacity).unwrap())
                    .unwrap().as_ptr() as *mut isize;
                Box::from_raw(slice::from_raw_parts_mut(ptr, new_capacity))
            };

            for i in 0..self_piksari.length {
                new_data[i] = self_piksari.data[i];
            }

            self_piksari.data = new_data;
            self_piksari.capacity = new_capacity;
        }

        self_piksari.data[self_piksari.length] = n;
        self_piksari.length += 1;
    }
    fn at(&mut self_piksari, idx: usize) -> isize{
        self_piksari.data[idx]
    }
}

fn main() {
    let mut vec = MyVec::new();
    vec.push(107);
    let a = vec.at(0);
    vec.push(110);
    println!("{}", a);
}
