# QR Layer [![npm (scoped)](https://img.shields.io/npm/v/@smallstoneapps/qr-layer.svg?maxAge=2592000&style=flat-square)](https://www.npmjs.com/package/@smallstoneapps/qr-layer)&nbsp;[![MIT License](http://img.shields.io/badge/license-MIT-lightgray.svg?style=flat-square)](./LICENSE) [![Build Status](https://www.bitrise.io/app/6e10bf974a072362.svg?token=5KP1NfZZVZNq78OzvXneUg)](https://www.bitrise.io/app/6e10bf974a072362)

A minimalist QR code layer for Pebble apps and watchfaces.

![](https://images.unsplash.com/photo-1461724947009-3c626ff3d2bc?dpr=1&auto=format&fit=crop&w=767&h=511&q=80&cs=tinysrgb&crop=)

*As of January 2017, this library is officially abandoned.*

## Installation

*You must be using Pebble SDK 3.12 or newer to use this library.*

To install the package to your app, use the pebble tool:

```
pebble package install @smallstoneapps/qr-layer
```

## Usage

To create a QR code layer object and add it to the window.

```c
QRLayer* layer = qr_layer_create(GRect(0, 0, 144, 144));
qr_layer_set_data("ABCDEF");
qr_layer_add_to_window(layer, window);
```
