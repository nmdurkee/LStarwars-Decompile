/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e2c60; label: FUN_004e2c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e2c60(int param_1)

{
  DAT_00882b2c = FUN_00578750(4);
  FUN_004e2b20(param_1);
  if ((_DAT_008894b4 == 0.0) && (_DAT_008894b8 == 0.0)) {
    _DAT_008894b4 = *(float *)(*(int *)(param_1 + 0x128) + 0xd0);
    _DAT_008894b8 = *(float *)(*(int *)(param_1 + 0x128) + 0xd4);
  }
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xd0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xd4) = 0;
  return;
}

