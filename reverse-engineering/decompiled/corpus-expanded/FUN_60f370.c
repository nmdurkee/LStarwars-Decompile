/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60f370; label: FUN_0060f370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f370(void)

{
  int *piVar1;
  int *piVar2;
  int *in_ECX;
  
  if (in_ECX != in_ECX + 0x25a00) {
    piVar2 = in_ECX + 300;
    do {
      if (*piVar2 != 0) {
        *piVar2 = 0;
      }
      piVar1 = piVar2 + 1;
      piVar2 = piVar2 + 0x12d;
    } while (piVar1 != in_ECX + 0x25a00);
  }
  return;
}

