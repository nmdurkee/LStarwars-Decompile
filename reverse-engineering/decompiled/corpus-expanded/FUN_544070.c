/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x544070; label: FUN_00544070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00544070(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,float *param_4,
                float *param_5,float param_6,undefined2 param_7,undefined4 param_8,
                undefined4 param_9,undefined4 param_10,undefined4 param_11,int param_12,
                undefined4 param_13,undefined4 param_14,undefined1 param_15,undefined4 param_16)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  undefined2 uVar11;
  char *pcVar12;
  undefined4 uVar13;
  int iVar14;
  undefined *puVar15;
  int iVar16;
  int iVar17;
  float *pfVar18;
  float10 fVar19;
  undefined2 *local_34;
  int local_30;
  
  if (0x18 < param_12) {
    FID_conflict__wprintf("to many sections/n");
  }
  DAT_029892c0 = 1;
  pcVar12 = &DAT_02983a60;
  iVar17 = 0;
  while (*pcVar12 != '\0') {
    iVar17 = iVar17 + 1;
    pcVar12 = pcVar12 + 0xb0c;
    if (7 < iVar17) {
      return -1;
    }
  }
  if (iVar17 == -1) {
    return -1;
  }
  iVar16 = iVar17 * 0xb0c;
  *(undefined4 *)(&DAT_029844ec + iVar16) = *param_2;
  *(undefined4 *)(iVar16 + 0x29844f0) = param_2[1];
  *(undefined4 *)(iVar16 + 0x29844f4) = param_2[2];
  *(undefined4 *)(&DAT_029844f8 + iVar16) = *param_3;
  *(undefined4 *)(iVar16 + 0x29844fc) = param_3[1];
  *(undefined4 *)(iVar16 + 0x2984500) = param_3[2];
  *(undefined4 *)(&DAT_02983a64 + iVar16) = param_1;
  (&DAT_02983a60)[iVar16] = 1;
  (&DAT_02983a62)[iVar17 * 0x586] = 0;
  uVar13 = FUN_0066cbc0();
  (&DAT_02984554)[iVar17 * 0x2c3] = param_8;
  (&DAT_02983a68)[iVar17 * 0x2c3] = uVar13;
  (&DAT_0298455c)[iVar17 * 0x2c3] = param_9;
  (&DAT_02984548)[iVar17 * 0x2c3] = param_16;
  (&DAT_02984550)[iVar17 * 0x2c3] = param_6;
  (&DAT_02984546)[iVar16] = (char)param_12;
  (&DAT_02984547)[iVar16] = param_15;
  (&DAT_02984558)[iVar17 * 0x2c3] = param_10;
  (&DAT_02984560)[iVar17 * 0x2c3] = param_11;
  (&DAT_02984564)[iVar17 * 0x2c3] = param_13;
  (&DAT_02984568)[iVar17 * 0x2c3] = param_14;
  (&DAT_02984504)[iVar17 * 0x2c3] = (*param_4 + *param_5) * 0.5;
  (&DAT_02984508)[iVar17 * 0x2c3] = (param_4[1] + param_5[1]) * 0.5;
  (&DAT_0298450c)[iVar17 * 0x2c3] = (param_4[2] + param_5[2]) * 0.5;
  fVar4 = *param_5 - *param_4;
  fVar1 = param_5[1];
  fVar2 = param_4[1];
  fVar5 = param_5[2] - param_4[2];
  fVar3 = (fVar1 - fVar2) * 0.5;
  (&DAT_02984544)[iVar16] = 0;
  (&DAT_02984510)[iVar17 * 0x2c3] =
       fVar4 * 0.5 * fVar4 * 0.5 + fVar3 * fVar3 + fVar5 * 0.5 * fVar5 * 0.5 + 1.0;
  fVar19 = (float10)FUN_005c0240(fVar5 * fVar5 + fVar4 * fVar4);
  (&DAT_0298454e)[iVar17 * 0x586] = param_7;
  local_30 = 0;
  if (0 < param_12) {
    local_34 = &DAT_02984514 + iVar17 * 0x586;
    fVar3 = param_6 * (float)((float10)1 / fVar19) * -fVar5 * 0.5;
    fVar7 = (float)(param_12 + -1);
    fVar6 = param_6 * (float)((float10)1 / fVar19) * fVar4 * 0.5;
    puVar15 = &DAT_02983eec + iVar16;
    pfVar18 = (float *)(&DAT_02983a70 + iVar17 * 0x2c3);
    do {
      iVar14 = FUN_005cfac0(&DAT_029844ec + iVar16);
      if (iVar14 == 0) {
        *local_34 = 0xffff;
      }
      else {
        uVar13 = FUN_005cffb0(&DAT_029844ec + iVar16);
        uVar11 = FUN_0067bf50(puVar15,uVar13);
        *local_34 = uVar11;
      }
      FUN_005b44e0(puVar15);
      FUN_005b5060(puVar15,(int)(short)(&DAT_0298454e)[iVar17 * 0x586]);
      fVar8 = (float)local_30;
      local_34 = local_34 + 1;
      local_30 = local_30 + 1;
      fVar10 = (fVar8 * fVar4) / fVar7;
      *(float *)(puVar15 + 0x30) = *param_4 + fVar10;
      fVar9 = (fVar8 * (fVar1 - fVar2)) / fVar7;
      *(float *)(puVar15 + 0x34) = param_4[1] + fVar9;
      fVar8 = (fVar5 * fVar8) / fVar7;
      *(float *)(puVar15 + 0x38) = param_4[2] + fVar8;
      pfVar18[-1] = (*param_4 + fVar10) - fVar3;
      *pfVar18 = param_4[1] + fVar9;
      pfVar18[1] = (param_4[2] + fVar8) - fVar6;
      pfVar18[2] = *param_4 + fVar10 + fVar3;
      pfVar18[3] = param_4[1] + fVar9;
      pfVar18[4] = fVar6 + param_4[2] + fVar8;
      pfVar18[0x8f] = 0.0;
      pfVar18[0x90] = 0.0;
      pfVar18[0x91] = 0.0;
      pfVar18[0x92] = 0.0;
      pfVar18[0x93] = 0.0;
      pfVar18[0x94] = 0.0;
      (&DAT_0298454c)[iVar17 * 0x586] = 0;
      puVar15 = puVar15 + 0x40;
      pfVar18 = pfVar18 + 6;
    } while (local_30 < param_12);
    return iVar17;
  }
  return iVar17;
}

