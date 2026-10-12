/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x426b50; label: FUN_00426b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_00426b50(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar4 = 0;
  iVar3 = -1;
  piVar1 = &DAT_008569dc;
  iVar2 = 0;
  do {
    if (((char)piVar1[1] == '\0') || (*piVar1 != unaff_EDI)) {
      if (iVar3 == -1) {
        iVar3 = iVar2;
      }
    }
    else {
      iVar4 = iVar4 + 1;
      if (iVar4 == 3) {
        return (undefined *)0x0;
      }
    }
    piVar1 = piVar1 + 0xe;
    iVar2 = iVar2 + 1;
  } while ((int)piVar1 < 0x856c0c);
  if (iVar3 == -1) {
    return (undefined *)0x0;
  }
  return &DAT_008569b8 + iVar3 * 0x38;
}

