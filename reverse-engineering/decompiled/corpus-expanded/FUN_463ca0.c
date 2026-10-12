/* Ghidra pseudocode, not original source.
 * ev_a0c576544e413369fb0a5ddd4679e51ae37c83af368344a8e8d6b5078f1bd76b
 * Entry: 0x463ca0; label: FUN_00463ca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00463ca0(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 **ppuVar5;
  float local_7c;
  int local_78;
  undefined4 local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 *local_58 [4];
  undefined4 local_48;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  short local_32;
  int local_30;
  uint local_2c;
  undefined1 *local_18;
  code *local_10;
  char local_c;
  undefined1 local_a;
  
  local_7c = 0.0;
  iVar2 = *(int *)(param_1 + 0x14);
  local_64 = 0;
  local_60 = _DAT_007fc310;
  local_5c = 0x3f800000;
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x40800000;
    return;
  }
  if (iVar2 == 1) {
    fVar1 = *(float *)(param_1 + 0x18);
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if ((1.5 <= param_3) && (iVar2 = FUN_005618e0(1,0,0xffffffff,0), iVar2 == 0)) {
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x14) = 2;
      *(undefined4 *)(param_1 + 0x1c) = 0x3f800000;
      return;
    }
    if ((fVar1 < 1.0) && (1.0 < *(float *)(param_1 + 0x18) != (*(float *)(param_1 + 0x18) == 1.0)))
    {
      local_78 = 0x32;
      do {
        local_70 = 0;
        iVar2 = FUN_0054fa60();
        local_6c = (float)iVar2 * 1.5259022e-05 * 0.1;
        local_68 = 0x3f800000;
        uVar3 = FUN_0054fa60();
        FUN_005b3690(&local_70,&local_70,uVar3);
        puVar4 = &DAT_00802cd8;
        ppuVar5 = local_58;
        for (iVar2 = 0x14; iVar2 != 0; iVar2 = iVar2 + -1) {
          *ppuVar5 = (undefined4 *)*puVar4;
          puVar4 = puVar4 + 1;
          ppuVar5 = ppuVar5 + 1;
        }
        local_48 = 0x3f400000;
        local_58[1] = &local_70;
        iVar2 = FUN_0054fa60();
        local_c = (char)((int)(iVar2 + (iVar2 >> 0x1f & 0x7fffU)) >> 0xf);
        local_64 = *(undefined4 *)(&DAT_0087b9ac + local_c * 4);
        local_32 = DAT_007f8e78;
        local_48 = _DAT_007fc368;
        local_58[2] = &local_64;
        local_30 = DAT_007f8e78 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
        local_2c = (uint)DAT_007f8e7a;
        local_3c = _DAT_008033a8;
        local_38 = local_7c;
        local_40 = 0x112d;
        local_a = 1;
        local_10 = FUN_0046af20;
        local_18 = &LAB_0046af00;
        FUN_00560b60(local_58);
        if (local_7c == 0.0) {
          FUN_004836f0(0xffffffff,0,0,1);
          FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x38,&local_70);
        }
        local_78 = local_78 + -1;
        local_7c = local_7c + 0.1;
      } while (local_78 != 0);
      return;
    }
  }
  else if ((iVar2 == 2) &&
          (param_3 = *(float *)(param_1 + 0x18) + param_3, *(float *)(param_1 + 0x18) = param_3,
          *(float *)(param_1 + 0x1c) < param_3)) {
    FUN_00681f40("Shop_BuyCheat",0);
    FUN_004838f0(param_2);
    return;
  }
  return;
}

