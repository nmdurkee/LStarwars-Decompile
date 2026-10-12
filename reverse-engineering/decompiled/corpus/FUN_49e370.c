/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49e370; label: FUN_0049e370
 */

undefined4 FUN_0049e370(void)

{
  undefined1 uVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = FUN_0058dfa0();
  if (iVar2 == 0) {
    *(undefined1 *)(unaff_ESI + 0x7b5) = 0xff;
    return 0;
  }
  *(undefined1 *)(unaff_ESI + 0x7b5) = 0xc;
  *(undefined1 *)(unaff_ESI + 0xe2f) = 0;
  if (*(int *)(unaff_ESI + 0xd04) == 0) {
    *(undefined4 *)(unaff_ESI + 0xd08) = 0;
    if (*(int *)(unaff_ESI + 0xcb0) == 0) {
      iVar2 = *(int *)(unaff_ESI + 0xd00);
      *(undefined4 *)(unaff_ESI + 0x77c) = 0x3dcccccd;
      *(undefined4 *)(unaff_ESI + 0xcb4) = 0;
      if (iVar2 != 0) {
        *(int *)(unaff_ESI + 0xcf8) = iVar2;
        uVar1 = *(undefined1 *)(iVar2 + 0x7aa);
        *(uint *)(unaff_ESI + 0xe20) = *(uint *)(unaff_ESI + 0xe20) | 0x20000000;
        *(undefined1 *)(unaff_ESI + 0xe2e) = uVar1;
        return 1;
      }
      *(int *)(unaff_ESI + 0xcf8) = *(int *)(unaff_ESI + 0xcfc);
      *(char *)(unaff_ESI + 0xe2e) = *(char *)(*(int *)(unaff_ESI + 0xcfc) + 0x7b2) + '\x01';
      return 1;
    }
    *(int *)(unaff_ESI + 0xcb4) = *(int *)(unaff_ESI + 0xcb0);
  }
  else {
    *(int *)(unaff_ESI + 0xd08) = *(int *)(unaff_ESI + 0xd04);
    *(undefined4 *)(unaff_ESI + 0xcb4) = 0;
  }
  *(undefined4 *)(unaff_ESI + 0xcf8) = 0;
  *(undefined1 *)(unaff_ESI + 0xe2e) = 0;
  *(undefined4 *)(unaff_ESI + 0x77c) = 0x3e99999a;
  return 1;
}

