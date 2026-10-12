/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x62a400; label: FUN_0062a400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0062a400(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int extraout_EDX;
  
  DAT_02912eb0 = param_1;
  if (*(int *)(param_1 + 0x3c) == 0) {
    iVar1 = FUN_00629e20(param_1,param_2,param_3);
    return iVar1;
  }
  iVar1 = FUN_0062a400(*(int *)(param_1 + 0x3c),param_2,param_3);
  if (DAT_02912eb0 != 0) {
    if (iVar1 != 0) {
      iVar1 = *(int *)(param_1 + 0x3c);
      if (*(int *)(param_1 + 0x3c) == 0) {
        iVar1 = param_1;
      }
      FUN_006271a0(iVar1);
      return extraout_EDX;
    }
    iVar1 = FUN_00627320(param_1,param_3);
  }
  return iVar1;
}

