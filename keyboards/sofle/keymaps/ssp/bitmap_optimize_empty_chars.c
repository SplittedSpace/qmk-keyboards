void bitmap_optimization_print_empty_ranges(char *name, const uint8_t *b, uint8_t b_size) {

    cout << "const b_empty_range " << name << "_op_empty_ranges [] PROGMEM = {";

    int start = 0;
    bool in_range = true;

    for (uint8_t i = 0; i < b_size; i++) {
        if (b[i] == 0 && i != b_size-1) {
            if (!in_range) {
                start = i;
                in_range = true;
            }

            continue;
        }

        if (in_range) {
            in_range = false;

            if (i - start > 2) {
                cout << "{" << start << ", " << int(i == (b_size-1) ? i : i-1) << "}, ";
            }
        }
    }

    cout << "};\n";
}

void bitmap_optimization_print_data(char *name, const uint8_t *b, uint8_t b_size) {
    cout << "const char " << name << "_op [] PROGMEM = {";

    for (uint8_t i = 0; i < b_size; i++) {
        if (b[i] != 0) {
            cout << int(b[i]) << ", ";
        }
    }

    cout << "};\n";
}


void bitmap_optimization_print(char *name, const uint8_t *b, uint8_t b_size) {
    bitmap_optimization_print_data(name, b, b_size);
    bitmap_optimization_print_empty_ranges(name, b, b_size);
}

    const uint8_t data[] = {
       0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfc, 0xfe, 0xfe, 0xfc, 0xf8, 
        0xf0, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x7f, 0x7f, 0x3f, 0x1f, 
        0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    bitmap_optimization_print("data", data, sizeof(data));





// =======================

typedef uint8_t b_empty_range[2];

void prepare_optimized_bmp(char *bmp, const char *b, uint8_t b_size, const b_empty_range *b_op, uint8_t b_op_size) {

    uint8_t bmp_point = 0;
    uint8_t bitmap_point = 0;

    for ( uint8_t op_point = 0; op_point <= b_op_size; op_point++) {

        // fill empty range 
        if (op_point < b_op_size && b_op[op_point][0] <= bmp_point && b_op[op_point][1] >= bmp_point) {
            for (uint8_t j = 0; j < b_op[op_point][1]-b_op[op_point][0]+1; j++) {
                bmp[bmp_point++] = 0x00;
            }

        } else {
            // fill values
            uint8_t fill_count = 0;

            if (op_point == 0) {
                fill_count = b_op[op_point][1]-1;
            } else if (op_point == b_op_size) {
                fill_count = b_size - bitmap_point;
            } else {
                fill_count = b_op[op_point][0] - b_op[op_point-1][1] - 1;
            }

            for (uint8_t j = 0; j < fill_count; j++) {
                // bmp[bmp_point++] = (char)pgm_read_byte(&b[bitmap_point]);
                bmp[bmp_point++] = b[bitmap_point];
                bitmap_point++;
            }

            // and then fill empty range if exists
            if (op_point < b_op_size) {
                for (uint8_t j = 0; j < b_op[op_point][1]-b_op[op_point][0]+1; j++) {
                    bmp[bmp_point++] = 0x00;
                }
            }
        }
    }
}

const char mode_text_op []  = {128, 192, 224, 96, 96, 48, 48, 48, 48, 48, 48, 96, 96, 224, 192, 128, 224, 252, 30, 7, 1, 192, 240, 56, 24, 12, 12, 12, 12, 24, 56, 252, 252, 1, 7, 30, 252, 224, 7, 63, 120, 224, 128, 3, 15, 28, 24, 48, 48, 48, 48, 24, 28, 15, 7, 14, 140, 140, 14, 7, 3, 1, 3, 7, 6, 6, 12, 12, 12, 12, 12, 12, 6, 6, 7, 3, 1, };
const b_empty_range mode_text_op_empty_ranges [] = {{0, 7}, {24, 35}, {60, 67}, {92, 103}, {120, 127}, };

const char mode_special_op []  = {192, 240, 240, 192, 48, 112, 112, 240, 240, 176, 48, 48, 48, 62, 15, 1, 1, 15, 62, 48, 48, 48, 176, 240, 240, 112, 112, 48, 129, 243, 127, 142, 192, 192, 96, 112, 112, 96, 192, 192, 143, 255, 243, 193, 12, 15, 7, 3, 3, 1, 1, 3, 3, 7, 15, 14, };
const b_empty_range mode_special_op_empty_ranges [] = {{0, 13}, {18, 35}, {60, 71}, {88, 102}, {109, 114}, {121, 127}, };

const char mode_media_op []  = {192, 192, 128, 240, 240, 128, 192, 224, 112, 240, 224, 192, 48, 48, 48, 177, 195, 225, 112, 184, 220, 238, 119, 63, 31, 14, 55, 51, 49, 48, 128, 192, 224, 112, 184, 220, 238, 119, 59, 29, 14, 7, 3, 61, 60, 2, 7, 14, 12, 3, 7, 15, 14, 7, 3, 1, };
const b_empty_range mode_media_op_empty_ranges [] = {{0, 11}, {15, 17}, {28, 41}, {60, 68}, {90, 99}, {107, 127}, };

const char mode_navi_op []  = {240, 240, 240, 240, 176, 48, 48, 176, 240, 240, 240, 240, 3, 3, 1, 3, 7, 14, 28, 8, 8, 28, 14, 7, 3, 1, 3, 3, 192, 192, 128, 192, 224, 112, 56, 16, 16, 56, 112, 224, 192, 128, 192, 192, 15, 15, 15, 15, 13, 12, 12, 13, 15, 15, 15, 15, };
const b_empty_range mode_navi_op_empty_ranges [] = {{0, 3}, {10, 21}, {28, 35}, {45, 50}, {60, 67}, {77, 82}, {92, 99}, {106, 117}, {124, 127}, };



// =========================

static void print_status_l_narrow(void) {
    // Print current modefs     
    oled_write_P(PSTR("\n\n"), false);
    char mode_icon[128];

    switch (get_highest_layer(layer_state)) {
        // Text
        case 0:
            prepare_optimized_bmp(mode_icon, mode_text_op, sizeof(mode_text_op), mode_text_op_empty_ranges, sizeof(mode_text_op_empty_ranges)/sizeof(b_empty_range) );
            break;
        
        // Specials and numbers
        case 1:
            prepare_optimized_bmp(mode_icon, mode_special_op, sizeof(mode_special_op), mode_special_op_empty_ranges, sizeof(mode_special_op_empty_ranges)/sizeof(b_empty_range) );
            break;

        // Navi
        case 2:
            prepare_optimized_bmp(mode_icon, mode_navi_op, sizeof(mode_navi_op), mode_navi_op_empty_ranges, sizeof(mode_navi_op_empty_ranges)/sizeof(b_empty_range) );
            break;
        
        // 
        case 3:
            prepare_optimized_bmp(mode_icon, mode_media_op, sizeof(mode_media_op), mode_media_op_empty_ranges, sizeof(mode_media_op_empty_ranges)/sizeof(b_empty_range) );
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }

    oled_write_raw(mode_icon, sizeof(mode_icon));
}