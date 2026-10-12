/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5daae0; label: FUN_005daae0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005daae0(int param_1,byte param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x18c) + (uint)param_2) * 0x50 +
          *(int *)(param_1 + 0x184);
  FUN_005c0500(param_5,iVar1,(uint)*(byte *)(iVar1 + 0x44) * 0x40 + param_4);
  FUN_005c0500(param_5,param_5,param_3);
  return;
}

