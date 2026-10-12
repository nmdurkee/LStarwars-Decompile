/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x501240; label: FUN_00501240
 */

int FUN_00501240(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (DAT_009213c0 != (int *)0x0) {
    iVar1 = *DAT_009213c0;
    while (iVar1 != 0) {
      iVar1 = FUN_004f8b10();
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar1 = DAT_009213c0[iVar2 * 5];
    }
  }
  return -1;
}

