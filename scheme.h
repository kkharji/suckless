unsigned int defaultfg = 7;
unsigned int defaultbg = 0;
static unsigned int defaultcs = 12;
static unsigned int defaultrcs = 0;

static const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#1d1f21", /* black   */
  [1] = "#cc6666", /* red     */
  [2] = "#b5bd68", /* green   */
  [3] = "#f0c674", /* yellow  */
  [4] = "#81a2be", /* blue    */
  [5] = "#b294bb", /* magenta */
  [6] = "#8abeb7", /* cyan    */
  [7] = "#c5c8c6", /* white   */

  /* 8 bright colors */
  [8]  = "#969896", /* black   */
  [9]  = "#cc6666", /* red     */
  [10] = "#b5bd68", /* green   */
  [11] = "#f0c674", /* yellow  */
  [12] = "#81a2be", /* blue    */
  [13] = "#b294bb", /* magenta */
  [14] = "#8abeb7", /* cyan    */
  [15] = "#c5c8c6", /* white   */

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
