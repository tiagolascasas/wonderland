extern crate image;

use image::GenericImageView;

pub fn edge_detect_app(filename: &str) {
    let (width, height) = match parse_image_filename(filename) {
        Some((width, height)) => (width, height),
        None => {
            println!("Invalid image filename: {}", filename);
            return;
        }
    };

    let image_rgb: Vec<u32> = match read_image(filename) {
        Some(image_data) => image_data,
        None => {
            println!("Error reading image: {}", filename);
            return;
        }
    };
    let threshold = 220;

    let mut output: Vec<u32> = vec![0; (width * height) as usize];

    edge_detect::edge_detect(&image_rgb, &mut output, width, height, threshold);

    let output_filename = filename
        .replace("inputs", "outputs")
        .replace(".jpg", ".png");
    save_image(&output_filename, &output, width, height);
}

pub fn parse_image_filename(image_filename: &str) -> Option<(i32, i32)> {
    // Split the filename by '_' and '.' to extract X and Y
    let parts: Vec<&str> = image_filename.split("_").collect();
    if parts.len() != 3 {
        return None;
    }

    let x: Option<i32> = parts[1].parse().ok();
    let y: Option<i32> = parts[2].split('.').next().and_then(|s| s.parse().ok());

    match (x, y) {
        (Some(x), Some(y)) => Some((x, y)),
        _ => None,
    }
}

pub fn read_image(path: &str) -> Option<Vec<u32>> {
    let img = match image::open(path) {
        Ok(img) => img,
        Err(_) => return None, // Return None if there's an error loading the image
    };

    let (width, height) = img.dimensions();

    let mut image_data = Vec::with_capacity((width * height * 3) as usize);

    for y in 0..height {
        for x in 0..width {
            let pixel = img.get_pixel(x, y);
            image_data.push(pixel[0] as u32); // Red component
            image_data.push(pixel[1] as u32); // Green component
            image_data.push(pixel[2] as u32); // Blue component
        }
    }

    Some(image_data)
}

pub fn save_image(path: &str, image_data: &Vec<u32>, width: i32, height: i32) {
    let mut imgbuf = image::ImageBuffer::new(width as u32, height as u32);

    for y in 0..height {
        for x in 0..width {
            let pixel = image_data[(y * width + x) as usize];

            imgbuf.put_pixel(
                x as u32,
                y as u32,
                image::Rgb([pixel as u8, pixel as u8, pixel as u8]),
            );
        }
    }

    println!("Saving image to: {}", path);
    imgbuf.save(path).unwrap();
}
