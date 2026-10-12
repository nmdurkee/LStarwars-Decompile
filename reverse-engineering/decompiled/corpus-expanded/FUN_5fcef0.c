/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fcef0; label: FUN_005fcef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fcef0(int param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar2 = DAT_009736e0;
  puVar1 = (undefined4 *)*DAT_009736e0;
  if (*(int *)(param_1 + 0xf4) != 0) {
    *puVar1 = *(undefined4 *)(param_1 + 0xf8);
    *puVar2 = (uint)(puVar1 + 1);
    return;
  }
  *puVar1 = 0x3f800000;
  *puVar2 = (uint)(puVar1 + 1);
  return;
}

