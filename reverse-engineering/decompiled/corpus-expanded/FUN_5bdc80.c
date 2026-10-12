/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bdc80; label: FUN_005bdc80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005bdc80(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_4;
  
  iVar1 = *param_2;
  local_4 = 0;
  iVar2 = FUN_004fd5d0(param_1,iVar1,*param_3 - iVar1);
  if (iVar2 != 0) {
    FUN_004ef660(&local_4,*param_2,4);
    *param_2 = *param_2 + 4;
    FUN_004ef660(iVar1,*param_2,0x5c);
    *param_2 = *param_2 + 0x58;
    return 1;
  }
  return 0;
}

