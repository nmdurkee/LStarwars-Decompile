/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74db00; label: FUN_0074db00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074db00(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  
  uVar1 = *(uint *)(in_ECX + 4);
  if ((uVar1 == 0) || ((int)(*(uint *)(in_ECX + 8) - uVar1) >> 2 == 0)) {
    iVar2 = 0;
  }
  else {
    if (*(uint *)(in_ECX + 8) < uVar1) {
      FUN_006e9fe6();
    }
    if ((param_2 == 0) || (param_2 != in_ECX)) {
      FUN_006e9fe6();
    }
    iVar2 = (int)(param_3 - uVar1) >> 2;
  }
  FUN_0074d8a0(param_2,param_3,1,param_4);
  uVar1 = *(uint *)(in_ECX + 4);
  if (*(uint *)(in_ECX + 8) < uVar1) {
    FUN_006e9fe6();
  }
  uVar1 = uVar1 + iVar2 * 4;
  if ((*(uint *)(in_ECX + 8) < uVar1) || (uVar1 < *(uint *)(in_ECX + 4))) {
    FUN_006e9fe6();
  }
  param_1[1] = uVar1;
  *param_1 = in_ECX;
  return;
}

