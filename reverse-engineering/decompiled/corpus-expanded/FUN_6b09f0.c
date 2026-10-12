/* Ghidra pseudocode, not original source.
 * ev_0b75f810defb69f43ff4ee181673bf6e816c7d4f879f3f967a03f199d8168922
 * Entry: 0x6b09f0; label: FUN_006b09f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b09f0(int *param_1,int param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  float *pfVar6;
  float10 fVar7;
  void *local_1c;
  int local_18;
  
  iVar5 = *(int *)(param_2 + 0x1c);
  iVar3 = *(int *)(param_2 + 4);
  param_1[1] = 0x80;
  param_1[2] = 0x40;
  param_1[3] = *(int *)(iVar5 + 0xb74);
  *param_1 = iVar3;
  param_1[0x29] = 0x80;
  param_1[0x2c] = *(int *)(iVar5 + 4) / 2;
  pvVar4 = _calloc(0x80,4);
  param_1[9] = (int)pvVar4;
  FUN_006af2a0(param_1 + 4,0x80);
  iVar5 = 0;
  do {
    fVar7 = (float10)FUN_006e8e80();
    *(float *)(param_1[9] + iVar5 * 4) = (float)fVar7;
    fVar2 = *(float *)(param_1[9] + iVar5 * 4);
    iVar1 = iVar5 * 4;
    iVar5 = iVar5 + 1;
    *(float *)(param_1[9] + iVar1) = fVar2 * fVar2;
  } while (iVar5 < 0x80);
  param_1[0xb] = 4;
  param_1[0xe] = 4;
  param_1[0x12] = 6;
  param_1[0x13] = 6;
  param_1[10] = 2;
  param_1[0xf] = 5;
  param_1[0x16] = 9;
  param_1[0x17] = 8;
  param_1[0x1a] = 0xd;
  param_1[0x1b] = 8;
  param_1[0x1e] = 0x11;
  param_1[0x1f] = 8;
  param_1[0x22] = 0x16;
  param_1[0x23] = 8;
  local_18 = 7;
  pfVar6 = (float *)(param_1 + 0xd);
  do {
    fVar2 = pfVar6[-2];
    local_1c = _malloc((int)fVar2 * 4);
    iVar5 = 0;
    pfVar6[-1] = (float)local_1c;
    if (0 < (int)fVar2) {
      do {
        fVar7 = (float10)FUN_006e8e80();
        *(float *)((int)local_1c + iVar5 * 4) = (float)fVar7;
        local_1c = (void *)pfVar6[-1];
        iVar1 = iVar5 * 4;
        iVar5 = iVar5 + 1;
        *pfVar6 = *(float *)((int)local_1c + iVar1) + *pfVar6;
      } while (iVar5 < (int)fVar2);
    }
    local_18 = local_18 + -1;
    *pfVar6 = 1.0 / *pfVar6;
    pfVar6 = pfVar6 + 4;
  } while (local_18 != 0);
  pvVar4 = _calloc(iVar3 * 7,0x90);
  param_1[0x26] = (int)pvVar4;
  pvVar4 = _calloc(param_1[0x29],4);
  param_1[0x28] = (int)pvVar4;
  return;
}

