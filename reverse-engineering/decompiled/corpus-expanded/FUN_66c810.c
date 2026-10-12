/* Ghidra pseudocode, not original source.
 * ev_c3511c7e9be8c9ea3f86dbf498dc77cf8080442af45acd9c68d26e3bdf8b902d
 * Entry: 0x66c810; label: FUN_0066c810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066c810(undefined4 param_1,int *param_2)

{
  short *psVar1;
  short sVar2;
  int *piVar3;
  float fVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  float *pfVar8;
  undefined2 *puVar9;
  int iVar10;
  float10 fVar11;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  piVar3 = (int *)*param_2;
  *param_2 = (int)(piVar3 + 0x2924);
  *piVar3 = (int)(piVar3 + 0x2924);
  *param_2 = *param_2 + 0x700;
  piVar3[1] = *param_2;
  *param_2 = *param_2 + 0x1c00;
  _memset((void *)*piVar3,0,0x700);
  puVar5 = (undefined4 *)(*piVar3 + 0x2c);
  iVar7 = 0x20;
  do {
    *puVar5 = 0xffffffff;
    puVar5 = puVar5 + 0xe;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 0x20;
  piVar6 = piVar3 + 0x58;
  do {
    *piVar6 = 0;
    piVar6[-5] = 0;
    piVar6[1] = 0;
    iVar7 = iVar7 + -1;
    piVar6[2] = 0;
    piVar6[4] = 0;
    piVar6[3] = 0;
    piVar6 = piVar6 + 0x1b;
  } while (iVar7 != 0);
  piVar6 = piVar3 + 3;
  for (iVar7 = 0x40; iVar7 != 0; iVar7 = iVar7 + -1) {
    *piVar6 = -1;
    piVar6 = piVar6 + 1;
  }
  DAT_02961f50 = 0;
  _DAT_02961fe0 = 0;
  DAT_0292fc64 = 0;
  DAT_0292119c = 0;
  DAT_0292fbf0 = 0;
  DAT_02947d88 = 0;
  DAT_0292125e = 0;
  DAT_02961f74 = 0xffffffff;
  iVar7 = FUN_0066c670(param_1,param_2,piVar3);
  piVar3[2] = iVar7;
  piVar6 = (int *)(*piVar3 + 0x2c);
  iVar7 = 0x20;
  do {
    if ((*piVar6 == 0) || (*piVar6 == 1)) {
      pfVar8 = (float *)piVar6[-8];
      sVar2 = *(short *)pfVar8;
      param_2 = (int *)0x0;
      local_18 = 2e+08;
      local_14 = 2e+08;
      local_10 = 2e+08;
      local_c = -2e+08;
      local_8 = -2e+08;
      local_4 = -2e+08;
      while (-1 < sVar2) {
        psVar1 = (short *)((int)pfVar8 + 2);
        pfVar8 = pfVar8 + 5;
        for (iVar10 = (int)*psVar1; 0 < iVar10; iVar10 = iVar10 + -1) {
          if (*(char *)(pfVar8 + 0x18) == -1) {
            *(byte *)((int)pfVar8 + 0x62) = *(byte *)((int)pfVar8 + 0x62) | 0x80;
            *(undefined1 *)(pfVar8 + 0x18) = *(undefined1 *)((int)pfVar8 + 0x61);
            *(undefined1 *)((int)pfVar8 + 0x61) = 0;
          }
          if (*pfVar8 < local_18) {
            local_18 = *pfVar8;
          }
          if (pfVar8[2] < local_14) {
            local_14 = pfVar8[2];
          }
          if (pfVar8[4] < local_10) {
            local_10 = pfVar8[4];
          }
          if (local_c < pfVar8[1]) {
            local_c = pfVar8[1];
          }
          if (local_8 < pfVar8[3]) {
            local_8 = pfVar8[3];
          }
          if (local_4 < pfVar8[5]) {
            local_4 = pfVar8[5];
          }
          fVar4 = pfVar8[8] * pfVar8[8] + pfVar8[6] * pfVar8[6] + pfVar8[7] * pfVar8[7];
          if ((float)param_2 < fVar4) {
            param_2 = (int *)fVar4;
          }
          fVar4 = pfVar8[0xb] * pfVar8[0xb] + pfVar8[9] * pfVar8[9] + pfVar8[10] * pfVar8[10];
          if ((float)param_2 < fVar4) {
            param_2 = (int *)fVar4;
          }
          fVar4 = pfVar8[0xe] * pfVar8[0xe] + pfVar8[0xc] * pfVar8[0xc] + pfVar8[0xd] * pfVar8[0xd];
          if ((float)param_2 < fVar4) {
            param_2 = (int *)fVar4;
          }
          fVar4 = pfVar8[0x11] * pfVar8[0x11] +
                  pfVar8[0xf] * pfVar8[0xf] + pfVar8[0x10] * pfVar8[0x10];
          if ((float)param_2 < fVar4) {
            param_2 = (int *)fVar4;
          }
          pfVar8 = pfVar8 + 0x19;
        }
        sVar2 = *(short *)pfVar8;
      }
      fVar11 = (float10)FUN_005c0240(param_2);
      piVar6[2] = (int)(float)fVar11;
      _DAT_02961fe0 = _DAT_02961fe0 + 1;
      piVar6[-7] = (int)local_18;
      *piVar6 = 0;
      piVar6[-6] = (int)local_14;
      piVar6[-5] = (int)local_10;
      piVar6[-4] = (int)local_c;
      piVar6[-3] = (int)local_8;
      piVar6[-2] = (int)local_4;
    }
    piVar6 = piVar6 + 0xe;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar7 = 0;
  puVar9 = (undefined2 *)(*piVar3 + 0x30);
  piVar6 = piVar3 + 0x53;
  do {
    *puVar9 = (short)iVar7;
    *piVar6 = 0;
    iVar7 = iVar7 + 1;
    puVar9 = puVar9 + 0x1c;
    piVar6 = piVar6 + 0x1b;
  } while (iVar7 < 0x20);
  DAT_02924af4 = piVar3;
  return;
}

