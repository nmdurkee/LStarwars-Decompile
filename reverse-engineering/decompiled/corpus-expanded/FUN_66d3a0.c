/* Ghidra pseudocode, not original source.
 * ev_ffad5e5ce23835b03a7ab4a596a1220c1c80cd63cb6050216f74ff540445a181
 * Entry: 0x66d3a0; label: FUN_0066d3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0066d3a0(int param_1,short param_2)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float *pfVar7;
  byte bVar8;
  
  iVar6 = param_1;
  bVar8 = (byte)param_2;
  if (*(float *)(param_1 + 0x58) <= 65535.0) {
    iVar1 = (uint)(byte)(bVar8 << 6) * 0x100 + (uint)(bVar8 & 0x80);
    param_1 = 0;
    do {
      fVar2 = (float)param_1;
      pfVar7 = (float *)(*DAT_0292fc68 + param_2 * 0x38);
      FUN_005dc050(*pfVar7 + *(float *)(iVar6 + 0x18) +
                   (*(float *)(iVar6 + 0x24) - *(float *)(iVar6 + 0x18)) * fVar2,
                   *(float *)(iVar6 + 0x1c) + pfVar7[1] +
                   (*(float *)(iVar6 + 0x28) - *(float *)(iVar6 + 0x1c)) * fVar2,
                   pfVar7[2] + *(float *)(iVar6 + 0x20) +
                   (*(float *)(iVar6 + 0x2c) - *(float *)(iVar6 + 0x20)) * fVar2,
                   *pfVar7 + *(float *)(iVar6 + 0x30) +
                   (*(float *)(iVar6 + 0x3c) - *(float *)(iVar6 + 0x30)) * fVar2,
                   *(float *)(iVar6 + 0x34) + pfVar7[1] +
                   (*(float *)(iVar6 + 0x40) - *(float *)(iVar6 + 0x34)) * fVar2,
                   pfVar7[2] + *(float *)(iVar6 + 0x38) +
                   fVar2 * (*(float *)(iVar6 + 0x44) - *(float *)(iVar6 + 0x38)),iVar1);
      param_1 = param_1 + 1;
    } while (param_1 < 2);
    param_1 = 0;
    do {
      fVar2 = (float)param_1;
      pfVar7 = (float *)(param_2 * 0x38 + *DAT_0292fc68);
      FUN_005dc050(*pfVar7 + *(float *)(iVar6 + 0x18) +
                   (*(float *)(iVar6 + 0x30) - *(float *)(iVar6 + 0x18)) * fVar2,
                   *(float *)(iVar6 + 0x1c) + pfVar7[1] +
                   (*(float *)(iVar6 + 0x34) - *(float *)(iVar6 + 0x1c)) * fVar2,
                   pfVar7[2] + *(float *)(iVar6 + 0x20) +
                   (*(float *)(iVar6 + 0x38) - *(float *)(iVar6 + 0x20)) * fVar2,
                   *pfVar7 + *(float *)(iVar6 + 0x24) +
                   (*(float *)(iVar6 + 0x3c) - *(float *)(iVar6 + 0x24)) * fVar2,
                   *(float *)(iVar6 + 0x28) + pfVar7[1] +
                   (*(float *)(iVar6 + 0x40) - *(float *)(iVar6 + 0x28)) * fVar2,
                   pfVar7[2] + *(float *)(iVar6 + 0x2c) +
                   fVar2 * (*(float *)(iVar6 + 0x44) - *(float *)(iVar6 + 0x2c)),iVar1);
      param_1 = param_1 + 1;
    } while (param_1 < 2);
  }
  iVar1 = (uint)(byte)(bVar8 << 6) * 0x100 + (uint)(bVar8 & 0x80);
  iVar3 = param_2 * 0x38;
  pfVar7 = (float *)(*DAT_0292fc68 + iVar3);
  fVar2 = pfVar7[2] + *(float *)(iVar6 + 0x20);
  fVar5 = pfVar7[1] + *(float *)(iVar6 + 0x1c);
  fVar4 = *(float *)(iVar6 + 0x18) + *pfVar7;
  FUN_005dc050(fVar4,fVar5,fVar2,*(float *)(iVar6 + 0x48) * 0.4 + fVar4,
               *(float *)(iVar6 + 0x4c) * 0.4 + fVar5,*(float *)(iVar6 + 0x50) * 0.4 + fVar2,iVar1);
  if (*(float *)(iVar6 + 0x58) < 65536.0) {
    pfVar7 = (float *)(iVar3 + *DAT_0292fc68);
    fVar2 = *(float *)(iVar3 + 8 + *DAT_0292fc68) + *(float *)(iVar6 + 0x44);
    fVar5 = pfVar7[1] + *(float *)(iVar6 + 0x40);
    fVar4 = *(float *)(iVar6 + 0x3c) + *pfVar7;
    FUN_005dc050(fVar4,fVar5,fVar2,*(float *)(iVar6 + 0x54) * 0.4 + fVar4,
                 *(float *)(iVar6 + 0x58) * 0.4 + fVar5,*(float *)(iVar6 + 0x5c) * 0.4 + fVar2,iVar1
                );
  }
  return;
}

