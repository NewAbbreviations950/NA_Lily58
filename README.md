## NA_Lily58
#Repository for my lily58 build

#moved to https://github.com/NewAbbreviations950/qmk_firmware/tree/NA_lily58/keyboards/lily58/keymaps/NA_lily58 as of 08.07.2024


# Build Goal
I wanted to build a split keyboard with trackpad to eliminate the need to move my hands from the keyboard as much as possible. I also liked the screens on each half but couldn't find a guide that had a screen on both halves and a trackpad. Seeing as both the screens ans trackpad coould be run over I2c I figured that it should be possible to have both if they had different addresses. As it turns out, it worked!

I have now added a key tapper to function like a mouse jiggler so when it's active the computer won't go to sleep and you're teams or discord status stays active. It sends the F15 keycode every thirty seconds after thirty seconds of inactivity while active. It is activated via a custom keycode. It's all included and working in my keymap file or just the code you need to make it work on another keyboard is in the jiggler.c file. While active it displays "Jiggle" on the oled.

# BOM
(links are just to the things I bought, I recieve no kickbacks)
 - A lily58 PCB kit, I went with the pro because I wanted low profile switches. I used this one: https://mechboards.co.uk/collections/featured/products/lily58-kit?variant=40874845339853
 - A pair of controllers, I used some RP2040 based controllers that are compatible with the Pro-Micro pinout so they would fit right on the PCB. The RP2040 based controllers also have more much more memory which you'll need if you want lots of extra stuff in the firmware (RGB, trackpad, screens, lots of macros, animations on the screens, etc). I used these ones: https://42keebs.eu/shop/parts/controllers/frood-rp2040-pro-micro-controller/
 - I swapped the screens in the kit for these wider ones from Ali-express: https://www.aliexpress.com/item/1005005235557472.html?spm=a2g0o.order_list.order_list_main.28.18f01802Kw3SnX The 0.96 inch screens have almost the same footprint as the 0.91 inch ones in the kit. They don't hang out over the controllers either.
 - The trackpad, I bought this kit: https://shop.beekeeb.com/product/40mm-cirque-glidepoint-circle-trackpad-module-diy-kit-for-split-mechanical-keyboard/ It comes with everything you need and they sent spares of everything except the trackpad!
 - I bought the mill max pins and sockets from 42Keebs: https://42keebs.eu/shop/parts/components/mill-max-315-sockets-3320-pins-for-pro-micro/ for the controllers.
 - For the screens I used longer pins on the PCB and soldered sockets onto the screens so I could connect the trackpad controller on the underside of the PCB. https://www.aliexpress.com/item/4001122376295.html?spm=a2g0o.order_detail.order_detail_item.9.3096f19ck3FZye colour: 2.54 1row male gold
 - A longer ribbon cable than is included in the trackpad set: https://www.aliexpress.com/item/1005005315578674.html?spm=a2g0o.order_list.order_list_main.153.3efc1802bn5yDn colour: 100MM, 12P, Forward Direction, 0.5MM
 - 57 Switches. I used choc sunset but this is totally down to preference.
 - Keycaps. Any low profile Choc V1 keycaps should work. Got mine on Ali-express: https://www.aliexpress.com/item/1005004558327406.html?spm=a2g0o.order_list.order_list_main.121.3efc1802bn5yDn
    - 54 regular
    - 2 homing
    - 1 1.5U
 - Trackpad mount: ([link](https://www.printables.com/model/828770-lily58-trackpad-mount)) Credit to the tallented @korqie on printables (https://www.printables.com/@korqie) for the design and print of the trackpad mount. He can probably sell a print if you can't print one yourself. He's on printables or Discord: Korqie

# Building
I used a couple different guides with some deviations.

 - For the basic build including diodes, hot swap sockets and controllers this guide was quite good: https://www.rearvuemirror.com/guides/lily58buildguide The only things I did differently was that I used the Mill Max pins as they're already the perfect length. I also used the male pins from Ali-express instead of sockets in the 4 holes for the screen (the pins the controller uses for I2c) and soldered sockets on to the screens instead.
  - Male pins on the top of the PCB for the screen
![20240401_195639](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/65faca73-8262-45ed-a4ab-3ffa069ae768)

  - Sockets on the back of the screen
![20240401_195934](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/8e22ae9e-5059-46f9-947c-10105a9813b7)

  - Male pins sticking through the PCB ready to attach the trackpad controller. (Don't mind the red wire. I messed up one of the 4 solder pads on the top that enable I2C so I connected the pin to the controller with the red wire instead)
![20240401_195809](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/9670ea8e-1abf-4238-a689-eb9dd40adfa4)


- For the trackpad, the store that sold the kit has a good guide based on the corne ckbd keyboard: https://beekeeb.com/cirque-trackpad-i2c-on-corne-keyboard/ So for my build I'm using the 40mm trackpad but that doesnt make a difference. Just check the resistors on the back match the guide in that the trackpad is configured for I2C mode. I didnt worry about the voltage as I'm powering through I2C.

 - Trackpad controller attached. Remember to check the pins are in the same orientation as the OLED (eg. GND pin is attached to GND socket on both OLED and trackpad controller). You can kind of see the resistors here that are described in the trackpad guide. The masking tape is just for isolation until I get kapton tape.
![20240401_195844](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/3f1cfa15-1678-4b76-92d8-a1aaf19bc9a9)

 - I used a 1U keycap on the right thumb to accomodate the trackpad
![20240401_202115](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/29ef0400-3733-4206-8205-ead879b7fffb)

- The different configuration of the pins for the OLEDs makes them a little higher so the posts that come with the kit to mount the plexiglass over the OLEDs are a little too short. I left the pleziglass off seeing as I used the posts for the trackpad mount on the right half anyway.

# Getting it running
 - The trackpad worked out of the box but was very unresponsive but adjusting the CIRQUE_PINNACLE_ATTENUATION to EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_1X (the most sensitive) fixed the issue. From there I have customised the layout on the OLEDS a little. I have it set up with dynamic macros and while recording in either slot 1 or slot 2 the OLED will display REC1 or REC2. Once a macro is recorded it will display PLY1 or PLY2 to show you have a macro recorded. I also included Luna the keyboard pet (https://www.reddit.com/r/olkb/comments/lmtgxc/introducing_luna_the_qmk_keyboard_pet/) but as she was made for the smaller OLEDs the animattion was messed up. I've stretched her out horizontally but I'm going to have to make whole new animations to get her proportions correct.
 - Video showing the OLEDs https://www.youtube.com/shorts/IGh5hdUlp_4 
 - The trackpad is glued into the ring of the mount ![TouchPadMount](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/c1695ec6-7701-483f-af2e-918a419f539e)
 - With the smaller piece mounted here ![TouchPadMount-PadPlacement](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/ff6fb456-61d1-44a4-b29c-9fcd4b41b789)


 - Attach the trackpad with the notch at 9 o'clock when looking from the front or 3 o'clock when looking from the back. This is so the pointer moves the right direction. The angle the trackpad is rotated can be changed in the firmware so it isn't critical. The trackpad mount is mounted to the PCB using the screw holes for the posts that hold the plexiglass protector for the OLED.
![20240401_213422](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/baca9be9-3000-4e85-bdce-05682fdf73e8)

- More photos of the trackpad mount
![20240401_214642](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/45325eaa-7422-43ba-a36a-3cb8eac737c5)
![20240401_214701](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/59164e2a-470b-407f-bb3d-c3c24fd31a67)

- The finished product
![20240401_214805](https://github.com/NewAbbreviations950/NA_Lily58/assets/104692825/c573982e-2f56-4855-b380-ba87ddc04372)
