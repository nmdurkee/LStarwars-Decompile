/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60d770; label: FUN_0060d770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060d770(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  
  uVar1 = *(uint *)(in_ECX + 4);
  if ((uVar1 == 0) || ((int)(*(uint *)(in_ECX + 8) - uVar1) >> 3 == 0)) {
    iVar2 = 0;
  }
  else {
    if (*(uint *)(in_ECX + 8) < uVar1) {
      FUN_006e9fe6();
    }
    if ((param_2 == 0) || (param_2 != in_ECX)) {
      FUN_006e9fe6();
    }
    iVar2 = (int)(param_3 - uVar1) >> 3;
  }
  FUN_0060d2b0(param_2,param_3,1,param_4);
  uVar1 = *(uint *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 8) < uVar1) {
    FUN_006e9fe6();
  }
  uVar1 = uVar1 + iVar2 * 8;
  if ((*(uint *)(in_ECX + 8) < uVar1) || (uVar1 < *(uint *)(in_ECX + 4))) {
    FUN_006e9fe6();
  }
  param_1[1] = uVar1;
  *param_1 = in_ECX;
  return;
}

