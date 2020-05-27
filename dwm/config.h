// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
// My Dwm Configuration :::::::::::::::::::::::::::::::::::::::
// Dwm Version: st 6.2 ::::::::::::::::::::::::::::::::::::::::
// Author: Tamibam ::::::::::::::::::::::::::::::::::::::::::::
// repo: github.com/tamibam/suckless ::::::::::::::::::::::::::
// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

// Imports:::::::::::::::::::::::::::::::::::::::::::::::::::::
#include "../vars.h" 
#include "../scheme.h"

// Appearance::::::::::::::::::::::::::::::::::::::::::::::::::
static const int showbar            = 1; // Bar? 
static const int topbar             = 1; // Top?
static const unsigned int borderpx  = 3; // Border
static const unsigned int snap      = 32; // Snap pixel
static const char *colors[][3]      = { // Colors Setup
  /*                  fg               bg               border   */
  [SchemeNorm]      = { col_foreground,  col_background,   col_background },
  [SchemeSel]       = { col_foreground,  col_blue,         col_blue },
  [SchemeStatus]    = { col_foreground,  col_background,   col_background  }, // Statusbar right
  [SchemeTagsSel]   = { col_blue,         col_background,   col_background  }, // Tagbar left selected 
  [SchemeTagsNorm]  = { col_foreground,  col_background,   col_background  }, // Tagbar left unselected 
  [SchemeInfoSel]   = { col_blue,        col_background,   col_background  }, // infobar middle  selected
  [SchemeInfoNorm]  = { col_foreground,  col_background,   col_background  }, // infobar middle  unselected 
};
static const char *tags[] = { "●", "●", "●", "●", "●", "●", "●", "●" };


// Rules:::::::::::::::::::::::::::::::::::::::::::::::::::::::::
static const float mfact = 0.6;  // Master area size [0.05..0.95]
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
  { "[]=",  tile },
  { "><",   NULL },
  { "[M]",  monocle },
};

// Helper for spawning shell commands:::::::::::::::::::::::::::
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Commands:::::::::::::::::::::::::::::::::::::::::::::::::::::
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, NULL };
static const char *termcmd[]  = { "st", NULL };

// Mappings:::::::::::::::::::::::::::::::::::::::::::::::::::::
static Key keys[] = {
  /* modifier                     key        function        argument */
  { SU,   XK_d,        spawn,          {.v = dmenucmd } },
  { SU,   XK_Return,   spawn,          {.v = termcmd } },
  { SU,   XK_b,        togglebar,      {0} },
  { SU,   XK_j,        focusstack,     {.i = +1 } },
  { SU,   XK_k,        focusstack,     {.i = -1 } },
  { SU,   XK_o,        incnmaster,     {.i = +1 } },
  { SS,   XK_o,        incnmaster,     {.i = -1 } },
  { SU,   XK_h,        setmfact,       {.f = -0.05} },
  { SU,   XK_l,        setmfact,       {.f = +0.05} },
  { SU,   XK_Tab,      view,           {0} },
  { SU,   XK_c,        killclient,     {0} },
  { SU,   XK_t,        setlayout,      {.v = &layouts[0]} },
  { SU,   XK_f,        setlayout,      {.v = &layouts[1]} },
  { SU,   XK_m,        setlayout,      {.v = &layouts[2]} },
  { SU,   XK_w,        spawn,          SHCMD("$BROWSER") },
  { SU,   XK_space,    zoom,           {0} },
  { SS,   XK_space,    togglefloating, {0} },
  { SU,   XK_0,        view,           {.ui = ~0 } },
  { SS,   XK_0,        tag,            {.ui = ~0 } },
  { SU,   XK_comma,    focusmon,       {.i = -1 } },
  { SU,   XK_period,   focusmon,       {.i = +1 } },
  { SS,   XK_comma,    tagmon,         {.i = -1 } },
  { SS,   XK_period,   tagmon,         {.i = +1 } },
  { SS,   XK_q,        quit,          {0} },
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
  /* click                event mask      button          function        argument */
  { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
  { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
  { ClkWinTitle,          0,              Button2,        zoom,           {0} },
  { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
  { ClkClientWin,         SU,         Button1,        movemouse,      {0} },
  { ClkClientWin,         SU,         Button2,        togglefloating, {0} },
  { ClkClientWin,         SU,         Button3,        resizemouse,    {0} },
  { ClkTagBar,            0,              Button1,        view,           {0} },
  { ClkTagBar,            0,              Button3,        toggleview,     {0} },
  { ClkTagBar,            SU,         Button1,        tag,            {0} },
  { ClkTagBar,            SU,         Button3,        toggletag,      {0} },
};

