#include "my_gui.h"
#include "lvgl.h"

//lv_obj_t *obj1;
//lv_obj_t *obj2;
lv_obj_t   *switch1;

static void event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e); 		 /* 第一步：获取触发事件的部件 */
	if ( code == LV_EVENT_VALUE_CHANGED )				 /* 第二步：判断触发事件的部件 */
	{
        if(lv_obj_has_state(switch1, LV_STATE_CHECKED))
        {
            printf("LED ON \r\n");	 		 /* 第三步：执行相应操作 */
        }
        else
        {
            printf("LED OFF \r\n");	 		 /* 第三步：执行相应操作 */
        }
	}
}

void my_gui(void)
{
    switch1  = lv_switch_create( lv_scr_act() );
    lv_obj_set_style_bg_color(switch1,lv_color_hex(0xdf5345), LV_STATE_CHECKED|LV_PART_INDICATOR);

    lv_obj_add_state(switch1, LV_STATE_CHECKED|LV_STATE_DISABLED);		/* 添加状态：默认打开且不可修改 */
    lv_obj_clear_state(switch1, LV_STATE_CHECKED | LV_STATE_DISABLED);	/* 清除开关的状态 */

    lv_obj_add_event_cb(switch1,event_cb,LV_EVENT_VALUE_CHANGED,NULL);
}
