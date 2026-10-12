/* Ghidra pseudocode, not original source.
 * ev_817077ca9f28b5da8eda466d74b875e7bf54783851332e01356736ec14054f9d
 * Entry: 0x58a8d0; label: FUN_0058a8d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0058a8d0(int param_1)

{
  if ((param_1 != 0) || (param_1 = DAT_009553d4, DAT_009553d4 != 0)) {
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined1 *)(param_1 + 0x1d) = 0;
    FUN_00548fb0(param_1 + 8,0);
  }
  return;
}

