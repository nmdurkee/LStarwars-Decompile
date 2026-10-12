/* Ghidra analysis pseudocode, not original source.
 * ev_f6f29f3a3b14d12541c710eb91fc3c5282bb00f37b38cc241e06611dc1b7516b
 * Entry: 0x49e2b0; label: FUN_0049e2b0
 */

void FUN_0049e2b0(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int unaff_ESI;
  
  uVar1 = *(undefined4 *)(*(int *)(*(int *)(unaff_ESI + 0x54) + 0x24) + 0x38);
  *(uint *)(unaff_ESI + 0x7bc) = *(uint *)(unaff_ESI + 0x7bc) & 0xfffeffff;
  *(undefined4 *)(unaff_ESI + 0x6c) = uVar1;
  *(undefined1 *)(unaff_ESI + 0x7b5) = 0;
  *(undefined1 *)(unaff_ESI + 0x7b8) = 2;
  if (param_1 == 0) {
    *(undefined2 *)(unaff_ESI + 0x7aa) = 0x12;
    uVar2 = *(uint *)(unaff_ESI + 0x7bc) & 0xffffdfff;
  }
  else {
    *(undefined2 *)(unaff_ESI + 0x7aa) = 0xc;
    uVar2 = *(uint *)(unaff_ESI + 0x7bc) | 0x2000;
  }
  *(uint *)(unaff_ESI + 0xe20) = *(uint *)(unaff_ESI + 0xe20) | 0x100000;
  *(undefined4 *)(unaff_ESI + 0x77c) = 0;
  *(undefined4 *)(unaff_ESI + 0xd48) = 0;
  *(uint *)(unaff_ESI + 0x7bc) = uVar2;
  *(uint *)(unaff_ESI + 0x7bc) = *(uint *)(unaff_ESI + 0x7bc) & 0xffff6fff;
  *(undefined4 *)(unaff_ESI + 0xd2c) = 0;
  *(undefined1 *)(unaff_ESI + 0x281) = 0;
  *(undefined2 *)(unaff_ESI + 0x1050) = 0;
  *(undefined4 *)(unaff_ESI + 0xd1c) = 0;
  FUN_00547f30();
  FUN_0062e650(unaff_ESI + 8,(int)*(short *)(unaff_ESI + 0x7aa));
  if ((*(byte *)(unaff_ESI + 0x1fc) & 0x80) != 0) {
    *(uint *)(unaff_ESI + 0xeec) = *(uint *)(unaff_ESI + 0xeec) | 0x800;
  }
  return;
}

