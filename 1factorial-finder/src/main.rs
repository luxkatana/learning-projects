use std::env::args;
use std::process::exit;
use std::io::Result;

fn main() -> Result<()> {
    let arguments: Vec<String> = args().collect();
    if arguments.len() != 2 {
        eprintln!("SYNTAX: {} <TO_HAVE_FACTORED>", arguments[0]);
        eprintln!("NOTE: TO_HAVE_FACTORED MUST BE AN INTEGER");
        exit(1);
    }
    
    let to_find: u32 = match arguments[1].parse() {
        Ok(e) => e,
        Err(_) => {
            eprintln!("Second argument must be an integer");
            exit(1);
        }
    };
    println!("Answer: {}", find_factorial(to_find));

    Ok(())
}
fn find_factorial(n: u32) -> u32 {
    if n < 2 {
        return 1;
    }
    n * find_factorial(n - 1)
}
