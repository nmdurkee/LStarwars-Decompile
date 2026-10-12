/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x566290; label: FUN_00566290
 */

void FUN_00566290(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_00802e14 != 0) {
    if (DAT_00950750 != 0) {
      puVar2 = &DAT_00806680;
      puVar3 = DAT_00925164;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      FUN_00603cc0(DAT_00925164);
      do {
        FUN_004f3e20();
        FUN_005d4290(1);
        FUN_005ebd80(0xb00,0,0x3f800000);
        FUN_00564af0(0x3f800000,1);
        FUN_005f3950();
        FUN_0065f4d0();
        FUN_004fd050();
        FUN_0065f4e0();
        param_1 = param_1 + -1;
      } while (0 < param_1);
      DAT_00950750 = 0;
      return;
    }
    if (DAT_009507a0 != -1) {
      do {
        FUN_004f3e20();
        FUN_005b1180();
        FUN_0065f4d0();
        FUN_004fd050();
        FUN_0065f4e0();
        param_1 = param_1 + -1;
      } while (0 < param_1);
      return;
    }
    do {
      FUN_004f3e20();
      FUN_005d4290(1);
      FUN_005ebd80(0xb00,0,0x3f800000);
      FUN_005f3950();
      FUN_0065f4d0();
      FUN_004fd050();
      FUN_0065f4e0();
      param_1 = param_1 + -1;
    } while (0 < param_1);
  }
  return;
}

