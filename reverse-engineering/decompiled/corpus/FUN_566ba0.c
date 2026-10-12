/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x566ba0; label: FUN_00566ba0
 */

void FUN_00566ba0(void)

{
  int iVar1;
  int unaff_ESI;
  
  *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) & 0xfeff7ffe | 0x804000;
  *(undefined1 *)(unaff_ESI + 0x110) = *(undefined1 *)(unaff_ESI + 0x111);
  *(undefined1 *)(unaff_ESI + 0x10e) = *(undefined1 *)(unaff_ESI + 0x10f);
  iVar1 = FUN_005d0420(*(int *)(unaff_ESI + 0xa4) + 0x30);
  if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x50) & 1) != 0)) {
    *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) | 0x100000;
    if ((*(byte *)(iVar1 + 0x50) & 8) != 0) {
      *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) | 0x480000;
    }
  }
  *(uint *)(unaff_ESI + 0x94) = *(uint *)(unaff_ESI + 0x94) | 0x10000;
  return;
}

