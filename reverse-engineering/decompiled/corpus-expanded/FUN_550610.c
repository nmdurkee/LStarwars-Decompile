/* Ghidra pseudocode, not original source.
 * ev_9af94503fce638d48c98755f8a4ba03de7c5cdf51e6dce151974c12e75b3fd49
 * Entry: 0x550610; label: FUN_00550610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00550610(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  FUN_0054fb80(param_1,param_2,param_3,param_4);
  iVar1 = param_1 + 0x10;
  FUN_0054fb80(iVar1,param_2 + 0x10,param_3 + 0x10,param_4);
  iVar2 = param_1 + 0x20;
  FUN_0054fb80(iVar2,param_2 + 0x20,param_3 + 0x20,param_4);
  FUN_005b3b30(param_1,param_1);
  FUN_005b3b30(iVar1,iVar1);
  FUN_005b3b30(iVar2,iVar2);
  return;
}

