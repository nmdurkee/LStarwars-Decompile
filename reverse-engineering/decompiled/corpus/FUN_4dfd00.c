/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4dfd00; label: FUN_004dfd00
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

