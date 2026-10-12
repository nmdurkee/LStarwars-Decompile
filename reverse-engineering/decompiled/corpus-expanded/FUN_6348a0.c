/* Ghidra pseudocode, not original source.
 * ev_1103904689436dd579d46533c258b0710963d6b5b648a9f295784d5cea761bb8
 * Entry: 0x6348a0; label: FUN_006348a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006348a0(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  if (DAT_0291389c != 0) {
    if (param_1 == 0) {
      return DAT_0291389c + 4;
    }
    iVar1 = ((param_1 - DAT_0291389c) + -4) / 0x8c + 1;
    if (iVar1 < 0x80) {
      pcVar2 = (char *)(iVar1 * 0x8c + 0x5c + DAT_0291389c);
      do {
        if (*pcVar2 != '\0') {
          return iVar1 * 0x8c + 4 + DAT_0291389c;
        }
        iVar1 = iVar1 + 1;
        pcVar2 = pcVar2 + 0x8c;
      } while (iVar1 < 0x80);
    }
  }
  return 0;
}

