/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4dfd00; label: FUN_004dfd00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004dfd00(int param_1)

{
  uint *puVar1;
  
  FUN_004dde30(param_1);
  if ((((DAT_00882b44 != 0) && (*(float *)(DAT_00882b44 + 0x28) != 0.0)) &&
      (50.0 < *(float *)(DAT_00888fd4 + 0x54))) && (*(float *)(DAT_00888fd4 + 0x54) < 54.0)) {
    *(undefined4 *)(*(int *)(DAT_00888fd4 + 4) + 0x90) = 0;
    puVar1 = (uint *)(*(int *)(DAT_00888fd4 + 4) + 0x88);
    *puVar1 = *puVar1 & 0xfffffffd;
    *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xd0) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xd4) = 0;
    return;
  }
  if (_DAT_007fffa8 < *(float *)(*(int *)(DAT_00888fd4 + 4) + 0x90)) {
    *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xd0) = _DAT_008894b4;
    *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xd4) = _DAT_008894b8;
    FUN_00681f40("FacB_BeltLp",0);
    return;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xd0) = 0;
  *(undefined4 *)(*(int *)(param_1 + 0x128) + 0xd4) = 0;
  return;
}

