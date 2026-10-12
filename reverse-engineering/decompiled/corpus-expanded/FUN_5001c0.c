/* Ghidra pseudocode, not original source.
 * ev_e3284882596e4924dd8e2753f6ae25b39d285bc55fae2794478040fb50a7242b
 * Entry: 0x5001c0; label: FUN_005001c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

