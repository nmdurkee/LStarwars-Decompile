/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67b1b0; label: FUN_0067b1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0067b1b0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (DAT_0292fc68 != 0) {
    piVar2 = (int *)(DAT_0292fc68 + 0x198);
    do {
      if (*piVar2 == param_1) {
        DAT_02947c74 = DAT_0292fc68 + (iVar1 * 3 + 0x33) * 8;
        goto LAB_0067b1d8;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 6;
    } while (iVar1 < 0x40);
    DAT_02947c74 = 0;
LAB_0067b1d8:
    if (DAT_02947c74 == 0) {
      return 0;
    }
    iVar1 = (int)*(short *)(DAT_02947c74 + 8);
  }
  return iVar1;
}

