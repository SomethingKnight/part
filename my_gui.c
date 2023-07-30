#include "my_gui.h"
#include "lvgl.h"

//lv_obj_t *obj1;
//lv_obj_t *obj2;
lv_obj_t   *switch1;

static void event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e); 		 /* ��һ������ȡ�����¼��Ĳ��� */
	if ( code == LV_EVENT_VALUE_CHANGED )				 /* �ڶ������жϴ����¼��Ĳ��� */
	{
        if(lv_obj_has_state(switch1, LV_STATE_CHECKED))
        {
            printf("LED ON \r\n");	 		 /* ��������ִ����Ӧ���� */
        }
        else
        {
            printf("LED OFF \r\n");	 		 /* ��������ִ����Ӧ���� */
        }
	}
}

void my_gui(void)
{
    switch1  = lv_switch_create( lv_scr_act() );
    lv_obj_set_style_bg_color(switch1,lv_color_hex(0xdf5345), LV_STATE_CHECKED|LV_PART_INDICATOR);

    lv_obj_add_state(switch1, LV_STATE_CHECKED|LV_STATE_DISABLED);		/* ���״̬��Ĭ�ϴ��Ҳ����޸� */
    lv_obj_clear_state(switch1, LV_STATE_CHECKED | LV_STATE_DISABLED);	/* ������ص�״̬ */

    lv_obj_add_event_cb(switch1,event_cb,LV_EVENT_VALUE_CHANGED,NULL);
}
