/* Ghidra analysis pseudocode, not original source.
 * ev_d9778a7e5954a243ecb5357ce6ca10d0e931dd6eaae906e14f50961a2e2268e2
 * Entry: 0x4bbbf0; label: FUN_004bbbf0
 */

void FUN_004bbbf0(void)

{
  int iVar1;
  
  FUN_005d4290(1);
  FUN_0050e6a0();
  FUN_00595720(0x3f800000);
  FUN_005ebd80(0xe00,0xff000000,0x3f800000);
  FUN_00565d00();
  FUN_004bae40();
  FUN_005b10a0();
  (**(code **)(*DAT_0095e418 + 0x28))(0);
  FUN_005f3950();
  FUN_005b1180();
  if ((PTR_DAT_00802c54 != (undefined *)0x0) && (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b88)
     ) {
    FUN_006e6b90();
    FUN_005d4290(1);
    DAT_02854d1c = DAT_02854d1c + 1;
    FUN_00600b20(2);
    FUN_00607d70(0x10,5,DAT_00950700);
    FUN_004b7080();
    FUN_006009e0(0,0,0);
    FUN_004b7080();
    FUN_006009e0(0x3f800000,0x3f800000,0);
    FUN_006009a0();
    iVar1 = DAT_02854d1c * 4;
    DAT_02854d1c = DAT_02854d1c + -1;
    FUN_00600b20(*(undefined4 *)(&DAT_00981c4c + iVar1));
    FUN_005f3950();
    return;
  }
  return;
}

