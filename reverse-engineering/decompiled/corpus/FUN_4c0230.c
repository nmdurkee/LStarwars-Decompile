/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4c0230; label: FUN_004c0230
 */

void FUN_004c0230(void)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  *(byte *)(unaff_ESI + 0x3c) = *(byte *)(unaff_ESI + 0x3c) & 0xe7 | 3;
  iVar3 = FUN_0054fa60();
  *(short *)(unaff_ESI + 0x34) =
       ((short)(iVar3 / 0x2493) + (short)(iVar3 >> 0x1f)) -
       (short)((longlong)iVar3 * 0x6ffdd00b >> 0x3f);
  iVar3 = 0;
  do {
    if (*(char *)(*(short *)(unaff_ESI + 0x34) * 0x10 + 0x41e + *(int *)(unaff_EDI + 0x2ac0)) !=
        '\0') break;
    sVar1 = *(short *)(unaff_ESI + 0x34) + 1;
    *(short *)(unaff_ESI + 0x34) = sVar1;
    if (sVar1 == 7) {
      *(undefined2 *)(unaff_ESI + 0x34) = 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 7);
  *(short *)(unaff_ESI + 0x34) = *(short *)(unaff_ESI + 0x34) + 0x41;
  uVar2 = FUN_0054fa60();
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(byte *)(unaff_ESI + 0x3c) = *(byte *)(unaff_ESI + 0x3c) & 0xdb;
  *(undefined2 *)(unaff_ESI + 0x3a) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x10);
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(unaff_ESI + 0x14);
  *(undefined4 *)(unaff_ESI + 0x24) = *(undefined4 *)(unaff_ESI + 0x18);
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  return;
}

