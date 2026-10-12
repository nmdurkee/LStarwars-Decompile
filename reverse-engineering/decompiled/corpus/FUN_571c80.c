/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x571c80; label: FUN_00571c80
 */

undefined4 FUN_00571c80(float param_1)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if ((0.0 < *(float *)((int)param_1 + 0x100)) && (2 < DAT_00925068 % 6)) {
    pbVar1 = (byte *)((int)param_1 + 0x20a);
    param_1 = 2.0;
    if ((*pbVar1 & 1) != 0) {
      param_1 = 1.0;
    }
    if (*(float *)(iVar2 + 0x100) < param_1) {
      return 0;
    }
  }
  return 1;
}

