/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x642570; label: FUN_00642570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00642570(int param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  
  *(float *)(param_1 + 0xf4) = param_2;
  *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) & 0xfffffffb;
  local_4c = param_2 * *(float *)(param_1 + 0x80);
  fVar2 = *(float *)(param_1 + 0xe8) * 0.5;
  local_48 = *(float *)(param_1 + 0x84) * param_2 + param_2 * param_2 * fVar2;
  local_44 = *(float *)(param_1 + 0x88) * param_2;
  if ((0.0 < *(float *)(param_1 + 0x84)) && (local_48 <= 0.0)) {
    param_2 = -*(float *)(param_1 + 0x84) / *(float *)(param_1 + 0xe8);
    *(float *)(param_1 + 0xf4) = param_2;
    local_4c = param_2 * *(float *)(param_1 + 0x80);
    local_48 = *(float *)(param_1 + 0x84) * param_2 + param_2 * param_2 * fVar2;
    local_44 = param_2 * *(float *)(param_1 + 0x88);
  }
  fVar6 = (float10)FUN_005b3b00();
  fVar2 = (float)fVar6;
  if ((((0.001 <= fVar2) && (fVar2 <= 10000.0)) && (iVar4 = FUN_006eaa47((double)fVar2), iVar4 != 0)
      ) && (iVar4 = __isnan((double)fVar2), iVar4 == 0)) {
    if (((byte)*(undefined4 *)(param_1 + 0x144) & 0x60) == 0x20) {
      fVar2 = ((*(float *)(param_1 + 0xf8) + param_2) / _DAT_008102e4) * *(float *)(param_1 + 0xdc);
      if (*(float *)(param_1 + 0xdc) < fVar2) {
        fVar2 = *(float *)(param_1 + 0xdc);
      }
      local_58 = local_4c;
      pfVar1 = (float *)(param_1 + 0x30);
      local_54 = local_48;
      local_50 = local_44;
      iVar4 = FUN_00642530(pfVar1,&local_58,fVar2,0);
      if (iVar4 == 0) goto LAB_00642a7c;
      uVar3 = FUN_0067b210();
      *(undefined1 *)(param_1 + 0x209) = uVar3;
      fVar6 = (float10)FUN_0067b200();
      if ((((float10)0.0 < fVar6) || (0.5 < DAT_0291f680)) &&
         (((*(uint *)(param_1 + 0x108) & 0x10000000) == 0 || (iVar5 = FUN_0067b270(), iVar5 != 4))))
      goto LAB_006429ed;
      if (0x10 < iVar4) {
        fVar2 = *pfVar1;
        fVar6 = (float10)FUN_0067b260();
        *pfVar1 = (float)((float10)fVar2 -
                         fVar6 * (float10)DAT_0291f67c * (float10)1.0499999523162842);
        fVar2 = *(float *)(param_1 + 0x34);
        fVar6 = (float10)FUN_0067b260();
        *(float *)(param_1 + 0x34) =
             (float)((float10)fVar2 - fVar6 * (float10)DAT_0291f680 * (float10)1.0499999523162842);
        fVar2 = *(float *)(param_1 + 0x38);
        fVar6 = (float10)FUN_0067b260();
        *(float *)(param_1 + 0x38) =
             (float)((float10)fVar2 - fVar6 * (float10)DAT_0291f684 * (float10)1.0499999523162842);
      }
    }
    *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) & 0xffffff9f;
    local_58 = local_4c;
    pfVar1 = (float *)(param_1 + 0x30);
    local_54 = local_48;
    local_50 = local_44;
    iVar4 = FUN_00642530(pfVar1,&local_58,*(undefined4 *)(param_1 + 0xe0),0);
    if (iVar4 != 0) {
      uVar3 = FUN_0067b210();
      *(undefined1 *)(param_1 + 0x209) = uVar3;
      fVar6 = (float10)FUN_0067b200();
      if ((((float10)0.0 < fVar6) || (0.5 < DAT_0291f680)) &&
         (((*(uint *)(param_1 + 0x108) & 0x10000000) == 0 || (iVar5 = FUN_0067b270(), iVar5 != 4))))
      {
LAB_006429ed:
        *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 4;
        iVar4 = FUN_0067fb40();
        *(int *)(param_1 + 0x200) = iVar4;
        *(uint *)(param_1 + 0x144) =
             *(uint *)(param_1 + 0x144) ^
             ((uint)(iVar4 != -1) << 4 ^ *(uint *)(param_1 + 0x144)) & 0x10;
        fVar6 = (float10)FUN_0067b200();
        *(float *)(param_1 + 0xf4) = (float)(fVar6 * (float10)*(float *)(param_1 + 0xf4));
        *(float *)(param_1 + 0xa4) = *(float *)(param_1 + 0x30) + local_58;
        *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0x34) + local_54;
        *(float *)(param_1 + 0xac) = *(float *)(param_1 + 0x38) + local_50;
        *(float *)(param_1 + 0xb0) = DAT_0291f67c;
        *(float *)(param_1 + 0xb4) = DAT_0291f680;
        *(float *)(param_1 + 0xb8) = DAT_0291f684;
        return;
      }
      if (0x10 < iVar4) {
        fVar2 = *pfVar1;
        fVar6 = (float10)FUN_0067b260();
        *pfVar1 = (float)((float10)fVar2 -
                         fVar6 * (float10)DAT_0291f67c * (float10)1.0499999523162842);
        fVar2 = *(float *)(param_1 + 0x34);
        fVar6 = (float10)FUN_0067b260();
        *(float *)(param_1 + 0x34) =
             (float)((float10)fVar2 - fVar6 * (float10)DAT_0291f680 * (float10)1.0499999523162842);
        fVar2 = *(float *)(param_1 + 0x38);
        fVar6 = (float10)FUN_0067b260();
        *(float *)(param_1 + 0x38) =
             (float)((float10)fVar2 - fVar6 * (float10)DAT_0291f684 * (float10)1.0499999523162842);
      }
      fVar2 = ((*(float *)(param_1 + 0xf8) - param_2) / _DAT_008102e4) * *(float *)(param_1 + 0xdc);
      if (0.0 < fVar2) {
        local_58 = local_4c;
        *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) & 0xffffffdf | 0x40;
        local_54 = local_48;
        local_50 = local_44;
        iVar4 = FUN_00642530(pfVar1,&local_58,fVar2,0);
        if (iVar4 == 0) goto LAB_00642a7c;
        uVar3 = FUN_0067b210();
        *(undefined1 *)(param_1 + 0x209) = uVar3;
        if (((*(uint *)(param_1 + 0x108) & 0x10000000) == 0) || (iVar4 = FUN_0067b270(), iVar4 != 4)
           ) {
          *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 4;
          iVar4 = FUN_0067fb40();
          *(int *)(param_1 + 0x200) = iVar4;
          *(uint *)(param_1 + 0x144) =
               *(uint *)(param_1 + 0x144) ^
               ((uint)(iVar4 != -1) << 4 ^ *(uint *)(param_1 + 0x144)) & 0x10;
          fVar6 = (float10)FUN_0067b200();
          *(float *)(param_1 + 0xf4) = (float)(fVar6 * (float10)*(float *)(param_1 + 0xf4));
          *(float *)(param_1 + 0xa4) = *pfVar1 + local_58;
          *(float *)(param_1 + 0xa8) = *(float *)(param_1 + 0x34) + local_54;
          *(float *)(param_1 + 0xac) = *(float *)(param_1 + 0x38) + local_50;
          *(float *)(param_1 + 0xb0) = DAT_0291f67c;
          *(float *)(param_1 + 0xb4) = DAT_0291f680;
          *(float *)(param_1 + 0xb8) = DAT_0291f684;
          return;
        }
      }
      return;
    }
  }
LAB_00642a7c:
  *(undefined1 *)(param_1 + 0x209) = 0xff;
  return;
}

