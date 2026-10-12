/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x545860; label: FUN_00545860
 */

undefined2 *
FUN_00545860(undefined4 *param_1,float param_2,short param_3,float param_4,float param_5,
            undefined2 param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 uVar7;
  float *pfVar8;
  undefined2 *puVar9;
  int iVar10;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar4 = (int)param_2;
  puVar5 = (undefined2 *)FUN_00545620();
  iVar10 = (int)param_3;
  iVar6 = DAT_02983a50 + iVar10;
  if (iVar6 < DAT_00924834) {
    puVar9 = (undefined2 *)(DAT_0092483c + (iVar6 - iVar10) * 2);
    DAT_02983a50 = iVar6;
  }
  else {
    puVar9 = (undefined2 *)0x0;
  }
  if (((puVar5 != (undefined2 *)0x0) && (param_2 != 0.0)) && (puVar9 != (undefined2 *)0x0)) {
    *(float *)(puVar5 + 10) = param_2;
    *(undefined2 **)(puVar5 + 0xc) = puVar9;
    *(undefined4 *)(puVar5 + 2) = *param_1;
    *(undefined4 *)(puVar5 + 4) = param_1[2];
    puVar5[8] = *(undefined2 *)(param_1[2] + 0xc0);
    uVar7 = FUN_0066cbc0();
    *(float *)(puVar5 + 0x18) = param_4;
    *(float *)(puVar5 + 0x1a) = param_5;
    *(undefined4 *)(puVar5 + 6) = uVar7;
    puVar5[0x15] = param_3;
    puVar5[1] = param_6;
    *(float *)(puVar5 + 0x1c) = param_5 * param_5;
    *(float *)(puVar5 + 0x1e) = param_5 - param_4;
    local_4 = 1e+07;
    local_8 = 1e+07;
    local_10 = 1e+07;
    _param_3 = -1e+07;
    local_c = -1e+07;
    param_2 = -1e+07;
    if (0 < iVar10) {
      pfVar8 = (float *)(iVar4 + 0x34);
      do {
        *puVar9 = 0xffff;
        if (pfVar8[-1] < local_10) {
          local_10 = pfVar8[-1];
        }
        if (*pfVar8 < local_8) {
          local_8 = *pfVar8;
        }
        if (pfVar8[1] < local_4) {
          local_4 = pfVar8[1];
        }
        if (param_2 < pfVar8[-1]) {
          param_2 = pfVar8[-1];
        }
        if ((local_c < *pfVar8) && (*pfVar8 < 2e+06)) {
          local_c = *pfVar8;
        }
        if (_param_3 < pfVar8[1]) {
          _param_3 = pfVar8[1];
        }
        pfVar8 = pfVar8 + 0x10;
        puVar9 = puVar9 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    *(float *)(puVar5 + 0xe) = (local_10 + param_2) * 0.5;
    *(float *)(puVar5 + 0x10) = (local_8 + local_c) * 0.5;
    *(float *)(puVar5 + 0x12) = (local_4 + _param_3) * 0.5;
    fVar3 = (local_c - local_8) * 0.5;
    fVar1 = (param_2 - local_10) * 0.5;
    fVar2 = (_param_3 - local_4) * 0.5;
    fVar1 = fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3 + 1.0;
    *(float *)(puVar5 + 0x16) = fVar1;
    *(float *)(puVar5 + 0x1c) = fVar1 + *(float *)(puVar5 + 0x1c);
    return puVar5;
  }
  *puVar5 = 0;
  return (undefined2 *)0x0;
}

