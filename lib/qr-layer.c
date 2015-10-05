#include <pebble.h>
#include "qr-layer.h"

static void clear(Layer* layer, GContext* ctx);
static void update(Layer* layer, GContext* ctx);

QRLayer* qr_layer_create(GRect bounds) {
  QRLayer* qr_layer = layer_create_with_data(bounds, sizeof(QRData));
  layer_set_update_proc(qr_layer, update);
  return qr_layer;
}

QRLayer* qr_layer_create_max() {
  return qr_layer_create(GRect(0, 12, 144, 144));
}

void qr_layer_set_data(QRLayer* layer, char* data) {
  QRData* qr_data = (QRData*) layer_get_data(layer);
  qr_data->width = EncodeData(QR_LEVEL_L, 0, data, 0, qr_data->str);
  layer_mark_dirty(qr_layer_get_layer(layer));
}

void qr_layer_destroy(QRLayer* layer) {
  layer_destroy(layer);
}

Layer* qr_layer_get_layer(QRLayer* layer) {
  return (Layer*)layer;
}

static void clear(Layer* layer, GContext* ctx) {
  GRect layer_size = layer_get_bounds(layer);
  graphics_context_set_fill_color(ctx, DEFAULT_BG_COLOR);
  graphics_fill_rect(ctx, layer_size, 0, GCornerNone);
  graphics_context_set_fill_color(ctx, DEFAULT_FILL_COLOR);
}

static void update(Layer* layer, GContext* ctx) {
  GRect layer_size = layer_get_bounds(layer);

  clear(layer, ctx);

  QRData* qr_data = (QRData*) layer_get_data(layer);

  if (qr_data->width == 0) {
    return;
  }

	uint8_t byte = 0;
	uint8_t bit = 7;

	uint8_t block_size = layer_size.size.w / qr_data->width;
	uint8_t padding_x = (layer_size.size.w - (block_size * qr_data->width)) / 2;
	uint8_t padding_y = (layer_size.size.h - (block_size * qr_data->width)) / 2;

	for (uint8_t y = 0; y < qr_data->width; y += 1) {
		for (uint8_t x = 0; x < qr_data->width; x += 1) {
			bool value = (*((unsigned char*)qr_data->str + byte)) & (1 << bit);
			if (value) {
				graphics_fill_rect(ctx, GRect(padding_x + x * block_size, padding_y + y * block_size, block_size, block_size), 0, GCornerNone);
      }
      if (bit <= 0) {
        bit = 7;
        ++byte;
      }
      else {
        bit -= 1;
      }
		}
	}
}
