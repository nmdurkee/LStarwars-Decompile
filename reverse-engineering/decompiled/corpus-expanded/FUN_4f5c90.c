/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5c90; label: FUN_004f5c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f5c90(undefined1 *param_1,uint param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = (char)param_2;
    param_1 = param_1 + 1;
    param_2 = param_2 >> 8;
  }
  return;
}

