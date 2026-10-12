/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c05d0; label: FUN_006c05d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c05d0(void)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  if (0 < *(int *)(in_ECX + 0x10)) {
    iVar1 = 0;
    iVar2 = 0;
    do {
      FUN_006ba8a0(*(int *)(in_ECX + 0x14) + iVar1,0x3f000000,0xffffffff);
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10;
    } while (iVar2 < *(int *)(in_ECX + 0x10));
  }
  return;
}

