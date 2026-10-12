/* Ghidra pseudocode, not original source.
 * ev_49c5de326560f696c25fe7c48a171edc0aeca1661cc4385396c06e099fff9572
 * Entry: 0x4436d0; label: FUN_004436d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004436d0(void)

{
  int iVar1;
  
  iVar1 = FUN_00574e20();
  if (iVar1 == 0xd) {
    return (float10)1;
  }
  return (float10)0;
}

