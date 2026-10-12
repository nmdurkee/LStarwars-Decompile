/* Ghidra pseudocode, not original source.
 * ev_d4530897d537ad66196ce8be54ac8764fec809d1ef324fd4741f37f5a52d36bb
 * Entry: 0x6121c0; label: FUN_006121c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006121c0(undefined4 param_1,undefined4 param_2,float param_3,int param_4,int param_5,
                 int param_6)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  
  iVar4 = FUN_00617a00();
  fVar2 = (float)iVar4;
  if (iVar4 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  fVar3 = 1.0 / (*(float *)((int)param_3 + 0xc) - *(float *)((int)param_3 + 8));
  fVar2 = fVar2 - *(float *)((int)param_3 + 0xc);
  iVar4 = 0;
  if (3 < param_6) {
    iVar7 = (param_6 - 4U >> 2) + 1;
    piVar5 = (int *)(param_4 + 4);
    iVar4 = iVar7 * 4;
    pfVar6 = (float *)(param_5 + 0xc);
    do {
      iVar1 = piVar5[-1];
      param_3 = (*(float *)(iVar1 + 8) - *(float *)(iVar1 + 4)) * fVar3 * fVar2 +
                *(float *)(iVar1 + 8);
      if (((*(ushort *)(in_ECX + 0xe) & 0x10) != 0) && (param_3 <= *(float *)(in_ECX + 0x20))) {
        param_3 = *(float *)(in_ECX + 0x20);
      }
      if (((*(ushort *)(in_ECX + 0xe) & 0x20) != 0) && (*(float *)(in_ECX + 0x24) <= param_3)) {
        param_3 = *(float *)(in_ECX + 0x24);
      }
      iVar1 = *piVar5;
      pfVar6[-3] = pfVar6[-3] * 0.8 + param_3 * 0.2;
      param_3 = (*(float *)(iVar1 + 8) - *(float *)(iVar1 + 4)) * fVar3 * fVar2 +
                *(float *)(iVar1 + 8);
      if (((*(ushort *)(in_ECX + 0xe) & 0x10) != 0) && (param_3 <= *(float *)(in_ECX + 0x20))) {
        param_3 = *(float *)(in_ECX + 0x20);
      }
      if (((*(ushort *)(in_ECX + 0xe) & 0x20) != 0) && (*(float *)(in_ECX + 0x24) <= param_3)) {
        param_3 = *(float *)(in_ECX + 0x24);
      }
      iVar1 = piVar5[1];
      *(float *)((int)piVar5 + (param_5 - param_4)) =
           param_3 * 0.2 + *(float *)((int)piVar5 + (param_5 - param_4)) * 0.8;
      param_3 = (*(float *)(iVar1 + 8) - *(float *)(iVar1 + 4)) * fVar3 * fVar2 +
                *(float *)(iVar1 + 8);
      if (((*(ushort *)(in_ECX + 0xe) & 0x10) != 0) && (param_3 <= *(float *)(in_ECX + 0x20))) {
        param_3 = *(float *)(in_ECX + 0x20);
      }
      if (((*(ushort *)(in_ECX + 0xe) & 0x20) != 0) && (*(float *)(in_ECX + 0x24) <= param_3)) {
        param_3 = *(float *)(in_ECX + 0x24);
      }
      iVar1 = piVar5[2];
      pfVar6[-1] = param_3 * 0.2 + pfVar6[-1] * 0.8;
      param_3 = (*(float *)(iVar1 + 8) - *(float *)(iVar1 + 4)) * fVar3 * fVar2 +
                *(float *)(iVar1 + 8);
      if (((*(ushort *)(in_ECX + 0xe) & 0x10) != 0) && (param_3 <= *(float *)(in_ECX + 0x20))) {
        param_3 = *(float *)(in_ECX + 0x20);
      }
      if (((*(ushort *)(in_ECX + 0xe) & 0x20) != 0) && (*(float *)(in_ECX + 0x24) <= param_3)) {
        param_3 = *(float *)(in_ECX + 0x24);
      }
      piVar5 = piVar5 + 4;
      iVar7 = iVar7 + -1;
      *pfVar6 = param_3 * 0.2 + *pfVar6 * 0.8;
      pfVar6 = pfVar6 + 4;
    } while (iVar7 != 0);
  }
  if (iVar4 < param_6) {
    piVar5 = (int *)(param_4 + iVar4 * 4);
    param_6 = param_6 - iVar4;
    do {
      iVar4 = *piVar5;
      param_3 = (*(float *)(iVar4 + 8) - *(float *)(iVar4 + 4)) * fVar3 * fVar2 +
                *(float *)(iVar4 + 8);
      if (((*(ushort *)(in_ECX + 0xe) & 0x10) != 0) && (param_3 <= *(float *)(in_ECX + 0x20))) {
        param_3 = *(float *)(in_ECX + 0x20);
      }
      if (((*(ushort *)(in_ECX + 0xe) & 0x20) != 0) && (*(float *)(in_ECX + 0x24) <= param_3)) {
        param_3 = *(float *)(in_ECX + 0x24);
      }
      pfVar6 = (float *)((param_5 - param_4) + (int)piVar5);
      piVar5 = piVar5 + 1;
      param_6 = param_6 + -1;
      *(float *)((param_5 - param_4) + -4 + (int)piVar5) = param_3 * 0.2 + *pfVar6 * 0.8;
    } while (param_6 != 0);
  }
  return;
}

