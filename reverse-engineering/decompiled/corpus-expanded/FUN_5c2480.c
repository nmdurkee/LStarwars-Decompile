/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c2480; label: FUN_005c2480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2480(void)

{
  int *piVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI != 0) {
    piVar1 = (int *)FUN_005f8460();
    if (((&DAT_0097f9b8)[unaff_ESI * 2] != *piVar1) || ((&DAT_0097f9bc)[unaff_ESI * 2] != piVar1[1])
       ) {
      FUN_005f8460();
      FUN_005fa540();
    }
  }
  FUN_005f8550();
  return;
}

