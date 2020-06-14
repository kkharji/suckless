unsigned int defaultfg = 7;
unsigned int defaultbg = 0;
static unsigned int defaultcs = 12;
static unsigned int defaultrcs = 0;

static const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#292d3e", /* black   */
  [1] = "#f07178", /* red     */
  [2] = "#c3e88d", /* green   */
  [3] = "#ffcb6b", /* yellow  */
  [4] = "#82aaff", /* blue    */
  [5] = "#c792ea", /* magenta */
  [6] = "#89ddff", /* cyan    */
  [7] = "#959dcb", /* white   */

  /* 8 bright colors */
  [8]  = "#676e95", /* black   */
  [9]  = "#f07178", /* red     */
  [10] = "#c3e88d", /* green   */
  [11] = "#ffcb6b", /* yellow  */
  [12] = "#82aaff", /* blue    */
  [13] = "#c792ea", /* magenta */
  [14] = "#89ddff", /* cyan    */
  [15] = "#959dcb", /* white   */

  /* special colors */
  [256] = "#f78c6c", /* background */
  [257] = "#ff5370", /* foreground */
  [258] = "#444267", /* foreground */
  [259] = "#32374d", /* foreground */
  [260] = "#8796b0", /* foreground */
  [261] = "#959dcb", /* foreground */
           
           
};
 
/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
*/
unsigned int defaultitalic = 7;
unsigned int defaultunderline = 7;
