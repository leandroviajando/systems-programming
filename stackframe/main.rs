/*
 * is_stack_growing_upwards recursively checks the stack growth direction.
 *
 * Returns 1 if the stack grows upwards, 0 if downwards.
 */
fn is_stack_growing_upwards(previous: Option<&i32>) -> bool {
    let current: i32 = 0;

    match previous {
        None => is_stack_growing_upwards(Some(&current)),
        Some(prev_addr) => &current > prev_addr,
    }
}

fn main() {
    println!("This is a Rust script checking stack growth direction:");
    println!(
        "{}",
        if is_stack_growing_upwards(None) {
            "Up"
        } else {
            "Down"
        }
    );
}
