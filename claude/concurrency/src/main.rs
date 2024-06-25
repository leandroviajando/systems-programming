use std::sync::{Arc, Mutex};

const NUM_THREADS: usize = 10;
const INCREMENTS_PER_THREAD: usize = 1000;
const DECREMENTS_PER_THREAD: usize = 900;

struct Counter {
    value: Mutex<i32>,
}

impl Counter {
    fn new() -> Self {
        Counter {
            value: Mutex::new(0),
        }
    }

    fn increment(&self) {
        let mut value = self.value.lock().unwrap();
        *value += 1;
    }

    fn decrement(&self) {
        let mut value = self.value.lock().unwrap();
        *value -= 1;
    }

    fn get(&self) -> i32 {
        *self.value.lock().unwrap()
    }
}

fn main() {
    let counter = Arc::new(Counter::new());
    let mut handles = vec![];

    for _ in 0..NUM_THREADS {
        let counter = Arc::clone(&counter);
        let handle = std::thread::spawn(move || {
            for _ in 0..INCREMENTS_PER_THREAD {
                counter.increment();
            }
            for _ in 0..DECREMENTS_PER_THREAD {
                counter.decrement();
            }
        });
        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap();
    }

    println!("Final count: {}", counter.get());
}
