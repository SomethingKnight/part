#include "my_gui.h"
#include "lvgl.h"

lv_obj_t *obj1;
lv_obj_t *obj2;

static void my_event_cb(lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e); 		 /* ��һ������ȡ�����¼��Ĳ��� */
	if ( code == LV_EVENT_VALUE_CHANGED )				 /* �ڶ������жϴ����¼��Ĳ��� */
	{
        printf("�����󴥷��¼� \r\n");	 		 /* ��������ִ����Ӧ���� */
	}
}

void my_gui(void)
{
    lv_obj_t  *btn  = lv_btn_create( lv_scr_act() );

    lv_obj_set_size( btn, 100, 50 );								    /* ��С */
    lv_obj_set_align( btn, LV_ALIGN_CENTER );						    /* ���� */
    lv_obj_set_style_bg_color( btn, lv_color_hex(0xffe1d4), LV_STATE_PRESSED );

    lv_obj_add_flag( btn, LV_OBJ_FLAG_CHECKABLE );
    lv_obj_add_event_cb( btn, my_event_cb, LV_EVENT_VALUE_CHANGED,NULL );	    /* ����¼� */

}
