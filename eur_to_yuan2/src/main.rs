use std::env::args;
use std::process::exit;

const EUR_TO_YUAN: f32 = 7.92;

fn main() {
    let options: Vec<&str> = vec!["EURTOYUAN", "YUANTOEUR"];
    let arguments: Vec<String> = args().collect();
    if arguments.len() != 3 {
        eprintln!("SYNTAX: {} <CURRENCY> <HOW>", arguments[0]);
        exit(1);
    }
    if !options.contains(&arguments[2].as_str()) {
        eprintln!("ERROR: Second argument invalid, valid options are: EURTOYUAN and YUANTOEUR");
        exit(1);
    }
    let converted: f32 = match arguments[1].parse::<i32>() {
        Ok(e) => {e as f32},
        Err(_) => {
            match arguments[1].parse::<f32>() {
                Ok(z) => z,
                Err(_) => {
                    eprintln!("Error: First argument must be an integer or a float");
                    exit(1);

                }
            }
        }
    };
    if &arguments[2] == "EURTOYUAN" {
        println!("{converted} EURO = {:.2} YUAN",  converted * EUR_TO_YUAN);
    }
    else {
        println!("{converted} YUAN = {:.2} EURO", (converted / EUR_TO_YUAN));
    }

    
}
