# Turnip Project

![status](https://img.shields.io/github/workflow/status/ngawung/turnip-project/CI?style=for-the-badge)
![license](https://img.shields.io/github/license/ngawung/turnip-project?style=for-the-badge)

Hello there....
this is a simple devkitpro project...

feel free to use this project :D

## Building
1. Install [devkitPro](https://devkitpro.org/wiki/Getting_Started), khusus nya devkitARM sama libnds.
2. Clone repo ini
3. Run `make`
4. Hasil build ada di folder `./dist`

- (Note: gaperlu install compiler kayak `g++` karna udah disediain sama devkitPro nya)

## Debugging
Saya saranin make [vscode](https://code.visualstudio.com/download) buat debugging.
1. Rubah dulu semua path di folder `./vscode`
<sup>(Note: Dsini saya make OS linux, jadi mungkin buat windows sama mac perlu di rubah dikit settingan nya)</sup>
2. Download [DesMuME](http://desmume.org/) versi dev
<sup>(Note: Kalo kamu make windows mungkin bisa make no$gba katanya bisa track vram)</sup>
3. Run task `gdb-debug`
4. Run vscode debug (F5)

- (Note: gaperlu install `gdb` udah disediain sama devkitPro nya)

## Credits
- [devkitPro](https://devkitpro.org/wiki/Getting_Started) for your great tools
- [NightfoxLib](https://sourceforge.net/projects/nflib/) for your best ram management and graphic lib
- [SimpleNFL](https://github.com/PipeWarp/SimpleNFL/) for make my life easier
- [STween](https://github.com/riverreal/STween) for your simple and quick tween library

## LICENSE

GPLv3