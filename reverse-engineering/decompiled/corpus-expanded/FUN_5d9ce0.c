/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d9ce0; label: FUN_005d9ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_005d9ce0(float *param_1,int param_2,short param_3)

{
  float fVar1;
  int in_EAX;
  int iVar2;
  float *pfVar3;
  short in_DX;
  float *pfVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int local_10;
  int local_c;
  
  if (*(byte *)(*(int *)(in_EAX + 0x78) + 0x14 + in_DX * 0x18) <
      *(byte *)(*(int *)(in_EAX + 0x78) + 0x14 + param_3 * 0x18)) {
    fVar1 = param_1[2] * _DAT_0097189c + *param_1 * _DAT_00971894 + param_1[1] * _DAT_00971898 +
            param_1[3];
    if ((*(short *)(param_1 + 6) == in_DX) && (fVar1 < 0.0)) {
      return '\0';
    }
    if ((*(short *)((int)param_1 + 0x16) == in_DX) && (0.0 < fVar1)) {
      return '\0';
    }
  }
  iVar2 = (int)*(short *)(param_2 + 0x9c);
  _param_3 = 0;
  local_c = 0;
  if (0 < iVar2) {
    iVar6 = (int)*(short *)(param_1 + 5);
    local_10 = 0;
    do {
      iVar5 = 0;
      iVar8 = 0;
      if (3 < iVar6) {
        pfVar4 = (float *)(local_10 + *(int *)(param_2 + 0x80));
        pfVar3 = (float *)((int)param_1[4] + 8);
        iVar7 = (iVar6 - 4U >> 2) + 1;
        iVar8 = iVar7 * 4;
        do {
          if (pfVar4[2] * *pfVar3 + pfVar3[-1] * pfVar4[1] + pfVar3[-2] * *pfVar4 + pfVar4[3] < 0.0)
          {
            iVar5 = iVar5 + 1;
          }
          else {
            _param_3 = _param_3 + 1;
          }
          if (pfVar3[3] * pfVar4[2] + pfVar3[1] * *pfVar4 + pfVar3[2] * pfVar4[1] + pfVar4[3] < 0.0)
          {
            iVar5 = iVar5 + 1;
          }
          else {
            _param_3 = _param_3 + 1;
          }
          if (pfVar3[6] * pfVar4[2] + pfVar3[4] * *pfVar4 + pfVar3[5] * pfVar4[1] + pfVar4[3] < 0.0)
          {
            iVar5 = iVar5 + 1;
          }
          else {
            _param_3 = _param_3 + 1;
          }
          if (pfVar3[9] * pfVar4[2] + pfVar3[7] * *pfVar4 + pfVar3[8] * pfVar4[1] + pfVar4[3] < 0.0)
          {
            iVar5 = iVar5 + 1;
          }
          else {
            _param_3 = _param_3 + 1;
          }
          pfVar3 = pfVar3 + 0xc;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (iVar8 < iVar6) {
        pfVar3 = (float *)(*(int *)(param_2 + 0x80) + local_10);
        pfVar4 = (float *)((int)param_1[4] + iVar8 * 0xc);
        iVar8 = iVar6 - iVar8;
        do {
          if (pfVar4[2] * pfVar3[2] + *pfVar3 * *pfVar4 + pfVar4[1] * pfVar3[1] + pfVar3[3] < 0.0) {
            iVar5 = iVar5 + 1;
          }
          else {
            _param_3 = _param_3 + 1;
          }
          pfVar4 = pfVar4 + 3;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      if (iVar5 == iVar6) {
        return '\0';
      }
      local_10 = local_10 + 0x10;
      local_c = local_c + 1;
    } while (local_c < iVar2);
  }
  return (_param_3 != *(short *)(param_1 + 5) * iVar2) + '\x01';
}

