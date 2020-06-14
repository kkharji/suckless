unsigned int defaultfg = 15;
unsigned int defaultbg = 0;
static unsigned int defaultcs = 13;
static unsigned int defaultrcs = 0;

static const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#000000", /* black   */
  [1] = "#5f8787", /* red     */
  [2] = "#f3ecd4", /* green   */
  [3] = "#eecc6c", /* yellow  */
  [4] = "#888888", /* blue    */
  [5] = "#999999", /* magenta */
  [6] = "#aaaaaa", /* cyan    */
  [7] = "#c1c1c1", /* white   */

  /* 8 bright colors */
  [8]  = "#333333", /* black   */
  [9]  = "#5f8787", /* red     */
  [10] = "#f3ecd4", /* green   */
  [11] = "#eecc6c", /* yellow  */
  [12] = "#888888", /* blue    */
  [13] = "#999999", /* magenta */
  [14] = "#aaaaaa", /* cyan    */
  [15] = "#c1c1c1", /* white   */

  /* special colors */
  [256] = "#aaaaaa", /* background */
  [257] = "#444444", /* foreground */
  [258] = "#121212", /* foreground */
  [259] = "#222222", /* foreground */
  [260] = "#999999", /* foreground */
  [261] = "#999999", /* foreground */
           
           
};
 
/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
*/
unsigned int defaultitalic = 7;
unsigned int defaultunderline = 7;
