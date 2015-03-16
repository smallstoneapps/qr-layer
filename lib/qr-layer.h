#pragma once

#include <pebble.h>

typedef Layer QRLayer;

QRLayer* qr_layer_create(GRect bounds);
void qr_layer_set_data(QRLayer* layer, char* data);
void qr_layer_destroy(QRLayer* layer);
Layer* qr_layer_get_layer(QRLayer* layer);

#define qr_layer_add_to_window(layer, window) layer_add_child(window_get_root_layer(window), qr_layer_get_layer(layer))
