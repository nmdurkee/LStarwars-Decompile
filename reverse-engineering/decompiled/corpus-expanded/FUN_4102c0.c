/* Ghidra pseudocode, not original source.
 * ev_6ac18c1e3533fe25fc33452ed7d20d92b2d33ecb9fa34638a091e07f32e3aa59
 * Entry: 0x4102c0; label: FUN_004102c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004102c0(undefined4 *param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  int unaff_ESI;
  float10 fVar4;
  float10 extraout_ST0;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  FUN_005b3470(&local_20,param_1);
  sVar1 = FUN_005be2d0(local_20,local_18);
  *(int *)(unaff_ESI + 0xc4) = (int)sVar1;
  FUN_005b3620(&local_20,&local_20,-(int)sVar1);
  sVar1 = FUN_005be2d0(local_1c,local_18);
  *(int *)(unaff_ESI + 0xc0) = (int)sVar1;
  FUN_005b5060();
  FUN_005b4dd0();
  if (param_3 == 0) {
    sVar1 = FUN_005be2d0(*param_1,param_1[2]);
    FUN_005b3620(&local_30,param_1,-(int)sVar1);
    sVar2 = FUN_005be2d0(local_2c,local_28);
    local_30 = 0x3f800000;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    sVar3 = FUN_006e6b90();
    FUN_005b3690(&local_30,&local_30,sVar3 + 0x4000);
    FUN_005b35a0(&local_30,&local_30,-(int)sVar2);
    FUN_005b3620(&local_30,&local_30,(int)sVar1);
    FUN_005b3470(&local_30,&local_30);
    sVar1 = FUN_005be2d0(local_30,local_2c);
    fVar4 = (float10)_DAT_00925018;
    if ((float10)24000.0 * fVar4 < (float10)(int)sVar1) {
      sVar1 = FUN_006e6b90();
      fVar4 = extraout_ST0;
    }
    if ((float10)(int)sVar1 < fVar4 * (float10)-24000.0) {
      FUN_006e6b90();
    }
    FUN_006e6b90();
    FUN_005b5240();
    return;
  }
  FUN_005b5240();
  return;
}

