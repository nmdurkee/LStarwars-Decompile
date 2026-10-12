/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b86f0; label: FUN_004b86f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b86f0(float param_1,undefined4 param_2,int param_3,int param_4,float param_5,
                 float param_6,undefined4 param_7,float param_8)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 extraout_ST0;
  
  iVar4 = FUN_006e6b90();
  FUN_005b7d30((float)extraout_ST0,0x3f800000);
  iVar5 = FUN_006e6b90();
  iVar5 = 0xb2 - iVar5;
  iVar6 = 0;
  fVar1 = _DAT_007fc390 * _DAT_007fc388 * param_6 *
          (float)(&DAT_029899a0)[(int)param_8 + 0x4000 >> 1 & 0x7fff];
  param_8 = param_1 - (float)(DAT_007fc384 + -1) * fVar1 * 0.5;
  if (0 < DAT_007fc384) {
    do {
      iVar3 = DAT_007fc384;
      if (param_3 == param_4) {
        iVar5 = iVar5 + 1;
        if (0xb2 < iVar5) {
LAB_004b87c9:
          iVar5 = 0xa9;
        }
      }
      else if (iVar6 < iVar4) {
        iVar5 = 0xb2;
      }
      else {
        if (iVar6 != iVar4) goto LAB_004b87c9;
        iVar5 = FUN_006e6b90();
      }
      fVar2 = _DAT_007fc38c * _DAT_007fc390 * param_5 * param_6;
      FUN_00552c10(param_8,param_2,(float)((iVar3 - iVar6) + -1) * 0.001 + 1.0,fVar2,fVar2,fVar2,0,0
                   ,0,iVar5 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0),0,param_7);
      param_8 = param_8 + fVar1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < DAT_007fc384);
  }
  return;
}

