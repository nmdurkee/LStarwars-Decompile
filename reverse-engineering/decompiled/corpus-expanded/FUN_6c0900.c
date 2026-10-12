/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0900; label: FUN_006c0900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006c0900(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar3 = param_3;
  if (((*(int *)(in_ECX + 0xc) != 0) && (1 < param_2)) && (iVar2 = param_1, 0 < param_3)) {
    do {
      if (param_2 == 2) {
        FUN_00621180(iVar2);
      }
      else if (param_2 == 4) {
        FUN_00621190(iVar2);
      }
      param_3 = param_3 + -1;
      iVar2 = iVar2 + param_2;
    } while (param_3 != 0);
  }
  uVar1 = FUN_004f03d0(*(undefined4 *)(in_ECX + 0x44),param_1,param_2 * iVar3);
  if (((*(int *)(in_ECX + 0xc) != 0) && (1 < param_2)) && (0 < iVar3)) {
    do {
      if (param_2 == 2) {
        FUN_00621180(param_1);
      }
      else if (param_2 == 4) {
        FUN_00621190(param_1);
      }
      param_1 = param_1 + param_2;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return uVar1;
}

