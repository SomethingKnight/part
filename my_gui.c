#include "my_gui.h"
#include "lvgl.h"

lv_obj_t *obj1;
lv_obj_t *obj2;

static void my_event_cb(lv_event_t *e)
{
	lv_obj_t   *target = lv_event_get_target(e); 		 /* 第一步：获取触发事件的部件 */
	if ( target == obj1 )				 /* 第二步：判断触发事件的部件 */
	{
        printf("父对象触发事件 \r\n");	 		 /* 第三步：执行相应操作 */
	}
	else if ( target == obj2 )
	{
        printf("子对象触发事件 \r\n");
	}


}

void my_gui(void)
{
    obj1 = lv_obj_create(lv_scr_act());
    lv_obj_add_event_cb(obj1,my_event_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_size(obj1,300,300);
    //lv_obj_add_event_cb(obj1,my_event_cb, LV_EVENT_LONG_PRESSED, NULL);

    obj2 = lv_obj_create(lv_scr_act());
    lv_obj_add_event_cb(obj2,my_event_cb, LV_EVENT_LONG_PRESSED, NULL);
}
