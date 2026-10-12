/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64f780; label: FUN_0064f780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064f780(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = FUN_0064b410(param_1,param_6);
  if (iVar1 != -1) {
    FUN_0064e550(iVar1,param_2,param_3,param_4,param_5);
  }
  return;
}

