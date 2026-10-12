/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x637e10; label: FUN_00637e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00637e10(void)

{
  int iVar1;
  char *pcVar2;
  
  if (DAT_0291389c != 0) {
    iVar1 = 0;
    pcVar2 = (char *)(DAT_0291389c + 0x5c);
    do {
      if (*pcVar2 == '\0') {
        return iVar1 * 0x8c + 4 + DAT_0291389c;
      }
      iVar1 = iVar1 + 1;
      pcVar2 = pcVar2 + 0x8c;
    } while (iVar1 < 0x80);
  }
  return 0;
}

