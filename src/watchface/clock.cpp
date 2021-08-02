#include "A_config.h"

static lv_obj_t *scr_clock;

static lv_obj_t *bar1;
static lv_obj_t *lblDate;
static lv_obj_t *lblTime[6][2];

static lv_obj_t *lblCurrentClass[2];
static lv_obj_t *lblNextClass[2];
static lv_obj_t *lblRemaining;

static lv_obj_t *swap;

static alarm_t *curr_class;
static alarm_t *next_class;
static alarm_t *breakflag = NULL; //用于是否下课
static uint8_t last_sec = 0;
static RTC_DATA_ATTR uint8_t digits[6];
static uint8_t digits_now[6];
static uint16_t label_y[6];
static uint32_t remaining;
static const char *week_chinese[] =
    {
        "----",
        "周一",
        "周二",
        "周三",
        "周四",
        "周五",
        "周六",
        "周日",
};

static void wf_clock_anim_set(lv_obj_t *label[2], uint16_t y, uint16_t delaytime)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
    lv_anim_set_time(&a, 500);
    lv_anim_set_delay(&a, delaytime);
    lv_anim_set_var(&a, label[1]);
    lv_anim_set_values(&a, y - 32, y);
    lv_anim_start(&a);
    lv_obj_fade_in(label[1], 500, delaytime);

    lv_anim_set_var(&a, label[0]);
    lv_anim_set_values(&a, y, y + 32);
    lv_anim_start(&a);
    lv_obj_fade_out(label[0], 400, delaytime);

    swap = label[0];
    label[0] = label[1];
    label[1] = swap;
}
static uint16_t class_y = 120 + 10;
static void swap_class(uint16_t p)
{
    REQUESTLV();
    if (curr_class == NULL)
    {
        if (next_class == NULL)
        {
            lv_obj_set_style_opa(lblCurrentClass[0], 0, 0);
            lv_obj_set_style_opa(lblNextClass[0], 0, 0);
            RELEASELV();
            return;
        }
        else
        {
            lv_label_set_text_fmt(lblCurrentClass[1], "不可用");
            lv_label_set_text_fmt(lblNextClass[1], "%s", class_names[next_class->subtype]);
        }
    }
    else if (curr_class->time_end <= p)
    {
        //当前课程已结束，如果闹钟没有冲突，此时一定有next_class->time_start > p
        lv_label_set_text_fmt(lblCurrentClass[1], "%s|课", class_names[curr_class->subtype]);
        lv_label_set_text_fmt(lblNextClass[1], "间|%s", class_names[next_class->subtype]);
    }
    else
    {
        //当前课程未结束
        lv_label_set_text_fmt(lblCurrentClass[1], "%s----->", class_names[curr_class->subtype]);
        lv_label_set_text_fmt(lblNextClass[1], "下课|%s", class_names[next_class->subtype]);
    }
    wf_clock_anim_set(lblCurrentClass, class_y, 0);
    wf_clock_anim_set(lblNextClass, class_y, 200);
    RELEASELV();
}
static void wf_clock_loop()
{
    bool tmp;
    if (last_sec != hal.rtc.getSecond())
    {
        alarm_check();
        //更新时间、日期、闹钟、倒计时
        uint8_t start_i = 99;
        uint8_t week;
        uint8_t minute;
        uint8_t hour;
        uint16_t p;
        last_sec = hal.rtc.getSecond();
        hour = hal.rtc.getHour(tmp, tmp);
        digits_now[0] = hour / 10;
        digits_now[1] = hour % 10;
        minute = hal.rtc.getMinute();
        digits_now[2] = minute / 10;
        digits_now[3] = minute % 10;
        digits_now[4] = last_sec / 10;
        digits_now[5] = last_sec % 10;
        for (uint8_t i = 0; i < 6; ++i)
        {
            if (digits[i] != digits_now[i])
            {
                if (start_i == 99)
                    start_i = i;
                digits[i] = digits_now[i];
                REQUESTLV();
                lv_label_set_text_fmt(lblTime[i][1], "%d", digits[i] % 10);
                wf_clock_anim_set(lblTime[i], label_y[i], (i - start_i) * 100);
                RELEASELV();
            }
        }
        REQUESTLV();
        lv_label_set_text_fmt(lblDate, "20%02d/%02d/%02d  %s", hal.rtc.getYear(), hal.rtc.getMonth(tmp), hal.rtc.getDate(), week_chinese[week = hal.rtc.getDoW()]);
        RELEASELV();
        p = hour * 60 + minute;
        if (curr_class != alarm_get_curr(week, p) || breakflag != alarm_get_next(week, p))
        {
            //更新闹钟信息
            breakflag = alarm_get_next(week, p);
            curr_class = alarm_get_curr(week, p);
            next_class = alarm_get_next_no_curr(week, p);
            alarm_check();
            alarm_update();
            if (next_class == NULL)
            {
                next_class = alarm_get_next_no_curr(1, 0);
            }
            swap_class(p);
        }

        uint32_t maxval = 0xffffffff;
        uint8_t dweek; //用于存储不同天闹钟相差天数
        if (curr_class == NULL)
        {
            if (next_class == NULL)
            {
                remaining = 0xffffffff;
            }
            else
            {
                dweek = next_class->week < week || (next_class->time_start <= p && next_class->week == week) ? next_class->week + 7 : next_class->week;
                dweek -= week;
                maxval = remaining = dweek * 24 * 60 + next_class->time_start - p;
            }
        }
        else if (next_class->week != week || curr_class->week != week)
        {
            dweek = next_class->week <= week ? next_class->week + 7 : next_class->week;
            dweek -= week;
            maxval = remaining = dweek * 24 * 60 + next_class->time_start - p;
        }
        else if (next_class->time_start <= p && curr_class->time_end <= p)
        {
            //当前课程已结束，但是下节课在下周的同一天
            maxval = remaining = 7 * 24 * 60 + next_class->time_start - p;
        }
        else if (curr_class->time_end <= p)
        {
            //当前课程已结束，如果闹钟没有冲突，此时一定有next_class->time_start > p
            remaining = next_class->time_start - p;
            maxval = next_class->time_start - curr_class->time_end;
        }
        else
        {
            //当前课程未结束
            remaining = curr_class->time_end - p;
            maxval = curr_class->time_end - curr_class->time_start;
        }
        if (remaining != 0xffffffff)
        {
            remaining *= 60;
            remaining -= last_sec;
            maxval *= 60;
        }
        REQUESTLV();
        lv_bar_set_value(bar1, map(remaining, maxval, 0, 0, 100), LV_ANIM_ON);
        lv_label_set_text_fmt(lblRemaining, "%d", remaining);
        RELEASELV();
    }
    if (hal.btnEnter.isPressedRaw())
    {
        vTaskDelay(300);
        if (hal.btnEnter.isPressedRaw())
        {
            menu_create();
            menu_add(LV_SYMBOL_SETTINGS " 设置");
            switch (menu_show())
            {
            case 1:
                menu_create();
                menu_add(LV_SYMBOL_WIFI " WiFi Smartconfig");
                menu_add(LV_SYMBOL_PLUS " 闹钟与时间");
                switch (menu_show())
                {
                    lv_obj_t *msgbox_full;
                case 1:
                    full_screen_msgbox(BIG_SYMBOL_INFO, "WiFi Smartconfig", "请用手机下载ESPTouch应用，按提示操作，按下确定键开始", FULL_SCREEN_BG_INFO);
                    hal.DoNotSleep = true;
                    msgbox_full = full_screen_msgbox_create(BIG_SYMBOL_SYNC, "WiFi Smartconfig", "正在等待Smartconfig，长按确定键1s取消", FULL_SCREEN_BG_SYNC);
                    if (hal.beginSmartconfig())
                    {
                        full_screen_msgbox_del(msgbox_full);
                        while (hal.btnEnter.isPressedRaw())
                            vTaskDelay(10);
                        full_screen_msgbox(BIG_SYMBOL_CHECK, "WiFi Smartconfig", "配网成功，已保存并自动断开连接", FULL_SCREEN_BG_CHECK);
                    }
                    else
                    {
                        full_screen_msgbox_del(msgbox_full);
                        while (hal.btnEnter.isPressedRaw())
                            vTaskDelay(10);
                        full_screen_msgbox(BIG_SYMBOL_CROSS, "WiFi Smartconfig", "配网失败", FULL_SCREEN_BG_CROSS);
                    }
                    hal.disconnectWiFi();
                    hal.DoNotSleep = false;
                    break;
                case 2:
                    menu_create();
                    menu_add(LV_SYMBOL_WIFI " 同步网络时间");
                    menu_add(LV_SYMBOL_EDIT " 时钟微调");
                    menu_add(LV_SYMBOL_BELL " 课程管理");
                    switch (menu_show())
                    {
                    case 1:
                        msgbox_full = full_screen_msgbox_create(BIG_SYMBOL_SYNC, "时间同步", "正在与NTP服务器同步时间: " CONFIG_NTP_ADDR, FULL_SCREEN_BG_SYNC);
                        hal.DoNotSleep = true;
                        if (hal.NTPSync())
                        {
                            full_screen_msgbox_del(msgbox_full);
                            while (hal.btnEnter.isPressedRaw())
                                vTaskDelay(10);
                            full_screen_msgbox(BIG_SYMBOL_CHECK, "时间同步", "同步成功!", FULL_SCREEN_BG_CHECK, 1000);
                        }
                        else
                        {
                            full_screen_msgbox_del(msgbox_full);
                            while (hal.btnEnter.isPressedRaw())
                                vTaskDelay(10);
                            full_screen_msgbox(BIG_SYMBOL_CROSS, "时间同步", "同步失败", FULL_SCREEN_BG_CROSS, 1000);
                        }
                        hal.DoNotSleep = false;
                        break;
                    default:
                        break;
                    }

                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
        }
    }
    vTaskDelay(50 / portTICK_PERIOD_MS);
}

void wf_clock_load(void)
{
    REQUESTLV();
    if (lv_scr_act())
        lv_obj_del(lv_scr_act());

    scr_clock = lv_obj_create(NULL);
    lv_scr_load(scr_clock);

    //课程进度条、倒计时

    bar1 = lv_bar_create(scr_clock);
    lv_obj_set_size(bar1, 200, 16);
    lv_obj_align(bar1, LV_ALIGN_CENTER, 0, 4);
    lv_obj_set_style_anim_time(bar1, 500, 0);
    lv_bar_set_value(bar1, 0, LV_ANIM_OFF);
    lv_bar_set_value(bar1, 50, LV_ANIM_ON);

    lblCurrentClass[0] = lv_label_create(scr_clock);
    lblNextClass[0] = lv_label_create(scr_clock);
    lv_obj_align(lblCurrentClass[0], LV_ALIGN_CENTER, -80, 20);
    lv_obj_align(lblNextClass[0], LV_ALIGN_CENTER, 80, 20);
    lv_label_set_text(lblCurrentClass[0], "");
    lv_label_set_text(lblNextClass[0], "");
    lv_obj_set_style_text_font(lblCurrentClass[0], &lv_font_chinese_16, 0);
    lv_obj_set_style_text_font(lblNextClass[0], &lv_font_chinese_16, 0);
    lblCurrentClass[1] = lv_label_create(scr_clock);
    lblNextClass[1] = lv_label_create(scr_clock);
    lv_obj_align(lblCurrentClass[1], LV_ALIGN_CENTER, -80, 20);
    lv_obj_align(lblNextClass[1], LV_ALIGN_CENTER, 80, 20);
    class_y = 20;
    lv_obj_set_style_text_font(lblCurrentClass[1], &lv_font_chinese_16, 0);
    lv_obj_set_style_text_font(lblNextClass[1], &lv_font_chinese_16, 0);
    lv_obj_set_style_opa(lblCurrentClass[1], 0, 0);
    lv_obj_set_style_opa(lblNextClass[1], 0, 0);

    lblRemaining = lv_label_create(scr_clock);
    lv_obj_set_style_text_font(lblRemaining, &lv_font_chinese_16, 0);
    lv_obj_align(lblRemaining, LV_ALIGN_CENTER, 0, 24);
    lv_label_set_text(lblRemaining, "0000");

    for (uint8_t i = 0; i < 4; ++i)
    {
        lblTime[i][0] = lv_label_create(scr_clock);
        lv_obj_set_style_text_font(lblTime[i][0], &num_64px, 0);
        lv_label_set_text(lblTime[i][0], "0");
        lblTime[i][1] = lv_label_create(scr_clock);
        lv_obj_set_style_text_font(lblTime[i][1], &num_64px, 0);
        lv_label_set_text(lblTime[i][1], "");
        lv_obj_set_x(lblTime[i][0], 40 + 32 * i);
        lv_obj_set_y(lblTime[i][0], 120 - 32 - 32);
        lv_obj_set_x(lblTime[i][1], 40 + 32 * i);
        lv_obj_set_y(lblTime[i][1], label_y[i] = 120 - 32 - 32); //暂存y,之后动画要用到
    }
    for (uint8_t i = 4; i < 6; ++i)
    {
        lblTime[i][0] = lv_label_create(scr_clock);
        lv_obj_set_style_text_font(lblTime[i][0], &num_32px, 0);
        lv_label_set_text(lblTime[i][0], "0");
        lblTime[i][1] = lv_label_create(scr_clock);
        lv_obj_set_style_text_font(lblTime[i][1], &num_32px, 0);
        lv_label_set_text(lblTime[i][1], "");
        lv_obj_set_x(lblTime[i][0], 104 + 16 * i);
        lv_obj_set_y(lblTime[i][0], 120 - 32 - 32 + 16 + 4);
        lv_obj_set_x(lblTime[i][1], 104 + 16 * i);
        lv_obj_set_y(lblTime[i][1], label_y[i] = 120 - 32 - 32 + 16 + 4);
    }
    for (uint8_t i = 0; i < 6; ++i)
    {
        lv_label_set_text_fmt(lblTime[i][0], "%d", digits[i] % 10);
    }
    lblDate = lv_label_create(scr_clock);
    lv_obj_set_style_text_font(lblDate, &lv_font_chinese_16, 0);
    lv_obj_align(lblDate, LV_ALIGN_CENTER, 0, -88);

    RELEASELV();

    hal.fLoop = wf_clock_loop;
}