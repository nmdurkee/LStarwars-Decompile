/* Ghidra pseudocode, not original source.
 * ev_573fcacabc8e68ea03635b0f8aa232ed45a87b6cc51fa6af4ed20e3c9ee5dc27
 * Entry: 0x5d18d0; label: FUN_005d18d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005d18d0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = DAT_009738d4;
  if (DAT_009738d4 == (int *)0x0) {
    return (int *)0x0;
  }
  do {
    iVar1 = FUN_004f8b10(param_1,piVar2 + 2);
    if (iVar1 == 0) {
      return piVar2;
    }
    piVar2 = (int *)*piVar2;
  } while (piVar2 != (int *)0x0);
  return (int *)0x0;
}

