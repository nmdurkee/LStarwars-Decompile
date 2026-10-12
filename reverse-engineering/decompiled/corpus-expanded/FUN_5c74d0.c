/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c74d0; label: FUN_005c74d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c74d0(int param_1,float *param_2,undefined4 param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  int *local_7c;
  float local_64;
  float local_54;
  
  iVar10 = 0;
  local_7c = &DAT_00806c04;
  do {
    pfVar8 = (float *)(local_7c[-1] * 0x10 + param_1);
    pfVar9 = (float *)(*local_7c * 0x10 + param_1);
    fVar7 = pfVar8[2] * param_4[2] +
            pfVar8[1] * param_4[1] + *(float *)(local_7c[-1] * 0x10 + param_1) * *param_4 +
            param_4[3];
    fVar1 = param_4[2] * pfVar9[2] + *param_4 * *pfVar9 + pfVar9[1] * param_4[1] + param_4[3];
    if (fVar7 <= 0.0) {
      if (0.0 < fVar1) {
        *param_2 = *pfVar9;
        param_2[1] = pfVar9[1];
        iVar10 = iVar10 + 2;
        param_2[2] = pfVar9[2];
        param_2[3] = pfVar9[3];
        fVar6 = -fVar7 / (fVar1 - fVar7);
        fVar7 = pfVar9[1];
        fVar1 = pfVar8[1];
        fVar2 = pfVar9[2];
        fVar3 = pfVar8[2];
        fVar4 = pfVar8[1];
        fVar5 = pfVar8[2];
        param_2[4] = *pfVar8 + fVar6 * (*pfVar9 - *pfVar8);
        param_2[5] = (fVar7 - fVar1) * fVar6 + fVar4;
        param_2[6] = fVar5 + fVar6 * (fVar2 - fVar3);
        param_2[7] = local_54;
        param_2 = param_2 + 8;
      }
    }
    else {
      *param_2 = *pfVar8;
      param_2[1] = pfVar8[1];
      iVar10 = iVar10 + 2;
      param_2[2] = pfVar8[2];
      param_2[3] = pfVar8[3];
      if (fVar1 <= 0.0) {
        fVar7 = fVar7 / (fVar7 - fVar1);
        fVar1 = pfVar9[1];
        fVar2 = pfVar8[1];
        fVar3 = pfVar9[2];
        fVar4 = pfVar8[2];
        fVar5 = pfVar8[1];
        fVar6 = pfVar8[2];
        param_2[4] = *pfVar8 + fVar7 * (*pfVar9 - *pfVar8);
        param_2[5] = (fVar1 - fVar2) * fVar7 + fVar5;
        param_2[6] = fVar6 + fVar7 * (fVar3 - fVar4);
        param_2[7] = local_64;
        param_2 = param_2 + 8;
      }
      else {
        param_2[4] = *pfVar9;
        param_2[5] = pfVar9[1];
        param_2[6] = pfVar9[2];
        param_2[7] = pfVar9[3];
        param_2 = param_2 + 8;
      }
    }
    local_7c = local_7c + 2;
  } while ((int)local_7c < 0x806c64);
  return iVar10;
}

