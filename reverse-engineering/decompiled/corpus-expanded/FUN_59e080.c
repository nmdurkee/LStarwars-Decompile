/* Ghidra pseudocode, not original source.
 * ev_57e4595202f6848139a561b6e4253d561eb3ad03e2f9632ed29ba9ff4f0bafc7
 * Entry: 0x59e080; label: FUN_0059e080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_0059e080(undefined4 param_1,int param_2)

{
  return *(byte *)(param_2 + 10) >> 1 & 1;
}

