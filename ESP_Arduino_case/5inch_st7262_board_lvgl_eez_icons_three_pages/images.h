#ifndef EEZ_LVGL_UI_IMAGES_H
#define EEZ_LVGL_UI_IMAGES_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern const lv_img_dsc_t img_phone;
extern const lv_img_dsc_t img_aircdt;
extern const lv_img_dsc_t img_door;
extern const lv_img_dsc_t img_home;
extern const lv_img_dsc_t img_light;
extern const lv_img_dsc_t img_bike;
extern const lv_img_dsc_t img_washing;
extern const lv_img_dsc_t img_fridge;
extern const lv_img_dsc_t img_menu_icon;
extern const lv_img_dsc_t img_wifi;
extern const lv_img_dsc_t img_clock;
extern const lv_img_dsc_t img_back;
extern const lv_img_dsc_t img_charge;
extern const lv_img_dsc_t img_qiaokeli;
extern const lv_img_dsc_t img_coffe;
extern const lv_img_dsc_t img_tanghulu;
extern const lv_img_dsc_t img_sanmingzhi;

#ifndef EXT_IMG_DESC_T
#define EXT_IMG_DESC_T
typedef struct _ext_img_desc_t {
    const char *name;
    const lv_img_dsc_t *img_dsc;
} ext_img_desc_t;
#endif

extern const ext_img_desc_t images[17];


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_IMAGES_H*/