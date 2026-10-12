/* Ghidra pseudocode, not original source.
 * ev_6c7022c87010c6d39f3f3226e46062ec65b94628332be136b3f738ab843f9afe
 * Entry: 0x4cf0f0; label: FUN_004cf0f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004cf0f0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0x4680) != 0)) &&
     (iVar2 = 0, 0 < *(int *)(param_3 + 0x4684))) {
    iVar1 = 0;
    do {
      FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x4680) + iVar1);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0xfc;
    } while (iVar2 < *(int *)(param_3 + 0x4684));
  }
  return;
}

