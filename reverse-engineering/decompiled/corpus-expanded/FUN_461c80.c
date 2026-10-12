/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x461c80; label: FUN_00461c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00461c80(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x40800000;
    return;
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    FUN_00482f10(param_2,(int)*(char *)(param_2 + 0xb8));
    fVar1 = *(float *)(param_1 + 0x18);
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      if ((*(int *)(param_1 + 0xc) == 0x1a) && (*(char *)(param_2 + 0xa7) == '\x02')) {
        **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x78);
      }
      if ((*(int *)(param_1 + 0xc) == 0x17) && (*(char *)(param_2 + 0xa6) == '\x02')) {
        **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x78);
      }
      FUN_004838f0(param_2);
      return;
    }
    if ((fVar1 < 0.5) && (!NAN(param_3) && 0.5 < param_3 != (param_3 == 0.5))) {
      if (((*(int *)(param_1 + 0xc) == 0x17) && (*(char *)(param_2 + 0xa6) == '\x03')) ||
         ((*(int *)(param_1 + 0xc) == 0x1a && (*(char *)(param_2 + 0xa7) == '\x03')))) {
        FUN_00547930(0x32,0,0,0);
      }
      else {
        FUN_00681f40("StatusAward",0);
      }
      FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      return;
    }
    if (((*(int *)(param_1 + 0xc) == 0x1a) && (*(char *)(param_2 + 0xa7) == '\x02')) ||
       ((*(int *)(param_1 + 0xc) == 0x17 && (*(char *)(param_2 + 0xa6) == '\x02')))) {
      fVar2 = *(float *)(param_1 + 0x1c) - 0.75;
      if ((fVar1 < fVar2) &&
         ((!NAN(fVar2) && !NAN(param_3)) && fVar2 < param_3 != (fVar2 == param_3))) {
        _DAT_0087b93c = 0x3fc00000;
        FUN_004836f0(0xffffffff,0,0x3dcccccd,0);
        FUN_00681f40("Shop_BuyCheat",0);
        return;
      }
      fVar1 = *(float *)(param_1 + 0x18);
      if ((!NAN(fVar1) && 0.75 < fVar1 != (fVar1 == 0.75)) && (*(float *)(param_1 + 0x18) < fVar2))
      {
        FUN_00681f40("PickupCoin",0);
        return;
      }
    }
  }
  return;
}

