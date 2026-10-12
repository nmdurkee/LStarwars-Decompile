/* Ghidra analysis pseudocode, not original source.
 * ev_5f3da693bf096313253939ed49ba5271cfe8862e4a440ae5c9d57980f69a0d69
 * Entry: 0x463f30; label: FUN_00463f30
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463f30(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  float10 fVar6;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = _DAT_007f8634;
  fVar2 = 1.0;
  local_4 = 0x3f800000;
  if (param_3 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x14) == 0) {
    _DAT_0087a1d0 = 0.0;
    return;
  }
  fVar1 = *(float *)(param_1 + 0x18);
  if (NAN(fVar1) || 0.5 < fVar1 == (fVar1 == 0.5)) {
    fVar2 = *(float *)(param_1 + 0x18) + *(float *)(param_1 + 0x18);
  }
  _DAT_0087a1d0 = fVar2;
  if (*(float *)(param_1 + 0x18) < 2.0) {
    fVar6 = (float10)FUN_005b7d30(*(undefined4 *)(param_1 + 0x18),0x3e4ccccd);
    if ((float10)0.10000000149011612 <= fVar6) {
      uVar5 = *(uint *)(param_2 + 0xb0) >> 5 & 1;
      if (uVar5 == 0) {
        uVar3 = 0xbf2ccccd;
      }
      else {
        uVar3 = 0x3f2ccccd;
      }
      uVar4 = FUN_006e6b90();
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_0088073c * 4),uVar3,_DAT_007fc310,0x3f800000,
                   0x3f333333,0x3f333333,0x3f333333,(-(uVar5 != 0) & 6U) + 2,0,0xff,0,0x3eb33333,1,0
                   ,0,uVar4);
    }
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    FUN_00560fa0(*(undefined4 *)(DAT_00926c20 + DAT_008806c8 * 4),&local_c,0x3f333333,&local_c,
                 0x3f333333,0xff,0,0x7f,0x4020,0x40000000);
  }
  return;
}

