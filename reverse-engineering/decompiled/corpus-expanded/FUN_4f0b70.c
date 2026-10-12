/* Ghidra pseudocode, not original source.
 * ev_2eacd74f46b42f047692015e667debd6c21dbe0f18f3288a1bcbfaeff2ef0d47
 * Entry: 0x4f0b70; label: FUN_004f0b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004f0b70(void)

{
  char cVar1;
  uint uVar2;
  char *in_EDX;
  
  uVar2 = 0x811c9dc5;
  cVar1 = *in_EDX;
  while (cVar1 != '\0') {
    uVar2 = ((int)cVar1 ^ uVar2) * 0x199933;
    in_EDX = in_EDX + 1;
    cVar1 = *in_EDX;
  }
  return uVar2;
}

