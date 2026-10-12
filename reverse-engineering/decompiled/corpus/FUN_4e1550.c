/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e1550; label: FUN_004e1550
 */

void FUN_004e1550(void)

{
  undefined4 uVar1;
  int *piVar2;
  
  DAT_00889048 = 0;
  piVar2 = &DAT_00889038;
  do {
    uVar1 = FUN_00559f50(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_007f90d0,piVar2[5],1,1);
    FUN_0055a250(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),uVar1);
    *(undefined1 *)(*piVar2 + 0x12e) = 1;
    *(ushort *)(*piVar2 + 0x13a) = *(ushort *)(*piVar2 + 0x13a) & 0xffef;
    piVar2 = piVar2 + 1;
  } while ((int)piVar2 < 0x889048);
  return;
}

