#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 2, 0);
    }
}

static void event_handler_cb_main_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 3, 0);
    }
}

static void event_handler_cb_page1_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 2, 0);
    }
}

static void event_handler_cb_page1_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 7, 0);
    }
}

static void event_handler_cb_page2_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 6, 0);
    }
}

static void event_handler_cb_page2_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 7, 0);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 21, 18);
            lv_obj_set_size(obj, 759, 383);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff61a3c4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 59, 51);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_phone, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj0, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 241, 51);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_fridge, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj1, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 595, 51);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_aircdt, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 59, 255);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_door, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 595, 255);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_home, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 413, 255);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_light, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 241, 255);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_bike, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 424, 51);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_washing, NULL);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 21, 413);
            lv_obj_set_size(obj, 759, 51);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff61a3c4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 488, 426);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_menu_icon);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 75, 415);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_wifi, NULL);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 159, 422);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "21:45:18 2024-09-07");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff19aece), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
}

void create_screen_page1() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.page1 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 21, 18);
            lv_obj_set_size(obj, 759, 383);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff61a3c4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 35, 35);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_phone, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_page1_obj2, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 21, 413);
            lv_obj_set_size(obj, 759, 51);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff61a3c4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 488, 426);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_menu_icon);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 75, 415);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_wifi, NULL);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 159, 422);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "21:45:18 2024-09-06");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff19aece), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 715, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_back, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_page1_obj3, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 306, 54);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_charge);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 306, 269);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Charging... 99% ");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff19aece), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_page1() {
    void *flowState = getFlowState(0, 1);
}

void create_screen_page2() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.page2 = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 21, 18);
            lv_obj_set_size(obj, 759, 383);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff61a3c4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            lv_obj_set_pos(obj, 21, 413);
            lv_obj_set_size(obj, 759, 51);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff1c6464), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0xff625b37), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xff61a3c4), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_img_create(parent_obj);
            lv_obj_set_pos(obj, 488, 426);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_img_set_src(obj, &img_menu_icon);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 75, 415);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_wifi, NULL);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 159, 422);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "21:45:18 2024-09-06");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff19aece), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 715, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_back, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_page2_obj4, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 35, 38);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 128);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_fridge, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_page2_obj5, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 283, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_qiaokeli, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 380, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_coffe, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 477, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_tanghulu, NULL);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            lv_obj_set_pos(obj, 574, 102);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 48);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_sanmingzhi, NULL);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 283, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "3 hours");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff57b8bd), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 472, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "25 hours");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff57b8bd), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 375, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "13 hours");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff57b8bd), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 569, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "3 hours");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff57b8bd), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj, 1000, 60);
            lv_obj_set_pos(obj, 283, 240);
            lv_obj_set_size(obj, 80, 80);
        }
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj, 1000, 60);
            lv_obj_set_pos(obj, 421, 240);
            lv_obj_set_size(obj, 80, 80);
        }
        {
            lv_obj_t *obj = lv_spinner_create(parent_obj, 1000, 60);
            lv_obj_set_pos(obj, 558, 240);
            lv_obj_set_size(obj, 80, 80);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 565, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "-20 °C");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff54ffdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 435, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "-8 °C");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffa2c8f1), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 301, 336);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "5 °C");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffbec385), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 315, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "C");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffbec385), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 455, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "L");
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffa2c8f1), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 591, 268);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "F");
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff54ffdc), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_page2() {
    void *flowState = getFlowState(0, 2);
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_page1();
    create_screen_page2();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_page1,
    tick_screen_page2,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
