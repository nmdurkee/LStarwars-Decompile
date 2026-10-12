/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x557600; label: FUN_00557600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00557600(void)

{
  int unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI != 0) {
    FUN_005a15e0(*(undefined4 *)(unaff_ESI + 0x34));
    *(uint *)(unaff_ESI + 0x94) =
         *(uint *)(unaff_ESI + 0x94) ^
         ((uint)(unaff_EDI != 0) * 2 ^ *(uint *)(unaff_ESI + 0x94)) & 2;
  }
  return;
}

