// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// My Dwm Configuration :::::::::::::::::::::::::::::::::::::::
// Dwm Version: st 6.2 ::::::::::::::::::::::::::::::::::::::::
// Author: Tamibam ::::::::::::::::::::::::::::::::::::::::::::
// repo: github.com/tamibam/suckless ::::::::::::::::::::::::::
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// Imports:::::::::::::::::::::::::::::::::::::::::::::::::::::
#include <X11/XF86keysym.h>
#include "../scheme.h"

#define AL Mod1Mask
#define AN XK_ANY_MOD
#define SU Mod4Mask
#define SS (Mod4Mask | ShiftMask)
#define SC (Mod4Mask | ControlMask)
#define SH ShiftMask
#define CT ControlMask
#define CS (ControlMask | ShiftMask)
#define TK(KEY,TAG) \
  { SU,     KEY,      view,           {.ui = 1 << TAG} }, \
  { SU|CT,  KEY,      toggleview,     {.ui = 1 << TAG} }, \
  { SS,     KEY,      tag,            {.ui = 1 << TAG} },

// Appearance::::::::::::::::::::::::::::::::::::::::::::::::::
static const char *fonts[] = { "MesloLGSDZ Nerd Font:size=8:antialias=true" };
static const int showbar            = 1; // Bar? 
static const int topbar             = 1; // Top?
static const unsigned int borderpx  = 3; // Border
static const unsigned int snap      = 32; // Snap pixel
static const unsigned int gappih    = 10; // horiz inner gap between windows */
static const unsigned int gappiv    = 10; // vert inner gap between windows */
static const unsigned int gappoh    = 10; // horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10; // vert outer gap between windows and screen edge */
static const int smartgaps          = 0;  // 1 means no outer gap when there is only one window */
static const char *colors[][3]      = { // Colors Setup
  //                    fg        bg        border
  [SchemeNorm]      = { col_fg,   col_bg,   col_bg },
  [SchemeSel]       = { col_fg,   col_blue, col_blue },
  [SchemeStatus]    = { col_fg,   col_bg,   col_bg  }, // Statusbar right
  [SchemeTagsSel]   = { col_blue, col_bg,   col_bg  }, // Tagbar left selected 
  [SchemeTagsNorm]  = { col_fg,   col_bg,   col_bg  }, // Tagbar left unselected 
  [SchemeInfoSel]   = { col_blue, col_bg,   col_bg  }, // infobar middle  selected
  [SchemeInfoNorm]  = { col_fg,   col_bg,   col_bg  }, // infobar middle  unselected 
};
static const char *tags[] = { "1", "2", "3", "4", "5" };
static const unsigned int baralpha = 0x88;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
  /*               fg      bg        border     */
  [SchemeNorm] = { OPAQUE,  OPAQUE, OPAQUE },
  [SchemeSel]  = { OPAQUE, OPAQUE, OPAQUE },
};

