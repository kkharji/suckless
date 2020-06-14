unsigned int defaultfg = 7;
unsigned int defaultbg = 0;
static unsigned int defaultcs = 4;
static unsigned int defaultrcs = 0;

static const char *colorname[] = {
  /* 8 bright colors */
  [0] = "#282c34", /* black   */
  [1] = "#e06c75", /* red     */
  [2] = "#98c379", /* green   */
  [3] = "#e5c07b", /* yellow  */
  [4] = "#61afef", /* blue    */
  [5] = "#c678dd", /* magenta */
  [6] = "#56b6c2", /* cyan    */
  [7] = "#abb2bf", /* white   */

  /* 8 normal colors */

  [8]  = "#545862", /* black   */
  [9]  = "#e06c75", /* red     */
  [10] = "#98c379", /* green   */
  [11] = "#e5c07b", /* yellow  */
  [12] = "#61afef", /* blue    */
  [13] = "#c678dd", /* magenta */
  [14] = "#56b6c2", /* cyan    */
  [15] = "#abb2bf", /* white   */

  /* special colors */
  [256] = "#d19a66", /* foreground */
  [257] = "#be5046", /* foreground */
  [258] = "#353b45",
  [259] = "#3e4451",
  [260] = "#565c64",
  [261] = "#b6bdca",
};
/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
*/
unsigned int defaultitalic = 7;
unsigned int defaultunderline = 7;
