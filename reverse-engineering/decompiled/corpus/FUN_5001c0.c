/* Ghidra analysis pseudocode, not original source.
 * ev_b66c424cb3575f57780fb90d996a1c84f19feddd26ab04bda15cdd4040b17690
 * Entry: 0x5001c0; label: FUN_005001c0
 */

void FUN_005001c0(void)

{
  int *piVar1;
  
  if (DAT_009212d8 != (int *)0x0) {
    do {
      piVar1 = DAT_009212d8;
      DAT_009212d8 = (int *)*piVar1;
      *piVar1 = (int)DAT_0092133c;
      if (DAT_0092133c != (int *)0x0) {
        DAT_0092133c[1] = (int)piVar1;
      }
      piVar1[1] = 0;
      DAT_0092133c = piVar1;
    } while (DAT_009212d8 != (int *)0x0);
    DAT_009212d8 = (int *)0x0;
  }
  return;
}

