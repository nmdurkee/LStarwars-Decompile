/* Ghidra pseudocode, not original source.
 * ev_77c3e64cbf166009276f17c020938a120e86ba2ebeb248b147f617680a486917
 * Entry: 0x6059c0; label: FUN_006059c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006059c0(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI != 0) {
    if (((&DAT_0097f9b8)[unaff_ESI * 2] != *(int *)(unaff_EDI + 0x20)) ||
       ((&DAT_0097f9bc)[unaff_ESI * 2] != *(int *)(unaff_EDI + 0x24))) {
      FUN_005fa540();
    }
    FUN_006e5630();
    return;
  }
  FUN_006e5630();
  return;
}

