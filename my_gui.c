#include "my_gui.h"
#include "lvgl.h"

lv_obj_t *obj1;
lv_obj_t *obj2;

static void my_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e); 		 /* 第一步：获取触发事件的部件 */
	if ( code == LV_EVENT_VALUE_CHANGED )				 /* 第二步：判断触发事件的部件 */
	{
        printf("父对象触发事件 \r\n");	 		 /* 第三步：执行相应操作 */
	}
}

void my_gui(void)
{
    lv_obj_t  *btn  = lv_btn_create( lv_scr_act() );

    lv_obj_set_size( btn, 100, 50 );								    /* 大小 */
    lv_obj_set_align( btn, LV_ALIGN_CENTER );						    /* 对齐 */
    lv_obj_set_style_bg_color( btn, lv_color_hex(0xffe1d4), LV_STATE_PRESSED );

    lv_obj_add_flag( btn, LV_OBJ_FLAG_CHECKABLE );
    lv_obj_add_event_cb( btn, my_event_cb, LV_EVENT_VALUE_CHANGED,NULL );	    /* 添加事件 */

}
