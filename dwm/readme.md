dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.

Requirements
------------
In order to build dwm you need the Xlib header files.


Installation
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if
necessary as root):

```
make clean install
```

Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.

Tryout
-------------
This a few patches that are intersting, and may worth trying in the future:

- https://dwm.suckless.org/patches/statuscmd/
- https://dwm.suckless.org/patches/xrdb/ ; this one is intersting, and with compination with color bar, it may just be what I need.
