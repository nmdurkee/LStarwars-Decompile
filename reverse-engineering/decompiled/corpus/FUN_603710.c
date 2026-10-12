/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x603710; label: FUN_00603710
 */

void FUN_00603710(uint *param_1,int param_2,int param_3,float *param_4,uint *param_5)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int *piVar4;
  uint *puVar5;
  float *pfVar6;
  uint uVar7;
  int iVar8;
  float fVar9;
  byte *pbVar10;
  float *pfVar11;
  float *pfVar12;
  undefined4 *puVar13;
  float *pfVar14;
  undefined4 *puVar15;
  float local_8;
  
  pfVar6 = param_4;
  puVar5 = param_1;
  if ((param_3 == 0) || (param_4[10] == 0.0)) {
    param_4[0xd] = 0.0;
    *param_5 = (uint)param_4;
  }
  else {
    *param_5 = *param_1 + 0x1f & 0xffffffe0;
    *param_1 = (*param_1 + 0x1f & 0xffffffe0) + 0x38;
    pfVar12 = (float *)*param_5;
    pfVar11 = param_4;
    pfVar14 = pfVar12;
    for (iVar8 = 0xe; iVar8 != 0; iVar8 = iVar8 + -1) {
      *pfVar14 = *pfVar11;
      pfVar11 = pfVar11 + 1;
      pfVar14 = pfVar14 + 1;
    }
    pfVar11 = param_4 + 2;
    param_1 = (uint *)0x0;
    pfVar14 = param_4 + 9;
    pfVar1 = param_4 + 6;
    pfVar2 = param_4 + 5;
    param_4 = pfVar12;
    FUN_006e5b90((int)*pfVar2 * (uint)*(ushort *)pfVar11,(int)*pfVar1 * (uint)*(ushort *)pfVar11,
                 &param_1,0x10,*pfVar14);
    param_4[0xd] = (float)(*puVar5 + 0x1f & 0xffffffe0);
    uVar7 = *puVar5 + 0x1f & 0xffffffe0;
    *puVar5 = uVar7;
    *puVar5 = (uint)*(ushort *)(pfVar6 + 2) * (int)pfVar6[6] + uVar7;
    pfVar12 = (float *)param_4[0xd];
    FUN_004ef660(pfVar12,param_1,(uint)*(ushort *)(pfVar6 + 2) * (int)pfVar6[6]);
    iVar8 = 0;
    local_8 = 0.0;
    if (pfVar6[6] != 0.0) {
      do {
        fVar9 = 0.0;
        if (pfVar6[10] != 0.0) {
          param_4 = (float *)(param_3 + 8);
          do {
            fVar3 = *param_4;
            if ((*(int *)((int)pfVar6[0xb] + (int)fVar9 * 4) != 0) && (fVar3 != 0.0)) {
              *pfVar12 = *(float *)(*(int *)((int)pfVar6[0xb] + (int)fVar9 * 4) + iVar8) * fVar3 +
                         *pfVar12;
              pfVar12[1] = *(float *)(*(int *)((int)pfVar6[0xb] + (int)fVar9 * 4) + 4 + iVar8) *
                           fVar3 + pfVar12[1];
              pfVar12[2] = fVar3 * *(float *)(*(int *)((int)pfVar6[0xb] + (int)fVar9 * 4) + 8 +
                                             iVar8) + pfVar12[2];
            }
            param_4 = param_4 + 1;
            fVar9 = (float)((int)fVar9 + 1);
          } while (fVar9 != pfVar6[10]);
        }
        param_1 = (uint *)((int)param_1 + (uint)*(ushort *)(pfVar6 + 2));
        pfVar12 = (float *)((int)pfVar12 + (uint)*(ushort *)(pfVar6 + 2));
        local_8 = (float)((int)local_8 + 1);
        iVar8 = iVar8 + 0xc;
      } while (local_8 != pfVar6[6]);
    }
    FUN_006e5bc0(pfVar6[9]);
  }
  piVar4 = (int *)*puVar5;
  *puVar5 = (uint)(piVar4 + 1);
  pbVar10 = (byte *)((int)pfVar6 + 10);
  *piVar4 = 0;
  if (*pbVar10 != 0xff) {
    do {
      if (7 < (int)(pbVar10 + (-10 - (int)pfVar6))) {
        return;
      }
      puVar13 = (undefined4 *)((uint)*pbVar10 * 0x40 + param_2);
      puVar15 = (undefined4 *)*puVar5;
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar15 = *puVar13;
        puVar13 = puVar13 + 1;
        puVar15 = puVar15 + 1;
      }
      *puVar5 = *puVar5 + 0x40;
      *piVar4 = *piVar4 + 1;
      pbVar10 = pbVar10 + 1;
    } while (*pbVar10 != 0xff);
  }
  return;
}

