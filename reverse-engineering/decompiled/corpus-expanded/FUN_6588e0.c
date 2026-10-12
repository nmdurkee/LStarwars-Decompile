/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x6588e0; label: FUN_006588e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006588e0(float param_1,float *param_2,float param_3,float param_4,byte param_5)

{
  float fVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  int iVar6;
  float local_10;
  float local_c;
  
  iVar6 = (int)param_1 * 0x330;
  sVar2 = *(short *)(iVar6 + 0x182 + DAT_029620a4);
  if ((((sVar2 != 0) && (sVar2 != -1)) && (iVar3 = *(int *)(DAT_0296209c + sVar2 * 4), iVar3 != 0))
     && (((*(byte *)(iVar3 + 0x2f2) & param_5) != 0 && (*(float *)(iVar3 + 0x30c) != 0.0)))) {
    param_1 = 0.0;
    local_10 = 0.0;
    local_c = 0.0;
    if (_DAT_0296205c <= *(float *)(iVar6 + 0x1e0 + DAT_029620a4)) {
      fVar1 = *(float *)(iVar6 + 0x1dc + DAT_029620a4);
    }
    else {
      fVar1 = *(float *)(iVar6 + 0x1e0 + DAT_029620a4);
    }
    fVar1 = _DAT_0296205c - fVar1;
    if ((0.0 < fVar1) && (fVar1 < *(float *)(iVar3 + 0x30c))) {
      fVar1 = fVar1 / *(float *)(iVar3 + 0x30c);
      iVar4 = 0;
      pfVar5 = (float *)(iVar3 + 0x318);
      do {
        if ((pfVar5[-2] < fVar1 != (pfVar5[-2] == fVar1)) && (fVar1 <= *pfVar5)) {
          pfVar5 = (float *)(iVar3 + 0x314 + iVar4 * 8);
          param_1 = (*(float *)(iVar3 + 0x31c + iVar4 * 8) - *pfVar5) *
                    ((fVar1 - *(float *)(iVar3 + 0x310 + iVar4 * 8)) /
                    (*(float *)(iVar3 + 0x318 + iVar4 * 8) - *(float *)(iVar3 + 0x310 + iVar4 * 8)))
                    + *pfVar5;
          break;
        }
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 7);
      iVar4 = 0;
      pfVar5 = (float *)(iVar3 + 0x358);
      do {
        if ((pfVar5[-2] < fVar1 != (pfVar5[-2] == fVar1)) && (fVar1 <= *pfVar5)) {
          pfVar5 = (float *)(iVar3 + 0x354 + iVar4 * 8);
          local_10 = (*(float *)(iVar3 + 0x35c + iVar4 * 8) - *pfVar5) *
                     ((fVar1 - *(float *)(iVar3 + 0x350 + iVar4 * 8)) /
                     (*(float *)(iVar3 + 0x358 + iVar4 * 8) - *(float *)(iVar3 + 0x350 + iVar4 * 8))
                     ) + *pfVar5;
          break;
        }
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 7);
      iVar4 = 0;
      pfVar5 = (float *)(iVar3 + 0x398);
      do {
        if ((pfVar5[-2] < fVar1 != (pfVar5[-2] == fVar1)) && (fVar1 <= *pfVar5)) {
          pfVar5 = (float *)(iVar3 + 0x394 + iVar4 * 8);
          local_c = (*(float *)(iVar3 + 0x39c + iVar4 * 8) - *pfVar5) *
                    ((fVar1 - *(float *)(iVar3 + 0x390 + iVar4 * 8)) /
                    (*(float *)(iVar3 + 0x398 + iVar4 * 8) - *(float *)(iVar3 + 0x390 + iVar4 * 8)))
                    + *pfVar5;
          break;
        }
        iVar4 = iVar4 + 1;
        pfVar5 = pfVar5 + 2;
      } while (iVar4 < 7);
      fVar1 = *(float *)(iVar3 + 0x304);
      local_10 = local_10 * *(float *)(iVar3 + 0x308);
      local_c = local_c * *(float *)(iVar3 + 0x308);
      _DAT_02947b48 = *param_2 - *(float *)(iVar6 + 400 + DAT_029620a4);
      _DAT_02947b4c = 0.0;
      _DAT_02947b50 = param_2[2] - *(float *)(iVar6 + 0x198 + DAT_029620a4);
      FUN_005b3b30(&DAT_02947b48,&DAT_02947b48);
      FUN_005b3830(&DAT_02947b48,&DAT_02947b48,fVar1 * param_1);
      _DAT_02947b48 = *(float *)(iVar6 + 400 + DAT_029620a4) + _DAT_02947b48;
      _DAT_02947b4c = *(float *)(iVar6 + 0x194 + DAT_029620a4) + _DAT_02947b4c;
      _DAT_02947b50 = *(float *)(iVar6 + 0x198 + DAT_029620a4) + _DAT_02947b50;
      param_1 = param_2[1] - _DAT_02947b4c;
      if ((param_4 != 1.0) || (local_c != local_10)) {
        param_1 = param_1 * ((local_10 + param_3) / (param_3 * param_4 + local_c));
      }
      if ((*param_2 - _DAT_02947b48) * (*param_2 - _DAT_02947b48) + param_1 * param_1 +
          (param_2[2] - _DAT_02947b50) * (param_2[2] - _DAT_02947b50) <
          (local_10 + param_3) * (local_10 + param_3)) {
        return 1;
      }
    }
  }
  return 0;
}

