# QRLayer

A minimalist QR code layer for Pebble apps and watchfaces.

## Usage

To create a QR code layer object and add it to the window.

```
QRLayer* layer = qr_layer_create(GRect(0, 0, 144, 144));
qr_layer_set_data("ABCDEF");
qr_layer_add_to_window(layer, window);
```
