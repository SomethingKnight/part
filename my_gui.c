#include "my_gui.h"
#include "lvgl.h"

lv_obj_t *obj1;
lv_obj_t *obj2;

static void my_event_cb(lv_event_t *e)
{
	lv_obj_t   *target = lv_event_get_target(e); 		 /* ��һ������ȡ�����¼��Ĳ��� */
	if ( target == obj1 )				 /* �ڶ������жϴ����¼��Ĳ��� */
	{
        printf("�����󴥷��¼� \r\n");	 		 /* ��������ִ����Ӧ���� */
	}
	else if ( target == obj2 )
	{
        printf("�Ӷ��󴥷��¼� \r\n");
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
