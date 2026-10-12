/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414f20; label: FUN_00414f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00414f20(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = DAT_0093d504;
  if (0 < DAT_0093d500) {
    do {
      if (((*(byte *)(iVar1 + 0x1fc) & 1) != 0) && ((*(uint *)(iVar1 + 0x1f8) & 0x400) != 0)) {
        FUN_004d22f0(iVar1 + 0xcc4);
        FUN_0055cad0(iVar1,1);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 0x10d8;
    } while (iVar2 < DAT_0093d500);
  }
  return;
}

