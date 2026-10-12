/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5d80; label: FUN_004f5d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004f5d80(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = DAT_0297e024 >> (0x20U - (char)param_1 & 0x1f);
  FUN_004f5d00(param_1);
  return uVar1;
}

