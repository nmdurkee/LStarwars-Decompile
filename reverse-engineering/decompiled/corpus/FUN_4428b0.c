/* Ghidra analysis pseudocode, not original source.
 * ev_57da142a35c0111f2a239c45d08c295619c149a30e290e5aab503b2119bb06b8
 * Entry: 0x4428b0; label: FUN_004428b0
 */

float10 FUN_004428b0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  float local_18 [3];
  float local_c [3];
  
  if (((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) && (DAT_0093d810 != 0)) {
    iVar1 = **(int **)(param_3 + 0xd0);
    if ((*(char *)(DAT_0093d810 + 0x671) != -1) &&
       (*(char *)(DAT_0093d810 + 0x671) == *(char *)(iVar1 + 0x671))) {
      FUN_005b3800(local_18,DAT_0093d810 + 0x5c,DAT_0093d810 + 0x678);
      FUN_005b3620(local_18,local_18,-(uint)*(ushort *)(DAT_0093d810 + 0x696));
      FUN_005b3800(local_c,iVar1 + 0x5c,iVar1 + 0x678);
      FUN_005b3620(local_c,local_c,-(uint)*(ushort *)(iVar1 + 0x696));
      return (float10)(local_18[0] - local_c[0]);
    }
  }
  return (float10)0;
}

