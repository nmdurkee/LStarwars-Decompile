/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c7820; label: FUN_004c7820
 */

void FUN_004c7820(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_0087bf94;
  if (((DAT_008800a0 == FUN_004c6e90) && (DAT_0087bba0 != 0)) && (DAT_008801ac != -1)) {
    iVar1 = *(int *)(DAT_0087bba0 + 8) + DAT_008801ac * 0xc;
    *param_1 = *(undefined4 *)(*(int *)(DAT_0087bba0 + 8) + DAT_008801ac * 0xc);
    param_1[1] = *(undefined4 *)(iVar1 + 4);
    param_1[2] = *(undefined4 *)(iVar1 + 8);
    return;
  }
  *param_1 = *DAT_0087bf94;
  param_1[1] = puVar2[1];
  param_1[2] = puVar2[2];
  return;
}

