/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x4243e0; label: FUN_004243e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_004243e0(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  
  uVar2 = 0;
  if (*(byte *)(unaff_EDI + 0x25c) != 0xff) {
    uVar2 = 1 << (*(byte *)(unaff_EDI + 0x25c) & 0x1f);
  }
  if (*(byte *)(unaff_EDI + 0x25d) != 0xff) {
    uVar2 = uVar2 | 1 << (*(byte *)(unaff_EDI + 0x25d) & 0x1f);
  }
  if (*(byte *)(unaff_EDI + 0x25e) != 0xff) {
    uVar2 = uVar2 | 1 << (*(byte *)(unaff_EDI + 0x25e) & 0x1f);
  }
  if (*(byte *)(unaff_EDI + 0x25f) != 0xff) {
    uVar2 = uVar2 | 1 << (*(byte *)(unaff_EDI + 0x25f) & 0x1f);
  }
  if (*(byte *)(unaff_EDI + 0x260) != 0xff) {
    uVar2 = uVar2 | 1 << (*(byte *)(unaff_EDI + 0x260) & 0x1f);
  }
  if (*(byte *)(unaff_EDI + 0x262) != 0xff) {
    uVar2 = uVar2 | 1 << (*(byte *)(unaff_EDI + 0x262) & 0x1f);
  }
  if (*(byte *)(unaff_EDI + 0x263) != 0xff) {
    uVar2 = uVar2 | 1 << (*(byte *)(unaff_EDI + 0x263) & 0x1f);
  }
  if (*(byte *)(unaff_EDI + 0x264) != 0xff) {
    uVar2 = uVar2 | 1 << (*(byte *)(unaff_EDI + 0x264) & 0x1f);
  }
  if (uVar2 == 0) {
    uVar2 = 1;
  }
  if (*(byte *)(param_3 + 0x11c) != 0xff) {
    uVar2 = uVar2 | 1 << (*(byte *)(param_3 + 0x11c) & 0x1f);
    if ((((param_2 != -1) && (iVar1 = FUN_00574e20(), iVar1 == 0xc)) && (DAT_008569ac == 0)) &&
       (param_2 == 5)) {
      return uVar2;
    }
    if ((*(byte *)(*(int *)(unaff_EDI + 0x38) + 0x12 + (uint)*(ushort *)(param_1 + 10) * 0x28) &
        0x40) != 0) {
      uVar2 = uVar2 & ~(1 << (*(byte *)(param_3 + 0x11c) & 0x1f));
    }
  }
  return uVar2;
}

