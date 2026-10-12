/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x567da0; label: FUN_00567da0
 */

void FUN_00567da0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  float *pfVar4;
  float10 fVar5;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar1 = *(uint *)(param_1 + 0x98);
  if ((uVar1 & 0x1000) != 0) {
    *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(param_1 + 0x30);
    *(undefined4 *)(param_1 + 0x50) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0x38);
  }
  if ((*(int *)(param_1 + 0xd8) == 0) || ((uVar1 & 0x1000) == 0)) {
    FUN_005d0130(*(int *)(param_1 + 0xa4) + 0x30,&local_7c,&local_88);
    local_60 = local_7c;
    local_5c = local_78;
    local_58 = local_74;
    local_54 = local_88;
    local_48 = local_88;
    local_50 = local_78;
    local_44 = local_78;
    local_4c = local_74;
    local_40 = local_80;
    local_34 = local_80;
    local_3c = local_7c;
    local_30 = local_7c;
    local_38 = local_78;
    local_2c = local_84;
    local_20 = local_84;
    local_14 = local_84;
    local_8 = local_84;
    local_28 = local_74;
    local_1c = local_74;
    local_24 = local_88;
    local_18 = local_88;
    local_10 = local_80;
    local_4 = local_80;
    local_c = local_7c;
    FUN_005c11d0(&local_7c,&local_7c,param_1);
    FUN_005c11d0(&local_88,&local_88,param_1);
    pfVar4 = &local_60;
    iVar3 = 8;
    do {
      FUN_005c11d0(pfVar4,pfVar4,param_1);
      pfVar4 = pfVar4 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar1 = *(uint *)(param_1 + 0x98);
    if ((uVar1 & 0x1000) == 0) {
      *(float *)(param_1 + 0x4c) = (local_88 - local_7c) * 0.5 + local_7c;
      *(float *)(param_1 + 0x50) = (local_84 - local_78) * 0.5 + local_78;
      *(float *)(param_1 + 0x54) = local_74 + (local_80 - local_74) * 0.5;
    }
  }
  if ((*(int *)(param_1 + 0xd8) == 0) && ((*(uint *)(param_1 + 0x94) & 0x4000) != 0)) {
    uVar2 = FUN_0059b0e0(*(undefined4 *)(PTR_DAT_00802c54 + 0x510c),param_1 + 0x4c,
                         *(short *)(param_1 + 0xec) + *(short *)(param_1 + 0xea),
                         *(int *)(param_1 + 0xa4) + 0xb4,0,uVar1 & 0x4000);
    *(undefined4 *)(param_1 + 0xd8) = uVar2;
  }
  local_70 = local_88 - *(float *)(param_1 + 0x4c);
  local_6c = local_84 - *(float *)(param_1 + 0x50);
  local_68 = local_80 - *(float *)(param_1 + 0x54);
  if ((*(uint *)(param_1 + 0x98) & 0x1000) == 0) {
    local_64 = local_68 * local_68 + local_70 * local_70 + local_6c * local_6c;
    fVar5 = (float10)FUN_005c0240(local_64);
    *(float *)(param_1 + 0xa8) = (float)fVar5;
  }
  *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) & 0xfffeffff;
  return;
}

