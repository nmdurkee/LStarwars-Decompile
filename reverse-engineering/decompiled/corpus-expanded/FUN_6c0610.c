/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0610; label: FUN_006c0610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c0610(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 != -1) {
    iVar2 = (**(code **)(*in_ECX + 0x14))(0);
    while (iVar1 = iVar2, iVar1 != 0) {
      iVar2 = (**(code **)(*in_ECX + 0x14))(iVar1);
      if (*(short *)(iVar1 + 0x44) == param_1) {
        (**(code **)(*in_ECX + 0x1c))(iVar1,0);
      }
    }
  }
  return;
}

