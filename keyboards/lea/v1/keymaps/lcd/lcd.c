#include <qp.h>

void lcd_housekeeping_task_user(void);

static painter_device_t display;

void keyboard_post_init_kb(void) {
    display = qp_st7735_make_spi_device(LCD_WIDTH, LCD_HEIGHT, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 2, 0);
    qp_init(display, QP_ROTATION_0);

    qp_power(display, true);
    rgb_matrix_set_suspend_state(false);
    //backlight_set(255);

    qp_clear(display);
    qp_rect(display, 0, 0, LCD_WIDTH-1, LCD_HEIGHT-1, HSV_WHITE, true);
}

void lcd_housekeeping_task_user(void) {

    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();

        qp_setpixel(display, 20, 20, HSV_ORANGE);
                qp_setpixel(display, 20, 21, HSV_ORANGE);
                qp_setpixel(display, 21, 20, HSV_ORANGE);
                qp_setpixel(display, 21, 21, HSV_ORANGE);

        qp_setpixel(display, 20, 20, HSV_ORANGE);
        qp_setpixel(display, 20, 21, HSV_ORANGE);
        qp_setpixel(display, 21, 20, HSV_ORANGE);
        qp_setpixel(display, 21, 21, HSV_ORANGE);

        qp_setpixel(display, 30, 30, HSV_GREEN);
        qp_setpixel(display, 30, 31, HSV_GREEN);
        qp_setpixel(display, 31, 30, HSV_GREEN);
        qp_setpixel(display, 31, 31, HSV_GREEN);

        qp_setpixel(display, 40, 40, RGB_BLUE);
        qp_setpixel(display, 40, 41, RGB_BLUE);
        qp_setpixel(display, 41, 40, RGB_BLUE);
        qp_setpixel(display, 41, 41, RGB_BLUE);

        qp_flush(display);
    }
}