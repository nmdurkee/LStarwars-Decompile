/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x4433e0; label: FUN_004433e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004433e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
      (iVar1 = *(int *)(**(int **)(param_3 + 0xd0) + 0x10a8), iVar1 != 0)) &&
     ((*(byte *)(iVar1 + 0x1fc) & 0x80) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

