/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x476010; label: FUN_00476010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00476010(int param_1)

{
  int iVar1;
  
  if (((param_1 == 0) || (param_1 == 1)) && (((&DAT_007fa138)[DAT_007fa190 * 0xc] & 2) != 0)) {
    iVar1 = FUN_0055f1a0();
    if (iVar1 == 0) {
      FUN_00547930(0x32,0,0,0);
      if (((&DAT_0093d7f0)[param_1] != 0) &&
         (iVar1 = *(int *)((&DAT_0093d7f0)[param_1] + 0x7fc), iVar1 != 0)) {
        *(undefined4 *)(iVar1 + 4) = 0x3fc00000;
      }
      _DAT_007fa1ac = 0x3fc00000;
    }
    else {
      (&DAT_00951250)[param_1] = (&DAT_00951250)[param_1] + 1;
      FUN_00681f40("env_padLight_on");
      if (((&DAT_0093d7f0)[param_1] != 0) &&
         (iVar1 = *(int *)((&DAT_0093d7f0)[param_1] + 0x7fc), iVar1 != 0)) {
        *(undefined4 *)(iVar1 + 4) = 0x3fc00000;
      }
      if (*(uint *)(&DAT_007fa134 + DAT_007fa190 * 0xc) <= (uint)(&DAT_00951250)[param_1]) {
        FUN_00475c60(param_1,0,0);
        DAT_00951250 = 0;
        _DAT_00951254 = 0;
        if (((&DAT_0093d7f0)[param_1 == 0] != 0) &&
           (iVar1 = *(int *)((&DAT_0093d7f0)[param_1 == 0] + 0x7fc), iVar1 != 0)) {
          *(undefined4 *)(iVar1 + 4) = 0x3fc00000;
          return;
        }
      }
    }
  }
  return;
}

