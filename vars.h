// Font
static char *font = "Liberation Mono:pixelsize=21:antialias=true:autohint=true";
// Modifers Defination
#define AL Mod1Mask
#define AN XK_ANY_MOD
#define SU Mod4Mask
#define SH ShiftMask
#define CT ControlMask
#define CS (ControlMask | ShiftMask)
#define SS (Mod4Mask | ShiftMask)

// bg opacity
float alpha = 0.8;           

// ST foreground, 
unsigned int defaultfg = 7;
// ST background
unsigned int defaultbg = 258;
// ST Cursor
static unsigned int defaultcs = 256;
// ST reverse cursor
static unsigned int defaultrcs = 257;
// St Colors
static const char *colorname[] = {
  /* 8 normal colors */
  "black",
  "red3",
  "green3",
  "yellow3",
  "blue2",
  "magenta3",
  "cyan3",
  "gray90",
  /* 8 bright colors */
  "gray50",
  "red",
  "green",
  "yellow",
  "#5c5cff",
  "magenta",
  "cyan",
  "white",
  [255] = 0,
  /* Added after 255 to use with DefaultXX */
  "#cccccc",
  "#555555",
  "Black"
};
