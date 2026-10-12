/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x40a2a0; label: FUN_0040a2a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0040a2a0(int param_1,float *param_2,float param_3)

{
  char cVar1;
  short sVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  float10 fVar12;
  float local_2c;
  undefined1 local_c [12];
  
  pfVar8 = param_2;
  fVar7 = param_3 * param_3;
  iVar10 = 0;
  local_2c = 1e+08;
  param_2 = (float *)0x0;
  fVar3 = *pfVar8 - param_3;
  fVar4 = pfVar8[2] - param_3;
  fVar5 = *pfVar8 + param_3;
  fVar6 = param_3 + pfVar8[2];
  iVar11 = DAT_0093d504;
  sVar9 = DAT_007f191c;
  if (0 < DAT_0093d500) {
    do {
      if ((((((iVar11 != param_1) && ((*(uint *)(iVar11 + 0x1fc) & 0x1000) != 0)) &&
            (*(char *)(iVar11 + 0x28b) == '\0')) &&
           ((iVar11 != DAT_0093d7f0 && (iVar11 != DAT_0093d7f4)))) &&
          ((cVar1 = *(char *)(iVar11 + 0x7b5),
           (*(uint *)(PTR_PTR_007fb0e4 + cVar1 * 0x10 + 8) & 0x8000) == 0 &&
           ((cVar1 != ';' && (cVar1 != '\x17')))))) &&
         (((cVar1 != 'A' && (cVar1 != '=')) &&
          (((((sVar2 = *(short *)(iVar11 + 0x1064), sVar2 == sVar9 || (sVar2 == DAT_007f1914)) ||
             (sVar2 == DAT_007f18f4)) || (sVar2 == DAT_007f18f8)) &&
           (((fVar3 <= *(float *)(iVar11 + 0x80) && (*(float *)(iVar11 + 0x80) <= fVar5)) &&
            ((fVar4 <= *(float *)(iVar11 + 0x88) && (*(float *)(iVar11 + 0x88) <= fVar6)))))))))) {
        fVar12 = (float10)FUN_005b3c50((float *)(iVar11 + 0x80),pfVar8,local_c);
        param_3 = (float)fVar12;
        if (*(short *)(iVar11 + 0x1064) == DAT_007f191c) {
          param_3 = param_3 * 0.8;
        }
        else if (*(short *)(iVar11 + 0x1064) == DAT_007f1914) {
          param_3 = param_3 * 0.9;
        }
        sVar9 = DAT_007f191c;
        if ((param_3 < fVar7) && (param_3 < local_2c)) {
          local_2c = param_3;
          iVar10 = iVar11;
        }
      }
      param_2 = (float *)((int)param_2 + 1);
      iVar11 = iVar11 + 0x10d8;
    } while ((int)param_2 < DAT_0093d500);
  }
  return iVar10;
}