// Rules:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
static const float mfact = 0.55;  // Master area size [0.05..0.95]
static const int nmaster = 1;  // Number of clients in master area
static const int resizehints = 1; // respect size hints in tiled resizals ?
static const Rule rules[] = {
  // xprop(1):  WM_CLASS(STRING) = instance, class WM_NAME(STRING) = title
  /* class      instance    title       tags mask     isfloating   monitor */
  { "Gimp",     NULL,       NULL,       0,            1,           -1 },
  { "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

// Layout Symbols:::::::::::::::::::::::::::::::::::::::::::::::
static const Layout layouts[] = {
  // Symbol Layout 
  { "|  ",  tile },
  { "| 缾",   NULL },
  { "|  ",  monocle },
};

// Helper for spawning shell commands:::::::::::::::::::::::::::
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Commands:::::::::::::::::::::::::::::::::::::::::::::::::::::
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { 
  "dmenu_run", "-m", dmenumon, topbar ? NULL : "-b", NULL 
};
static const char *termcmd[]  = { "st", NULL };
// static const char *brightinc[] = { "xbacklight", "-inc", "15", NULL };
// static const char *brightdec[] = { "xbacklight", "-dec", "15", NULL };
// static const char *volumeinc[] = { "pamixer", "--allow-boost", "-i", "5", NULL };
// static const char *volumedec[] = { "pamixer", "--allow-boost", "-d", "5", NULL };
// static const char *mustoggle[] = { "mpc", "toggle", NULL };
// static const char *musfastfo[] = { "mpc", "seek", "+10", NULL };
// static const char *musfastff[] = { "mpc", "seek", "+60", NULL };
// static const char *musfastba[] = { "mpc", "seek", "-10", NULL };
// static const char *musfastbb[] = { "mpc", "seek", "-60", NULL };
// static const char *musgonext[] = { "mpc", "next", NULL };
// static const char *musgoprev[] = { "mpc", "prev", NULL };
// static const char *exoptions[] = { "exoptions", NULL };
// static const char *deconfigs[] = { "editconfig", NULL };
// static const char *displayse[] = { "diselect", NULL };
// static const char *displayon[] = { "disone", NULL };
// static const char *mustuiapp[] = { "st", "-e", "ncmpcpp", NULL };

#define STACKKEYS(MOD,ACTION) \
  { MOD, XK_j,     ACTION##stack, {.i = INC(+1) } }, \
  { MOD, XK_k,     ACTION##stack, {.i = INC(-1) } }, \
  { MOD, XK_s,     ACTION##stack, {.i = 0 } }, \
 
// Mappings:::::::::::::::::::::::::::::::::::::::::::::::::::::
static Key keys[] = {
  // Window Management
  STACKKEYS(SU, focus)
  STACKKEYS(SS, push)
  { SU,   XK_b,             togglebar,        {0} },
  { SU,   XK_o,             incnmaster,       {.i = +1 } },
  { SS,   XK_o,             incnmaster,       {.i = -1 } },
  { SU,   XK_h,             setmfact,         {.f = -0.05} },
  { SU,   XK_l,             setmfact,         {.f = +0.05} },
  { SU,   XK_c,             killclient,       {0} },
  { SU,   XK_a,             togglesticky,     {0} },
  { SU,   XK_space,         zoom,             {0} },
  { SS,   XK_space,         togglefloating,   {0} },
  // Layout Management                        
  { SS,   XK_t,             setlayout,        {.v = &layouts[0]} },
  { SS,   XK_f,             setlayout,        {.v = &layouts[1]} },
  { SS,   XK_m,             setlayout,        {.v = &layouts[2]} },
  { SS,   XK_z,             incrogaps,        {.i = +5 } },
  { SU,   XK_z,             incrogaps,        {.i = -5 } },
  { SS,   XK_x,             incrigaps,        {.i = +5 } },
  { SU,   XK_x,             incrigaps,        {.i = -5 } },
  // Tag/Desktop Managment                    
  { SU,   XK_Tab,           view,             {0} },
  { SU,   XK_0,             view,             {.ui = ~0 } },
  { SU,   XK_semicolon,     shiftviewclients, { .i = +1 } },
  { SU,   XK_g,             shiftviewclients, { .i = -1 } },
  { SS,   XK_0,             tag,              {.ui = ~0 } },
  // Spawns                                   
  // { SU,   XK_d,             spawn,            {.v = dmenucmd } },
  // { SU,   XK_t,             spawn,            {.v = termcmd } },
  // { SU,   XK_w,             spawn,            SHCMD("$BROWSER") },
  // { SU,   XK_r,             spawn,            SHCMD("st -e $FILE") },
  // Controls                                 
// { SU,   XK_equal,         spawn,            {.v = volumeinc } },
// { SU,   XK_minus,         spawn,            {.v = volumedec } },
// { SS,   XK_equal,         spawn,            {.v = brightinc } },
// { SS,   XK_minus,         spawn,            {.v = brightdec } },
// { SU,   XK_p,             spawn,            {.v = mustoggle } },
// { SU,   XK_bracketright,  spawn,            {.v = musfastfo } },
// { SS,   XK_bracketright,  spawn,            {.v = musfastff } },
// { SU,   XK_bracketleft,   spawn,            {.v = musfastba } },
// { SS,   XK_bracketleft,   spawn,            {.v = musfastbb } },
// { SU,   XK_period,        spawn,            {.v = musgonext } },
// { SU,   XK_comma,         spawn,            {.v = musgoprev } },
// { SU,   XK_q,             spawn,            {.v = exoptions } },
// { SU,   XK_BackSpace,     spawn,            {.v = exoptions } },
// { SU,   XK_backslash,     spawn,            {.v = deconfigs } },
// { SU,   XK_F3,            spawn,            {.v = displayse } },
// { SU,   XK_F4,            spawn,            {.v = displayon } },
// { SU,   XK_m,             spawn,            {.v = mustuiapp } },
// { 0,    XK_Print,         spawn,            SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },   
// { SH,   XK_Print,         spawn,            SHCMD("maimpick") },
// { SC,   XK_x,             spawn,            SHCMD("slock & xset dpms force off;mpcpause;pauseallmpv") },

  // Tags Navigation
  TK(     XK_1,                        0)
  TK(     XK_2,                        1)
  TK(     XK_3,                        2)
  TK(     XK_4,                        3)
  TK(     XK_5,                        4)
  TK(     XK_6,                        5)
  TK(     XK_7,                        6)
  TK(     XK_8,                        7)
  TK(     XK_9,                        8)
};

// Button definitions:::::::::::::::::::::::::::::::::::::::::::

static Button buttons[] = {
  /* click          event mask button    function        argument */
  { ClkLtSymbol,    0,         Button1,  setlayout,      {0} },
  { ClkLtSymbol,    0,         Button3,  setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,    0,         Button2,  zoom,           {0} },
  { ClkStatusText,  0,         Button2,  spawn,          {.v = termcmd } },
  { ClkClientWin,   SU,        Button1,  movemouse,      {0} },
  { ClkClientWin,   SU,        Button2,  togglefloating, {0} },
  { ClkClientWin,   SU,        Button3,  resizemouse,    {0} },
  { ClkTagBar,      0,         Button1,  view,           {0} },
  { ClkTagBar,      0,         Button3,  toggleview,     {0} },
  { ClkTagBar,      SU,        Button1,  tag,            {0} },
  { ClkTagBar,      SU,        Button3,  toggletag,      {0} },
};
