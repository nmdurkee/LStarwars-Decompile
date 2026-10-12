/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5f99d0; label: FUN_005f99d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f99d0(void)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_8 [8];
  
  if (DAT_02854bf0 != (int *)0x0) {
    (**(code **)(*DAT_02854bf0 + 8))(DAT_02854bf0);
    DAT_02854bf0 = (int *)0x0;
  }
  FUN_006e4810(0x70,0,0,1,&DAT_02854bf0);
  piVar3 = DAT_02854bf0;
  iVar2 = (**(code **)(*DAT_02854bf0 + 0x2c))(DAT_02854bf0,0,0,auStack_8,0);
  if (-1 < iVar2) {
    *piVar3 = 0;
    piVar3[1] = 0;
    piVar3[2] = 0x3f000000;
    fVar1 = (float)DAT_02976700;
    if (DAT_02976700 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    piVar3[7] = (int)fVar1;
    piVar3[8] = 0;
    piVar3[9] = 0x3f000000;
    fVar1 = (float)DAT_02976700;
    if (DAT_02976700 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    piVar3[0xe] = (int)fVar1;
    fVar1 = (float)DAT_02976704;
    if (DAT_02976704 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    piVar3[0xf] = (int)fVar1;
    piVar3[0x10] = 0x3f000000;
    piVar3[0x15] = 0;
    fVar1 = (float)DAT_02976704;
    if (DAT_02976704 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    piVar3[0x16] = (int)fVar1;
    piVar3[0x17] = 0x3f000000;
    piVar3[0x19] = 0x4b000000;
    piVar3[0x12] = 0x4b000000;
    piVar3[0xb] = 0x4b000000;
    piVar3[4] = 0x4b000000;
    piVar3[0x18] = 0x3f800000;
    piVar3[0x11] = 0x3f800000;
    piVar3[10] = 0x3f800000;
    piVar3[3] = 0x3f800000;
    (**(code **)(*DAT_02854bf0 + 0x30))(DAT_02854bf0);
  }
  return;
}

