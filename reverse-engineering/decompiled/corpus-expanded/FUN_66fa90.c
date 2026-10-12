/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66fa90; label: FUN_0066fa90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066fa90(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = DAT_0292186c;
  iVar7 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
  iVar7 = FUN_006e6b90();
  fVar2 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
  iVar7 = FUN_006e6b90();
  fVar3 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
  iVar7 = FUN_006e6b90();
  fVar4 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff];
  *(float *)(iVar6 + 0x100) =
       fVar2 * *(float *)(param_1 + 0x1c) - fVar1 * *(float *)(param_1 + 0x20);
  fVar5 = fVar2 * *(float *)(param_1 + 0x20) + *(float *)(param_1 + 0x1c) * fVar1;
  *(float *)(iVar6 + 0x104) = fVar4 * fVar5 - fVar3 * *(float *)(param_1 + 0x18);
  *(float *)(iVar6 + 0xfc) = *(float *)(param_1 + 0x18) * fVar4 + fVar3 * fVar5;
  *(float *)(iVar6 + 0x10c) =
       *(float *)(param_1 + 0x28) * fVar2 - *(float *)(param_1 + 0x2c) * fVar1;
  fVar5 = *(float *)(param_1 + 0x28) * fVar1 + *(float *)(param_1 + 0x2c) * fVar2;
  *(float *)(iVar6 + 0x110) = fVar5 * fVar4 - *(float *)(param_1 + 0x24) * fVar3;
  *(float *)(iVar6 + 0x108) = *(float *)(param_1 + 0x24) * fVar4 + fVar3 * fVar5;
  *(float *)(iVar6 + 0x118) =
       *(float *)(param_1 + 0x34) * fVar2 - *(float *)(param_1 + 0x38) * fVar1;
  fVar5 = *(float *)(param_1 + 0x34) * fVar1 + *(float *)(param_1 + 0x38) * fVar2;
  *(float *)(iVar6 + 0x11c) = fVar5 * fVar4 - *(float *)(param_1 + 0x30) * fVar3;
  *(float *)(iVar6 + 0x114) = *(float *)(param_1 + 0x30) * fVar4 + fVar3 * fVar5;
  if (*(float *)(param_1 + 0x58) < 65536.0) {
    *(float *)(iVar6 + 0x124) =
         *(float *)(param_1 + 0x40) * fVar2 - *(float *)(param_1 + 0x44) * fVar1;
    fVar1 = *(float *)(param_1 + 0x44) * fVar2 + *(float *)(param_1 + 0x40) * fVar1;
    *(float *)(iVar6 + 0x128) = fVar1 * fVar4 - *(float *)(param_1 + 0x3c) * fVar3;
    *(float *)(iVar6 + 0x120) = fVar1 * fVar3 + *(float *)(param_1 + 0x3c) * fVar4;
    return;
  }
  return;
}

