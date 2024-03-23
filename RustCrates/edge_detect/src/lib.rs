pub fn edge_detect(
    image_rgb: &Vec<u32>,
    output: &mut Vec<u32>,
    width: i32,
    height: i32,
    threshold: u32,
) {
    let mut image_gray: Vec<u32> = vec![0; (width * height) as usize];
    let mut temp_buffer: Vec<u32> = vec![0; (width * height) as usize];
    let mut filter: Vec<i32> = vec![0; 9];

    rgb_to_gray(&image_rgb, &mut image_gray, width, height);

    set_filter_smooth(&mut filter);

    convolve2d(&image_gray, output, width, height, &filter);

    set_filter_vert(&mut filter);

    convolve2d(&output, &mut image_gray, width, height, &filter);

    set_filter_horiz(&mut filter);

    convolve2d(&output, &mut temp_buffer, width, height, &filter);

    combthreshold(&image_gray, &temp_buffer, output, width, height, threshold);
}

fn rgb_to_gray(image_rgb: &Vec<u32>, image_gray: &mut Vec<u32>, width: i32, height: i32) {
    let real_width = (width * 3) as i32;

    for y in 0..height {
        for x in (0..real_width).step_by(3) {
            let r = image_rgb[(y * real_width + x) as usize] as f32;
            let g = image_rgb[(y * real_width + x + 1) as usize] as f32;
            let b = image_rgb[(y * real_width + x + 2) as usize] as f32;

            let gray = (0.3 * r + 0.59 * g + 0.11 * b) as u32;
            image_gray[(y * width + x / 3) as usize] = gray;
        }
    }
}

fn set_filter_smooth(filter: &mut Vec<i32>) {
    filter[0] = 1;
    filter[1] = 2;
    filter[2] = 1;
    filter[3] = 2;
    filter[4] = 4;
    filter[5] = 2;
    filter[6] = 1;
    filter[7] = 2;
    filter[8] = 1;
}

fn convolve2d(input: &Vec<u32>, output: &mut Vec<u32>, width: i32, height: i32, filter: &Vec<i32>) {
    let k = 3;

    let mut normal_factor = 0;
    for i in 0..filter.len() {
        normal_factor += filter[i].abs();
    }
    if normal_factor == 0 {
        normal_factor = 1;
    }

    let dead_cols = k / 2;
    let dead_rows = k / 2;

    for r in 0..(height - k + 1) {
        for c in 0..(width - k + 1) {
            let mut sum = 0;

            for i in 0..k {
                for j in 0..k {
                    let pixel = input[((r + i) * width + (c + j)) as usize] as i32;
                    let filter_val = filter[(i * k + j) as usize];

                    sum += pixel * filter_val;
                }
            }
            let out_idx = ((r + dead_rows) * width + (c + dead_cols)) as usize;
            output[out_idx] = (sum / normal_factor) as u32;
        }
    }
}

fn set_filter_vert(filter: &mut Vec<i32>) {
    filter[0] = -1;
    filter[1] = 0;
    filter[2] = 1;
    filter[3] = -2;
    filter[4] = 0;
    filter[5] = 2;
    filter[6] = -1;
    filter[7] = 0;
    filter[8] = 1;
}

fn set_filter_horiz(filter: &mut Vec<i32>) {
    filter[0] = -1;
    filter[1] = -2;
    filter[2] = -1;
    filter[3] = 0;
    filter[4] = 0;
    filter[5] = 0;
    filter[6] = 1;
    filter[7] = 2;
    filter[8] = 1;
}

fn combthreshold(
    image_vert: &Vec<u32>,
    image_horiz: &Vec<u32>,
    output: &mut Vec<u32>,
    width: i32,
    height: i32,
    threshold: u32,
) {
    for y in 0..height {
        for x in 0..width {
            let vert = image_vert[(y * width + x) as usize];
            let horiz = image_horiz[(y * width + x) as usize];

            let biggest = if vert > horiz { vert } else { horiz };
            let val = if biggest > threshold { 255 } else { 0 };

            output[(y * width + x) as usize] = val;
        }
    }
}
