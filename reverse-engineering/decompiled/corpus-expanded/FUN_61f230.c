/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f230; label: FUN_0061f230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061f230(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar1 + 0xc) != 0) {
    iVar2 = *(int *)(*(int *)(iVar1 + 0xc) + 4);
    if (iVar2 != 0) {
      *(int *)(iVar1 + 0xc) = iVar2;
    }
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0xc);
  }
  return 0;
}

