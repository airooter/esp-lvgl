#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *screen_a;
    lv_obj_t *screen_b;
    lv_obj_t *screen_c;
    lv_obj_t *obj0;
    lv_obj_t *obj1;
    lv_obj_t *obj10;
    lv_obj_t *obj11;
    lv_obj_t *obj2;
    lv_obj_t *obj3;
    lv_obj_t *obj4;
    lv_obj_t *obj5;
    lv_obj_t *obj6;
    lv_obj_t *obj7;
    lv_obj_t *obj8;
    lv_obj_t *obj9;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
    SCREEN_ID_SCREEN_A = 2,
    SCREEN_ID_SCREEN_B = 3,
    SCREEN_ID_SCREEN_C = 4,
};

void create_screen_main();
void tick_screen_main();

void create_screen_screen_a();
void tick_screen_screen_a();

void create_screen_screen_b();
void tick_screen_screen_b();

void create_screen_screen_c();
void tick_screen_screen_c();

void create_screens();
void tick_screen(int screen_index);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/