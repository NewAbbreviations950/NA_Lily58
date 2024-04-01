## NA_Lily58
#Repository for my lily58 build


# Build Goal
I wanted to build a split keyboard with trackpad to eliminate the need to move my hands from the keyboard as little as possible. I also liked the screens on each half but couldn't find a guide that had a screen on both halves and a trackpad. Seeing as both the screens ans trackpad coould be run over I2c I figured that it should be possible to have both if they had different addresses. As it turns out, it worked!

# BOM
(links are just to the things I bought, I recieve no kickbacks)
 - A lily58 PCB kit, I went with the pro because I wanted low profile switches. I used this one: https://mechboards.co.uk/collections/featured/products/lily58-kit?variant=40874845339853
 - A pair of controllers, I used some RP2040 based controllers that are compatible with the Pro-Micro pinout so they would fit right on the PCB. The RP2040 based controllers also have more much more memory which you'll need if you want lots of extra stuff in the firmware (RGB, trackpad, screens, lots of macros, animations on the screens, etc). I used these ones: https://42keebs.eu/shop/parts/controllers/frood-rp2040-pro-micro-controller/
 - I swapped the screens in the kit for these wider ones from Ali-express: https://www.aliexpress.com/item/1005005235557472.html?spm=a2g0o.order_list.order_list_main.28.18f01802Kw3SnX The 0.96 inch screens have almost the same footprint as the 0.91 inch ones in the kit. They don't hang out over the controllers either.
 - The trackpad, I bought this kit: https://shop.beekeeb.com/product/40mm-cirque-glidepoint-circle-trackpad-module-diy-kit-for-split-mechanical-keyboard/ It comes with everything you need and they sent spares of everything except the trackpad! I follwed their guide for attatching the resistors and basic config in the rules.mk file: https://beekeeb.com/cirque-trackpad-i2c-on-corne-keyboard/
