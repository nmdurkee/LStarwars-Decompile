/* Ghidra pseudocode, not original source.
 * ev_1103904689436dd579d46533c258b0710963d6b5b648a9f295784d5cea761bb8
 * Entry: 0x634850; label: FUN_00634850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00634850(void)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = 0;
  pcVar2 = (char *)(DAT_0291389c + 0xe8);
  iVar3 = 0x20;
  do {
    if (pcVar2[-0x8c] != '\0') {
      iVar1 = iVar1 + 1;
    }
    if (*pcVar2 != '\0') {
      iVar1 = iVar1 + 1;
    }
    if (pcVar2[0x8c] != '\0') {
      iVar1 = iVar1 + 1;
    }
    if (pcVar2[0x118] != '\0') {
      iVar1 = iVar1 + 1;
    }
    pcVar2 = pcVar2 + 0x230;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}

