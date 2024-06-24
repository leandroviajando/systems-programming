pub struct String {
    data: Vec<u8>,
}

impl String {
    pub fn new(s: &str) -> String {
        String {
            data: s.as_bytes().to_vec(),
        }
    }

    pub fn len(&self) -> usize {
        self.data.len()
    }

    pub fn is_empty(&self) -> bool {
        self.len() == 0
    }

    pub fn as_str(&self) -> &str {
        std::str::from_utf8(&self.data).unwrap()
    }
}

fn main() {
    let s = String::new("Hello, Rust!");
    println!("The string is: {}", s.as_str());
    println!("Its length is: {}", s.len());
    println!("Its representation is: {:?}", s.data);
}
