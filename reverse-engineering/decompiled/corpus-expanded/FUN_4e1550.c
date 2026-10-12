/* Ghidra pseudocode, not original source.
 * ev_0ee855af08a75d03f9ec13e5e764dc4ef891e4d003f64e7462c0f5c0675bba63
 * Entry: 0x4e1550; label: FUN_004e1550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

