#include <pebble.h>
#include <qr-layer.h>

static void init(void);
static void deinit(void);
static void window_load(Window *window);
static void window_unload(Window *window);
static void click_config_provider(void* context);
static void select_click_handler(ClickRecognizerRef recognizer, void *context);
static void up_click_handler(ClickRecognizerRef recognizer, void *context);
static void down_click_handler(ClickRecognizerRef recognizer, void *context);

static Window* s_window;
static QRLayer* s_qr_layer;

int main(void) {
  init();
  app_event_loop();
  deinit();
}

static void init(void) {
  s_window = window_create();
  window_set_click_config_provider(s_window, click_config_provider);
  window_set_window_handlers(s_window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  window_stack_push(s_window, true);
}

static void deinit(void) {
  window_destroy(s_window);
}

static void window_load(Window *window) {
  s_qr_layer = qr_layer_create(GRect(0, 4, 144, 144));
  qr_layer_add_to_window(s_qr_layer, s_window);
}

static void window_unload(Window *window) {
  qr_layer_destroy(s_qr_layer);
}

static void click_config_provider(void* context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  qr_layer_set_data(s_qr_layer, "SELECT BUTTON");
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  qr_layer_set_data(s_qr_layer, "UP BUTTON");
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  qr_layer_set_data(s_qr_layer, "DOWN BUTTON");
}
