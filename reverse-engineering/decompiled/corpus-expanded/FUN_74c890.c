/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74c890; label: FUN_0074c890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074c890(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  iVar3 = in_ECX[1];
  if (iVar2 == 0) {
    FUN_006e9fe6();
  }
  uVar1 = iVar3 + param_2 * 4;
  if ((*(uint *)(iVar2 + 8) < uVar1) || (uVar1 < *(uint *)(iVar2 + 4))) {
    FUN_006e9fe6();
  }
  param_1[1] = uVar1;
  *param_1 = iVar2;
  return;
}

