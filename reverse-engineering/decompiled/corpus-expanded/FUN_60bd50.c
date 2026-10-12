/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60bd50; label: FUN_0060bd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060bd50(int *param_1,int param_2)

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
  uVar1 = iVar3 + param_2 * 8;
  if ((*(uint *)(iVar2 + 8) < uVar1) || (uVar1 < *(uint *)(iVar2 + 4))) {
    FUN_006e9fe6();
  }
  param_1[1] = uVar1;
  *param_1 = iVar2;
  return;
}

