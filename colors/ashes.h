unsigned int defaultfg = 15;
unsigned int defaultbg = 0;
static unsigned int defaultcs = 13;
static unsigned int defaultrcs = 0;

static const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#1c2023", /* black   */
  [1] = "#c79595", /* red     */
  [2] = "#95c7ae", /* green   */
  [3] = "#aec795", /* yellow  */
  [4] = "#ae95c7", /* blue    */
  [5] = "#c795ae", /* magenta */
  [6] = "#95aec7", /* cyan    */
  [7] = "#c7ccd1", /* white   */

  /* 8 bright colors */
  [8]  = "#747c84", /* black   */
  [9]  = "#c79595", /* red     */
  [10] = "#393f45", /* green   */
  [11] = "#565e65", /* yellow  */
  [12] = "#adb3ba", /* blue    */
  [13] = "#dfe2e5", /* magenta */
  [14] = "#c79595", /* cyan    */
  [15] = "#f3f4f5", /* white   */

  /* special colors */
  [256] = "#de935f", /* background */
  [257] = "#a3685a", /* foreground */
  [258] = "#282a2e", /* foreground */
  [259] = "#373b41", /* foreground */
  [260] = "#b4b7b4", /* foreground */
  [261] = "#e0e0e0", /* foreground */
           
           
};
 
/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
*/
unsigned int defaultitalic = 7;
unsigned int defaultunderline = 7;
