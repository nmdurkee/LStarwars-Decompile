/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x504c50; label: FUN_00504c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00504c50(void)

{
  int *piVar1;
  
  if (DAT_00921324 != (int *)0x0) {
    do {
      piVar1 = DAT_00921324;
      DAT_00921324 = (int *)*piVar1;
      *piVar1 = (int)DAT_009212dc;
      if (DAT_009212dc != (int *)0x0) {
        DAT_009212dc[1] = (int)piVar1;
      }
      piVar1[1] = 0;
      DAT_009212dc = piVar1;
    } while (DAT_00921324 != (int *)0x0);
    DAT_00921324 = (int *)0x0;
  }
  return;
}

