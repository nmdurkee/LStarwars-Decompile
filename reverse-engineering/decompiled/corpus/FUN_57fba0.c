/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57fba0; label: FUN_0057fba0
 */

undefined4 * FUN_0057fba0(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00951cc8 * 0x138;
  iVar2 = 0;
  if ((&DAT_00951de8)[iVar1] != '\0') {
    do {
      if ((((&DAT_00951dd8)[iVar1] & 8) == 0) || (0x1f < iVar2)) break;
      DAT_00951cc8 = DAT_00951cc8 + 1;
      if (DAT_00951cc8 == 0x20) {
        DAT_00951cc8 = 0;
      }
      iVar1 = DAT_00951cc8 * 0x138;
      iVar2 = iVar2 + 1;
    } while ((&DAT_00951de8)[iVar1] != '\0');
    if (0x20 < iVar2) {
      return (undefined4 *)0x0;
    }
  }
  iVar1 = DAT_00951cc8 * 0x4e;
  DAT_00951cc8 = DAT_00951cc8 + 1 & 0x8000001f;
  if ((int)DAT_00951cc8 < 0) {
    DAT_00951cc8 = (DAT_00951cc8 - 1 | 0xffffffe0) + 1;
  }
  return &DAT_00951ce8 + iVar1;
}

