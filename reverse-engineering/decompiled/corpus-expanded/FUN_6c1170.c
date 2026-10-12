/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c1170; label: FUN_006c1170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c1170(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(int *)(in_ECX + 0x60) = *(int *)(in_ECX + 0x60) + -1;
  iVar1 = in_ECX + *(int *)(in_ECX + 0x60) * 0xc;
  *param_1 = *(undefined4 *)(in_ECX + *(int *)(in_ECX + 0x60) * 0xc);
  uVar2 = *(undefined4 *)(iVar1 + 8);
  param_1[1] = *(undefined4 *)(iVar1 + 4);
  param_1[2] = uVar2;
  return;
}

