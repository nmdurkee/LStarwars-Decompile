/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x443ab0; label: FUN_00443ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00443ab0(void)

{
  int iVar1;
  float10 fVar2;
  int in_stack_00000014;
  
  if (in_stack_00000014 == 0) {
    fVar2 = (float10)0;
  }
  else {
    iVar1 = FUN_0055a1b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),in_stack_00000014,2,1);
    fVar2 = (float10)iVar1;
    if (iVar1 < 0) {
      return fVar2 + (float10)4.2949673e+09;
    }
  }
  return fVar2;
}

