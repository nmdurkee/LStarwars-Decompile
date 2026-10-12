/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x584910; label: FUN_00584910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00584910(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = FUN_004f7fb0();
  if (iVar1 != 0) {
    iVar1 = FUN_004f8b10(*(undefined4 *)(unaff_ESI + 0x510),&DAT_00758e24);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

