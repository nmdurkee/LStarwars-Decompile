/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f480; label: FUN_0061f480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061f480(void)

{
  int iVar1;
  int in_EAX;
  
  if ((((in_EAX != 0) && (*(int *)(in_EAX + 0x10) != 0)) &&
      (iVar1 = *(int *)(in_EAX + 0x14), iVar1 != 0)) && (*(int *)(iVar1 + 8) != 0x12)) {
    *(int *)(*(int *)(in_EAX + 0x10) + 8) = iVar1;
  }
  return;
}

