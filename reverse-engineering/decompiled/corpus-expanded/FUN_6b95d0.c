/* Ghidra pseudocode, not original source.
 * ev_53ad6b1d8bb34752a747640de0a0339f355d943428ba011e4ade8e8202156388
 * Entry: 0x6b95d0; label: FUN_006b95d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b95d0(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0xc);
  if (iVar1 == 0) {
    DAT_0081fadc = 0xffffffff;
  }
  else {
    if (iVar1 == 1) {
      DAT_0081fadc = 0;
      FUN_006b9590(param_1);
      return;
    }
    if (iVar1 == 2) {
      DAT_0081fadc = ~DAT_0081fadc;
      FUN_006b9590(param_1);
      return;
    }
    if (-1 < iVar1 + -3) {
      DAT_0081fadc = DAT_0081fadc ^ 1 << ((byte)(iVar1 + -3) & 0x1f);
      FUN_006b9590(param_1);
      return;
    }
  }
  FUN_006b9590(param_1);
  return;
}

