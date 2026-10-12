/* Ghidra pseudocode, not original source.
 * ev_50944669d30d55cc8660bd39a1540d3c58ad2d352d01610283ebac90eef0b416
 * Entry: 0x4f0de0; label: FUN_004f0de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f0de0(void)

{
  int iVar1;
  int in_ECX;
  byte *in_EDX;
  
  iVar1 = 0x12345678;
  for (; in_ECX != 0; in_ECX = in_ECX + -1) {
    iVar1 = iVar1 + (uint)*in_EDX;
    in_EDX = in_EDX + 1;
  }
  return iVar1;
}

