/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f310; label: FUN_0061f310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0061f310(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 0x3c), iVar2 != 0)) &&
     (*(code **)(iVar2 + 0x30) != (code *)0x0)) {
    (**(code **)(iVar2 + 0x30))(iVar2,iVar1);
  }
  return 0;
}

