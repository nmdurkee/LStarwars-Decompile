/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43e1a0; label: FUN_0043e1a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043e1a0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  param_3 = param_3 + 0x2af0;
  if ((param_3 != 0) && (iVar1 = 0, 0 < *(int *)(PTR_DAT_00802c54 + 0x2aec))) {
    do {
      FUN_00559ee0(param_1,param_2,0,param_3);
      iVar1 = iVar1 + 1;
      param_3 = param_3 + 0xdc;
    } while (iVar1 < *(int *)(PTR_DAT_00802c54 + 0x2aec));
  }
  return;
}

