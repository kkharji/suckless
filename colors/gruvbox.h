unsigned int defaultfg = 259;
unsigned int defaultbg = 258;
static unsigned int defaultcs = 256;
static unsigned int defaultrcs = 257;

static const char *colorname[] = {
  /* 8 normal colors */
  [0] = "#282828", /* black   */
  [1] = "#cc241d", /* red     */
  [2] = "#8ec07c", /* green   */
  [3] = "#d79921", /* yellow  */
  [4] = "#458588", /* blue    */
  [5] = "#b16286", /* magenta */
  [6] = "#689d6a", /* cyan    */
  [7] = "#a89984", /* white   */

  /* 8 bright colors */
  [8]  = "#928374", /* black   */
  [9]  = "#fb4934", /* red     */
  [10] = "#8ec07c", /* green   */
  [11] = "#fabd2f", /* yellow  */
  [12] = "#83a598", /* blue    */
  [13] = "#d3869b", /* magenta */
  [14] = "#8ec07c", /* cyan    */
  [15] = "#ebdbb2", /* white   */

  /* special colors */
  [256] = "#add8e6",  /* 256 -> cursor */    
  [257] = "#555555",  /* 257 -> rev cursor*/ 
  [258] = "#282828",  /* 258 -> bg */        
  [259] = "#ebdbb2",  /* 259 -> fg */        
           
           
};
 
/*
 * Colors used, when the specific fg == defaultfg. So in reverse mode this
 * will reverse too. Another logic would only make the simple feature too
 * complex.
*/
unsigned int defaultitalic = 7;
unsigned int defaultunderline = 7;
