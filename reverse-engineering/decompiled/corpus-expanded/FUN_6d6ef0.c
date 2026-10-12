/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d6ef0; label: FUN_006d6ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d6ef0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  int iVar1;
  
  iVar1 = FUN_006d43e0(param_1,param_2,param_3);
  if (iVar1 == 0) {
    if (param_6 == 0) {
      return;
    }
    iVar1 = FUN_006d43e0(param_1,param_2,0xffffffff);
    if (iVar1 == 0) {
      return;
    }
  }
  FUN_006d45f0(iVar1,param_2,(int)*(short *)(iVar1 + 0x5e),param_4,param_5);
  return;
}

