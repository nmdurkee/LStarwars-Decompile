/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53f0e0; label: FUN_0053f0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053f0e0(int *param_1,undefined4 *param_2,float param_3,undefined4 *param_4)

{
  char *pcVar1;
  float *pfVar2;
  float fVar3;
  short sVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  undefined4 *puVar9;
  float *pfVar10;
  int iVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  
  puVar5 = param_4;
  puVar9 = param_4;
  for (iVar7 = 0xe; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *param_2;
    param_2 = param_2 + 1;
    puVar9 = puVar9 + 1;
  }
  if (((param_1 == (int *)0x0) || (pcVar1 = (char *)((int)param_4 + 1), *pcVar1 == -1)) ||
     (param_3 == 0.0)) {
    return;
  }
  if (param_3 <= 0.0) {
    param_3 = -param_3;
    param_4 = (undefined4 *)0x2;
  }
  else {
    param_4 = (undefined4 *)0x1;
  }
  iVar7 = *pcVar1 * 0x13c + *param_1;
  uVar6 = (uint)*(ushort *)(iVar7 + 0x30);
  pfVar2 = (float *)(puVar5 + 2);
  if (*(char *)(iVar7 + 0x33) != '\0') {
    uVar6 = uVar6 + 1;
  }
  while( true ) {
    sVar4 = *(short *)((int)puVar5 + 2);
    *(short *)(puVar5 + 10) = sVar4 + 1;
    if (((int)(short)(sVar4 + 1) == uVar6) && (*(char *)(iVar7 + 0x33) != '\0')) {
      *(undefined2 *)(puVar5 + 10) = 0;
    }
    if (*(int *)(iVar7 + 0x14) == 0) {
      iVar11 = *(int *)(iVar7 + 0x34) + sVar4 * 0x80;
      pfVar8 = (float *)(iVar11 + 0x60);
      pfVar10 = (float *)(iVar11 + 0x6c);
    }
    else {
      iVar11 = *(int *)(*(int *)(iVar7 + 0x14) + 8);
      pfVar8 = (float *)(iVar11 + sVar4 * 0xc);
      pfVar10 = (float *)(iVar11 + *(short *)(puVar5 + 10) * 0xc);
    }
    if (param_4 != (undefined4 *)0x1) {
      pfVar10 = pfVar8;
    }
    fVar12 = (float10)FUN_005becc0(pfVar2,pfVar10,0);
    fVar13 = (float10)param_3;
    fVar14 = (float10)(float)fVar12;
    fVar12 = (float10)0;
    if (fVar13 <= fVar14) break;
    *pfVar2 = *pfVar10;
    puVar5[3] = pfVar10[1];
    puVar5[4] = pfVar10[2];
    puVar5[1] = (float)fVar12;
    param_3 = (float)(fVar13 - fVar14);
    if (param_4 == (undefined4 *)0x1) {
      if (*(char *)(iVar7 + 0x33) == '\0') {
        if ((int)uVar6 <= (int)*(short *)((int)puVar5 + 2)) goto LAB_0053f345;
        *(short *)((int)puVar5 + 2) = *(short *)((int)puVar5 + 2) + 1;
      }
      else {
        *(short *)((int)puVar5 + 2) = *(short *)((int)puVar5 + 2) + 1;
        if ((int)*(short *)((int)puVar5 + 2) == uVar6) {
          *(undefined2 *)((int)puVar5 + 2) = 0;
        }
      }
    }
    else if (*(char *)(iVar7 + 0x33) == '\0') {
      if (*(short *)((int)puVar5 + 2) < 1) goto LAB_0053f345;
      *(short *)((int)puVar5 + 2) = *(short *)((int)puVar5 + 2) + -1;
    }
    else {
      *(short *)((int)puVar5 + 2) = *(short *)((int)puVar5 + 2) + -1;
      if (*(short *)((int)puVar5 + 2) == -1) {
        *(undefined2 *)((int)puVar5 + 2) = *(undefined2 *)(iVar7 + 0x30);
      }
    }
  }
  if ((fVar12 < fVar14) && (fVar12 < fVar13)) {
    fVar3 = (float)(fVar13 / fVar14);
    *pfVar2 = *pfVar2 + fVar3 * (*pfVar10 - *pfVar2);
    puVar5[3] = (pfVar10[1] - (float)puVar5[3]) * fVar3 + (float)puVar5[3];
    puVar5[4] = (pfVar10[2] - (float)puVar5[4]) * fVar3 + (float)puVar5[4];
    if (*(int *)(iVar7 + 0x14) == 0) {
      iVar11 = *(short *)((int)puVar5 + 2) * 0x80 + *(int *)(iVar7 + 0x34);
      iVar7 = iVar11 + 0x60;
      iVar11 = iVar11 + 0x6c;
    }
    else {
      iVar11 = *(int *)(*(int *)(iVar7 + 0x14) + 8);
      iVar7 = iVar11 + *(short *)((int)puVar5 + 2) * 0xc;
      iVar11 = iVar11 + *(short *)(puVar5 + 10) * 0xc;
    }
    fVar13 = (float10)FUN_005becc0(iVar7,pfVar2,0);
    fVar12 = (float10)FUN_005becc0(iVar7,iVar11,0);
    fVar12 = (float10)(double)fVar13 / fVar12;
  }
  puVar5[1] = (float)fVar12;
LAB_0053f345:
  FUN_0053e900();
  puVar5[5] = DAT_009242e0;
  puVar5[6] = DAT_009242e4;
  puVar5[7] = DAT_009242e8;
  return;
}

