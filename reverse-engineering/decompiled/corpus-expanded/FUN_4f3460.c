/* Ghidra pseudocode, not original source.
 * ev_e27af7f74871e1dc60c6c80a9c8e67e6864abe93d2064640e98ee3190c864676
 * Entry: 0x4f3460; label: FUN_004f3460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f3460(void)

{
  int iVar1;
  int iVar2;
  short unaff_SI;
  short unaff_DI;
  
  iVar2 = 0;
  if (unaff_SI == unaff_DI) {
    return 1;
  }
  if (DAT_0080048c != 0) {
    iVar1 = 0;
    do {
      if ((*(short *)((int)&DAT_0080048e + iVar1) == unaff_SI) &&
         (*(short *)((int)&DAT_0080048c + iVar1) == unaff_DI)) {
        return 1;
      }
      if ((*(short *)((int)&DAT_0080048e + iVar1) == unaff_DI) &&
         (*(short *)((int)&DAT_0080048c + iVar1) == unaff_SI)) {
        return 1;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar2 * 4;
    } while ((&DAT_0080048c)[iVar2 * 2] != 0);
  }
  return 0;
}

