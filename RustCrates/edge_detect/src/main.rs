mod app;

use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() != 2 {
        println!("Usage: {} <path_to_image>", args[0]);
        return;
    }
    let filename = &args[1];

    app::edge_detect_app(filename);
    return;
}
