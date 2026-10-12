/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x4632e0; label: FUN_004632e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004632e0(int param_1,int param_2,float param_3)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x1c) = 0x40a00000;
    *(undefined4 *)(param_2 + 0x74) = **(undefined4 **)(param_2 + 0x1c);
    return;
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    fVar1 = *(float *)(param_1 + 0x18);
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 == (*(float *)(param_1 + 0x1c) == param_3)) {
      if ((fVar1 < 0.5) && (!NAN(param_3) && 0.5 < param_3 != (param_3 == 0.5))) {
        if (*(int *)(param_2 + 0x70) == 0) {
          FUN_00547930(0x32,0,0,0);
        }
        else {
          FUN_00681f40("StatusAward");
        }
        FUN_004836f0(0xffffffff,0x3f19999a,0,0);
      }
    }
    else {
      **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x80);
      FUN_004838f0(param_2);
    }
    if (*(int *)(param_2 + 0x80) != *(int *)(param_2 + 0x74)) {
      if ((fVar1 < 4.0) &&
         (fVar1 = *(float *)(param_1 + 0x18), !NAN(fVar1) && 4.0 < fVar1 != (fVar1 == 4.0))) {
        _DAT_0087b93c = 0x3fc00000;
        FUN_004836f0(0xffffffff,0,0x3dcccccd,0);
        FUN_00681f40("Shop_BuyCheat",0);
      }
      if (4.0 < *(float *)(param_1 + 0x18) == (*(float *)(param_1 + 0x18) == 4.0)) {
        fVar1 = *(float *)(param_1 + 0x18);
        if ((!NAN(fVar1) && 0.5 < fVar1 != (fVar1 == 0.5)) && (*(float *)(param_1 + 0x18) < 4.0)) {
          uVar2 = *(undefined4 *)(param_2 + 0x74);
          FUN_006e6b90();
          iVar3 = FUN_006e6b90();
          **(undefined4 **)(param_2 + 0x1c) = uVar2;
          FUN_005533f0(*(undefined4 *)(param_2 + 0x1c),iVar3,iVar3 >> 0x1f,0);
          iVar3 = FUN_006e6b90();
          iVar4 = FUN_006e6b90();
          if (iVar4 != iVar3) {
            FUN_00681f40("PickupCoin",0);
            return;
          }
        }
      }
      else {
        **(undefined4 **)(param_2 + 0x1c) = *(undefined4 *)(param_2 + 0x80);
      }
    }
  }
  return;
}

