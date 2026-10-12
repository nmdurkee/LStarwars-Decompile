/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fcf30; label: FUN_005fcf30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fcf30(int param_1)

{
  uint *puVar1;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar1 = DAT_009736e0;
  *(undefined4 *)*DAT_009736e0 = *(undefined4 *)(param_1 + 0x194);
  *puVar1 = *puVar1 + 4;
  return;
}

