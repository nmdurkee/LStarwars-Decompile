/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x597d90; label: FUN_00597d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00597d90(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x218);
  if ((*(byte *)(iVar1 + 0x9c) & 4) != 0) {
    FUN_00597c20(iVar1,param_1 + 0x30,*(undefined2 *)(param_1 + 0x13a));
    return;
  }
  FUN_005672d0(param_1 + 0x30,iVar1,0,0xf,0);
  return;
}

