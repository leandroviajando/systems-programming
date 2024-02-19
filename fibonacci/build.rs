extern crate cc;

fn main() {
    cc::Build::new().file("lib/fib/src/fib.c").compile("fib");
}
