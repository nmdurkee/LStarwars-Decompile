/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5a9750; label: FUN_005a9750
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a9750(void)

{
  int unaff_ESI;
  float local_c;
  undefined4 local_8;
  float local_4;
  
  if ((*(byte *)(unaff_ESI + 1) & 0x40) == 0) {
    local_c = DAT_0080250c;
    local_8 = DAT_00802510;
    local_4 = _DAT_00925018 * DAT_00802514 *
              *(float *)(&DAT_00805ca4 + ((*(byte *)(unaff_ESI + 1) & 0x30) >> 4) * 4);
    FUN_005b3620(&local_c,&local_c,*(undefined2 *)(unaff_ESI + 4));
    *(float *)(unaff_ESI + 0x14) = local_c + *(float *)(unaff_ESI + 0x14);
    *(float *)(unaff_ESI + 0x1c) = *(float *)(unaff_ESI + 0x1c) + local_4;
  }
  return;
}

