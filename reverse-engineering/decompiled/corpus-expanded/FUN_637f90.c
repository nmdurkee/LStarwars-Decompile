/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x637f90; label: FUN_00637f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00637f90(void)

{
  int iVar1;
  int *piVar2;
  
  if (DAT_0291389c != 0) {
    iVar1 = 0;
    piVar2 = (int *)(DAT_0291389c + 0x4618);
    do {
      if (*piVar2 == 0) {
        return iVar1 * 0x4c + 0x4604 + DAT_0291389c;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0x13;
    } while (iVar1 < 0x20);
  }
  return 0;
}

