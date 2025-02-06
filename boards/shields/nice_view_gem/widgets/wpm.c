#include <math.h>
#include <zephyr/kernel.h>
#include "wpm.h"
#include "../assets/custom_fonts.h"

static void draw_label(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_label_dsc_t label_left_dsc;
    init_label_dsc(&label_left_dsc, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_LEFT);
    lv_canvas_draw_text(canvas, 0, BUFFER_OFFSET_MIDDLE, 25, &label_left_dsc, "WPM");

    lv_draw_label_dsc_t label_dsc_wpm;
    init_label_dsc(&label_dsc_wpm, LVGL_FOREGROUND, &pixel_operator_mono, LV_TEXT_ALIGN_RIGHT);

    char wpm_text[6] = {};

    snprintf(wpm_text, sizeof(wpm_text), "%d", state->wpm[9]);
    lv_canvas_draw_text(canvas, 26, 101 + BUFFER_OFFSET_MIDDLE, 42, &label_dsc_wpm, wpm_text);
}

void draw_wpm_status(lv_obj_t *canvas, const struct status_state *state) {
    draw_label(canvas, state);
}
