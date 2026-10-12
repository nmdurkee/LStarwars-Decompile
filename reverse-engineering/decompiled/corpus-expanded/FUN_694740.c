/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694740; label: FUN_00694740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00694740(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_004f8a70(param_2,param_3);
  while (iVar1 != 0) {
    FUN_004f1f40(param_1,param_2,(iVar1 - param_2) + 1);
    param_1 = param_1 + (iVar1 - param_2);
    FUN_004f1f10(param_1,param_4);
    param_2 = FUN_004f1ff0(param_3);
    param_2 = param_2 + iVar1;
    iVar1 = FUN_004f1ff0(param_4);
    param_1 = param_1 + iVar1;
    iVar1 = FUN_004f8a70(param_2,param_3);
  }
  FUN_004f1f10(param_1,param_2);
  return;
}

