/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d94b0; label: FUN_004d94b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004d94b0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(DAT_00882a6c + 0xa694);
  do {
    if (*piVar2 == 0) {
      return iVar1 * 0xa0 + 0xa600 + DAT_00882a6c;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x28;
  } while (iVar1 < 0x10);
  return 0;
}

