struct Vector {
    data: Vec<i32>,
}

impl Vector {
    fn new() -> Self {
        Vector {
            data: Vec::with_capacity(2),
        }
    }

    fn push(&mut self, value: i32) {
        self.data.push(value);
    }

    fn get(&self, index: usize) -> Option<&i32> {
        self.data.get(index)
    }

    fn size(&self) -> usize {
        self.data.len()
    }
}

fn main() {
    let mut v = Vector::new();
    v.push(1);
    v.push(2);
    v.push(3);

    for i in 0..v.size() {
        println!("{:?}", v.get(i).unwrap());
    }
}
