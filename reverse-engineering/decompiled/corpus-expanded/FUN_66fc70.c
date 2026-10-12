/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66fc70; label: FUN_0066fc70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066fc70(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = DAT_0292186c;
  iVar9 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff];
  iVar9 = FUN_006e6b90();
  fVar2 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff];
  iVar9 = FUN_006e6b90();
  fVar3 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff];
  iVar9 = FUN_006e6b90();
  fVar4 = (float)(&DAT_029899a0)[iVar9 >> 1 & 0x7fff];
  fVar5 = *(float *)(param_1 + 0x20) - *(float *)(iVar8 + 0x78);
  fVar7 = *(float *)(param_1 + 0x18) - *(float *)(iVar8 + 0x70);
  fVar6 = fVar4 * fVar5 - fVar3 * fVar7;
  *(float *)(iVar8 + 0xfc) = fVar4 * fVar7 + fVar3 * fVar5;
  *(float *)(iVar8 + 0x100) =
       fVar2 * (*(float *)(param_1 + 0x1c) - *(float *)(iVar8 + 0x74)) - fVar1 * fVar6;
  *(float *)(iVar8 + 0x104) =
       (*(float *)(param_1 + 0x1c) - *(float *)(iVar8 + 0x74)) * fVar1 + fVar2 * fVar6;
  fVar7 = *(float *)(param_1 + 0x2c) - *(float *)(iVar8 + 0x78);
  fVar6 = *(float *)(param_1 + 0x24) - *(float *)(iVar8 + 0x70);
  fVar5 = fVar4 * fVar7 - fVar3 * fVar6;
  *(float *)(iVar8 + 0x108) = fVar6 * fVar4 + fVar3 * fVar7;
  *(float *)(iVar8 + 0x10c) =
       (*(float *)(param_1 + 0x28) - *(float *)(iVar8 + 0x74)) * fVar2 - fVar5 * fVar1;
  *(float *)(iVar8 + 0x110) =
       (*(float *)(param_1 + 0x28) - *(float *)(iVar8 + 0x74)) * fVar1 + fVar2 * fVar5;
  fVar7 = *(float *)(param_1 + 0x38) - *(float *)(iVar8 + 0x78);
  fVar6 = *(float *)(param_1 + 0x30) - *(float *)(iVar8 + 0x70);
  fVar5 = fVar4 * fVar7 - fVar3 * fVar6;
  *(float *)(iVar8 + 0x114) = fVar6 * fVar4 + fVar3 * fVar7;
  *(float *)(iVar8 + 0x118) =
       (*(float *)(param_1 + 0x34) - *(float *)(iVar8 + 0x74)) * fVar2 - fVar5 * fVar1;
  *(float *)(iVar8 + 0x11c) =
       (*(float *)(param_1 + 0x34) - *(float *)(iVar8 + 0x74)) * fVar1 + fVar2 * fVar5;
  if (*(float *)(param_1 + 0x58) < 65536.0) {
    fVar7 = *(float *)(param_1 + 0x44) - *(float *)(iVar8 + 0x78);
    fVar6 = *(float *)(param_1 + 0x3c) - *(float *)(iVar8 + 0x70);
    fVar5 = fVar4 * fVar7 - fVar3 * fVar6;
    *(float *)(iVar8 + 0x120) = fVar6 * fVar4 + fVar7 * fVar3;
    *(float *)(iVar8 + 0x124) =
         (*(float *)(param_1 + 0x40) - *(float *)(iVar8 + 0x74)) * fVar2 - fVar5 * fVar1;
    *(float *)(iVar8 + 0x128) =
         (*(float *)(param_1 + 0x40) - *(float *)(iVar8 + 0x74)) * fVar1 + fVar5 * fVar2;
    return;
  }
  return;
}

