/* Ghidra pseudocode, not original source.
 * ev_5fa8a0c629ff9dcf3dc3d25725019308ff1f1a9e08c812d6ee08209fa3308603
 * Entry: 0x654270; label: FUN_00654270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float * FUN_00654270(int param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  float10 fVar13;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float local_c [3];
  
  iVar3 = param_1;
  if (*(short *)(param_1 + 0x186) <= *(short *)(param_1 + 0x18a)) {
    *(undefined2 *)(param_1 + 0x18a) = 0;
  }
  if (*(char *)(param_2 + 0x2e) != '\a') {
    uVar8 = (uint)*(short *)(param_1 + 0x18a);
    uVar9 = uVar8 & 0x8000001f;
    if ((int)uVar9 < 0) {
      uVar9 = (uVar9 - 1 | 0xffffffe0) + 1;
    }
    pfVar10 = (float *)((uVar9 + 1) * 0x20 +
                       *(int *)(param_1 + 0x100 +
                               ((int)(uVar8 + ((int)uVar8 >> 0x1f & 0x1fU)) >> 5) * 4));
    *(short *)(param_1 + 0x18a) = *(short *)(param_1 + 0x18a) + 1;
    pfVar10[3] = param_3;
    *(float *)(param_1 + 0x324) = param_3;
    pfVar10[7] = 64.0 / *(float *)(param_2 + 0xa4);
    FUN_005b3830(local_c,param_2 + 100,param_3 - *(float *)(param_1 + 0x1e0));
    FUN_005b37d0(local_c,local_c,param_2 + 0x58);
    FUN_005b9d90(&DAT_00810900);
    FUN_006e6b90();
    iVar5 = FUN_006e6b90();
    fVar1 = (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff];
    iVar5 = FUN_006e6b90();
    fVar2 = (float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff];
    fVar13 = (float10)FUN_005b9d90(&DAT_00810900);
    sVar4 = FUN_0064fe20((float)(fVar13 * ((float10)fVar2 - (float10)fVar1) + (float10)fVar1));
    iVar5 = FUN_006e6b90();
    iVar6 = FUN_006e6b90();
    fStack_18 = local_c[0];
    fStack_10 = 0.0;
    fStack_14 = 0.0;
    FUN_005b3690(&fStack_18,&fStack_18,(int)sVar4);
    FUN_005b3620(&fStack_18,&fStack_18,iVar6 - iVar5);
    FUN_005c11d0(&fStack_18,&fStack_18,param_1 + 0x80);
    *pfVar10 = fStack_18;
    pfVar10[1] = fStack_14;
    pfVar10[2] = fStack_10;
    fVar13 = (float10)FUN_005b9d90(&DAT_00810900);
    fStack_18 = (float)(((fVar13 + fVar13) * (float10)*(float *)(param_2 + 0x4c) -
                        (float10)*(float *)(param_2 + 0x4c)) + (float10)*(float *)(param_2 + 0x48));
    fStack_10 = 0.0;
    fStack_14 = 0.0;
    FUN_005b3690(&fStack_18,&fStack_18,(int)sVar4);
    FUN_005b3620(&fStack_18,&fStack_18,iVar6 - iVar5);
    FUN_005c11d0(&fStack_18,&fStack_18,param_1 + 0x80);
    pfVar10[4] = fStack_18;
    pfVar10[5] = fStack_14;
    pfVar10[6] = fStack_10;
    if (*(code **)(param_1 + 0x1c4) != (code *)0x0) {
      (**(code **)(param_1 + 0x1c4))(param_1,param_2,pfVar10);
    }
    pfVar11 = (float *)(param_1 + 0x19c);
    param_1 = 0;
    *pfVar10 = *pfVar11 + *pfVar10;
    pfVar10[1] = *(float *)(iVar3 + 0x1a0) + pfVar10[1];
    pfVar10[2] = *(float *)(iVar3 + 0x1a4) + pfVar10[2];
    pfVar10[4] = *(float *)(iVar3 + 0x1a8) + pfVar10[4];
    pfVar10[5] = *(float *)(iVar3 + 0x1ac) + pfVar10[5];
    pfVar10[6] = *(float *)(iVar3 + 0x1b0) + pfVar10[6];
    if ('\0' < *(char *)(param_2 + 0x410)) {
      do {
        if (*(short *)(iVar3 + 0x186) <= *(short *)(iVar3 + 0x18a)) {
          *(undefined2 *)(iVar3 + 0x18a) = 0;
        }
        uVar9 = (uint)*(short *)(iVar3 + 0x18a);
        uVar8 = uVar9 & 0x8000001f;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xffffffe0) + 1;
        }
        pfVar7 = (float *)((uVar8 + 1) * 0x20 +
                          *(int *)(iVar3 + 0x100 +
                                  ((int)(((int)uVar9 >> 0x1f & 0x1fU) + uVar9) >> 5) * 4));
        *(short *)(iVar3 + 0x18a) = *(short *)(iVar3 + 0x18a) + 1;
        pfVar11 = pfVar10;
        pfVar12 = pfVar7;
        for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
          *pfVar12 = *pfVar11;
          pfVar11 = pfVar11 + 1;
          pfVar12 = pfVar12 + 1;
        }
        param_1 = param_1 + 1;
        pfVar7[3] = (float)param_1 * *(float *)(param_2 + 0x414) + pfVar7[3];
      } while (param_1 < *(char *)(param_2 + 0x410));
    }
    if (*(int *)(param_2 + 0x2a8) == 0) {
      FUN_00600260(param_2);
    }
    return pfVar10;
  }
  return (float *)0x0;
}

