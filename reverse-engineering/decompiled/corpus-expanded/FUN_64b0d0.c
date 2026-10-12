/* Ghidra pseudocode, not original source.
 * ev_3e786b2ab64c48f97439d141d8ad45f587e334c03ef45226df6d6e53cdeb8069
 * Entry: 0x64b0d0; label: FUN_0064b0d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0064b0d0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_0291f820;
  do {
    if (piVar2[-0x1b] != -1) {
      iVar1 = iVar1 + 1;
    }
    if (*piVar2 != -1) {
      iVar1 = iVar1 + 1;
    }
    if (piVar2[0x1b] != -1) {
      iVar1 = iVar1 + 1;
    }
    if (piVar2[0x36] != -1) {
      iVar1 = iVar1 + 1;
    }
    if (piVar2[0x51] != -1) {
      iVar1 = iVar1 + 1;
    }
    piVar2 = piVar2 + 0x87;
  } while ((int)piVar2 < 0x2920900);
  return iVar1;
}

