/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5c60; label: FUN_004f5c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004f5c60(uint *param_1,int param_2)

{
  return *param_1 & *(uint *)(&DAT_00800530 + param_2 * 4);
}

