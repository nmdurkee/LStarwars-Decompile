/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0c50; label: FUN_005d0c50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005d0c50(float param_1,ushort *param_2)

{
  float fVar1;
  byte bVar2;
  ushort uVar3;
  int iVar5;
  float10 fVar6;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float10 fVar7;
  float local_8;
  uint uVar4;
  
  bVar2 = (byte)DAT_009738c4;
  iVar5 = (int)param_1;
  if ((param_1 == 0.0) && (iVar5 = DAT_009738b8, DAT_009738b8 == 0)) {
    return (float10)0;
  }
  fVar7 = (float10)0;
  local_8 = (float)fVar7;
  fVar1 = **(float **)(iVar5 + 0x2c);
  uVar3 = *param_2;
  if (uVar3 != 0) {
    fVar6 = (float10)_DAT_009738b4;
    do {
      uVar4 = (uint)uVar3;
      param_2 = param_2 + 1;
      if (uVar4 < 0x3a) {
        if (uVar4 < 0x30) {
          if ((uVar4 != 0x20) || (fVar7 == fVar6)) goto LAB_005d0cfe;
          param_1 = (float)fVar6;
        }
        else if ((bVar2 & 1) == 0) {
          param_1 = *(float *)(*(int *)(iVar5 + 0x34) + 8 + uVar4 * 0xc);
        }
        else {
          uVar4 = FUN_005d0b40(iVar5,0x30);
          param_1 = *(float *)(*(int *)(iVar5 + 0x34) + 8 + (uVar4 & 0xffff) * 0xc);
          fVar6 = extraout_ST0;
          fVar7 = extraout_ST1;
        }
      }
      else if (uVar4 == 0xffff) {
        param_1 = (float)fVar7;
      }
      else {
LAB_005d0cfe:
        param_1 = *(float *)(*(int *)(iVar5 + 0x34) + 8 + uVar4 * 0xc);
      }
      uVar3 = *param_2;
      local_8 = *(float *)(iVar5 + 0x24) + param_1 + local_8;
    } while (uVar3 != 0);
  }
  return (float10)(_DAT_0080b608 * local_8 * fVar1);
}

