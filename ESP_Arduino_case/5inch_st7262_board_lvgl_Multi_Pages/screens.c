#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "styles.h"
#include "ui.h"

objects_t objects;
lv_obj_t *tick_value_change_obj;

static void event_handler_cb_main_obj0(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 2, 0);
    }
}

static void event_handler_cb_main_obj1(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 5, 0);
    }
}

static void event_handler_cb_screen_a_obj2(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 4, 0);
    }
}

static void event_handler_cb_screen_a_obj3(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 6, 0);
    }
}

static void event_handler_cb_screen_a_obj4(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 8, 0);
    }
    if (event == LV_EVENT_RELEASED) {
        flowPropagateValue(flowState, 8, 1);
    }
}

static void event_handler_cb_screen_a_obj5(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 9, 0);
    }
    if (event == LV_EVENT_RELEASED) {
        flowPropagateValue(flowState, 9, 1);
    }
}

static void event_handler_cb_screen_a_obj6(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 10, 0);
    }
    if (event == LV_EVENT_RELEASED) {
        flowPropagateValue(flowState, 10, 1);
    }
}

static void event_handler_cb_screen_b_obj7(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 4, 0);
    }
}

static void event_handler_cb_screen_b_obj8(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 6, 0);
    }
}

static void event_handler_cb_screen_b_obj9(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 8, 0);
    }
}

static void event_handler_cb_screen_c_obj10(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_CLICKED) {
        flowPropagateValue(flowState, 3, 0);
    }
}

static void event_handler_cb_screen_c_obj11(lv_event_t *e) {
    lv_event_code_t event = lv_event_get_code(e);
    void *flowState = e->user_data;
    if (event == LV_EVENT_PRESSED) {
        flowPropagateValue(flowState, 5, 0);
    }
}

void create_screen_main() {
    void *flowState = getFlowState(0, 0);
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 50, 380);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj0, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Screen A");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 261, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "This is the Main Screen");
            apply_style_screen_title(obj);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 300, 150);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 200);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_img1, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_img1, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_main_obj1, LV_EVENT_ALL, flowState);
        }
    }
}

void tick_screen_main() {
    void *flowState = getFlowState(0, 0);
}

void create_screen_screen_a() {
    void *flowState = getFlowState(0, 1);
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_a = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 282, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "This is the Screen A");
            apply_style_screen_title(obj);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 50, 380);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_a_obj2, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Screen B");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 650, 380);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_a_obj3, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj4 = obj;
            lv_obj_set_pos(obj, 300, 150);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 200);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_img2, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_img1, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_a_obj4, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj5 = obj;
            lv_obj_set_pos(obj, 50, 150);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 200);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_img2, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_img3, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_a_obj5, LV_EVENT_ALL, flowState);
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj6 = obj;
            lv_obj_set_pos(obj, 550, 150);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 200);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_img2, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_img4, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_a_obj6, LV_EVENT_ALL, flowState);
        }
    }
}

void tick_screen_screen_a() {
    void *flowState = getFlowState(0, 1);
}

void create_screen_screen_b() {
    void *flowState = getFlowState(0, 2);
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_b = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 282, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "This is the Screen B");
            apply_style_screen_title(obj);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 50, 380);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_b_obj7, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Screen C");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 650, 380);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_b_obj8, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 300, 150);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 133);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_img3, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_img4, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_b_obj9, LV_EVENT_ALL, flowState);
        }
    }
}

void tick_screen_screen_b() {
    void *flowState = getFlowState(0, 2);
}

void create_screen_screen_c() {
    void *flowState = getFlowState(0, 3);
    lv_obj_t *obj = lv_obj_create(0);
    objects.screen_c = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 800, 480);
    lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 283, 90);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "This is the Screen C");
            apply_style_screen_title(obj);
        }
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 650, 380);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_c_obj10, LV_EVENT_ALL, flowState);
            lv_obj_add_flag(obj, LV_OBJ_FLAG_SCROLL_ON_FOCUS);
            lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Back");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            lv_obj_t *obj = lv_imgbtn_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 300, 150);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, 150);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_RELEASED, NULL, &img_img4, NULL);
            lv_imgbtn_set_src(obj, LV_IMGBTN_STATE_PRESSED, NULL, &img_img4, NULL);
            lv_obj_add_event_cb(obj, event_handler_cb_screen_c_obj11, LV_EVENT_ALL, flowState);
        }
    }
}

void tick_screen_screen_c() {
    void *flowState = getFlowState(0, 3);
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
    create_screen_screen_a();
    create_screen_screen_b();
    create_screen_screen_c();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
    tick_screen_screen_a,
    tick_screen_screen_b,
    tick_screen_screen_c,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
