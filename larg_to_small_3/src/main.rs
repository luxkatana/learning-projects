use std::process::exit;
use std::env::args;
fn main() {
    let arguments: Vec<String> = args().collect();
    let n_stars = |n| {
        let mut result: String = String::new();
        for _ in 0..n {
            result.push_str("*");
        }
        result

    };
    
    if arguments.len() != 2 {
        eprintln!("Syntax: {} <N_stars>", arguments[0]);
        exit(1);
    }
    let amount: u32 = match arguments[1].parse() {
        Ok(e) => e,
        Err(_) => {
            eprintln!("Second argument must be an integer");
            exit(1);
        }
    };
    for n in 0..amount {
        if n == amount {
            print!("{}", n_stars(amount - n));
        }
        else {
            println!("{}", n_stars(amount - n));
        }
    }
}
