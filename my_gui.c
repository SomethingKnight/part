#include "my_gui.h"
#include "lvgl.h"

void my_gui(void)
{
    lv_obj_t *slider = lv_slider_create(lv_scr_act());
    lv_obj_set_align(slider, LV_ALIGN_CENTER);

    lv_obj_set_style_bg_color(slider, lv_color_hex(0x0c66ba),LV_STATE_DEFAULT|LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(slider, lv_color_hex(0x0c66ba),LV_STATE_DEFAULT|LV_PART_KNOB);

}
