/* Ghidra pseudocode, not original source.
 * ev_9a76e25c08ce4dcda3c08de929e5a103c2765ccb900e87aba0770623e17ea5fe
 * Entry: 0x6df290; label: FUN_006df290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_006df290(void)

{
  switch(DAT_00826494) {
  default:
    return (float10)1.3333334;
  case 1:
    return (float10)1.7777778;
  case 2:
    return (float10)1.6;
  case 3:
    return (float10)_DAT_02976bf8;
  }
}

