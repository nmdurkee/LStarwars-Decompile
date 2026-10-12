/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5a93b0; label: FUN_005a93b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005a93b0(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int in_EDX;
  int iVar5;
  int iVar6;
  int iVar7;
  float local_18;
  int local_10;
  
  local_18 = 1e+09;
  *param_3 = 0.0;
  iVar6 = 0;
  iVar7 = 0;
  local_10 = 0;
  if (3 < DAT_0095df38) {
    iVar5 = 2;
    do {
      if ((((iVar7 != param_2) &&
           (iVar4 = *(int *)(param_1 + 0x5040) + iVar6, (*(byte *)(iVar4 + 0x20) & 1) != 0)) &&
          ((uVar3 = *(uint *)(in_EDX + 0x18) >> 0x19 & 1, uVar3 != 0 ||
           ((*(uint *)(iVar4 + 0x18) & 0x2000000) != 0)))) &&
         (((uVar3 != 1 || ((*(uint *)(iVar4 + 0x18) & 0x2000000) == 0)) &&
          (fVar1 = *(float *)(iVar4 + 0x44) - *(float *)(in_EDX + 0x44),
          fVar2 = *(float *)(iVar4 + 0x4c) - *(float *)(in_EDX + 0x4c),
          fVar1 = fVar1 * fVar1 + fVar2 * fVar2, fVar1 < local_18)))) {
        *(int *)(in_EDX + 0x50) = iVar7;
        local_18 = fVar1;
        local_10 = iVar4;
      }
      if (((iVar5 + -1 != param_2) &&
          (iVar4 = *(int *)(param_1 + 0x5040) + 0x54 + iVar6,
          (*(byte *)(*(int *)(param_1 + 0x5040) + 0x74 + iVar6) & 1) != 0)) &&
         (((uVar3 = *(uint *)(in_EDX + 0x18) >> 0x19 & 1, uVar3 != 0 ||
           ((*(uint *)(iVar4 + 0x18) & 0x2000000) != 0)) &&
          (((uVar3 != 1 || ((*(uint *)(iVar4 + 0x18) & 0x2000000) == 0)) &&
           (fVar1 = *(float *)(iVar4 + 0x44) - *(float *)(in_EDX + 0x44),
           fVar2 = *(float *)(iVar4 + 0x4c) - *(float *)(in_EDX + 0x4c),
           fVar1 = fVar1 * fVar1 + fVar2 * fVar2, fVar1 < local_18)))))) {
        *(int *)(in_EDX + 0x50) = iVar5 + -1;
        local_18 = fVar1;
        local_10 = iVar4;
      }
      if (((iVar5 != param_2) &&
          (iVar4 = *(int *)(param_1 + 0x5040) + 0xa8 + iVar6,
          (*(byte *)(*(int *)(param_1 + 0x5040) + 200 + iVar6) & 1) != 0)) &&
         (((uVar3 = *(uint *)(in_EDX + 0x18) >> 0x19 & 1, uVar3 != 0 ||
           ((*(uint *)(iVar4 + 0x18) & 0x2000000) != 0)) &&
          (((uVar3 != 1 || ((*(uint *)(iVar4 + 0x18) & 0x2000000) == 0)) &&
           (fVar1 = *(float *)(iVar4 + 0x44) - *(float *)(in_EDX + 0x44),
           fVar2 = *(float *)(iVar4 + 0x4c) - *(float *)(in_EDX + 0x4c),
           fVar1 = fVar1 * fVar1 + fVar2 * fVar2, fVar1 < local_18)))))) {
        *(int *)(in_EDX + 0x50) = iVar5;
        local_18 = fVar1;
        local_10 = iVar4;
      }
      if (((iVar5 + 1 != param_2) &&
          (iVar4 = *(int *)(param_1 + 0x5040) + 0xfc + iVar6,
          (*(byte *)(*(int *)(param_1 + 0x5040) + 0x11c + iVar6) & 1) != 0)) &&
         (((uVar3 = *(uint *)(in_EDX + 0x18) >> 0x19 & 1, uVar3 != 0 ||
           ((*(uint *)(iVar4 + 0x18) & 0x2000000) != 0)) &&
          (((uVar3 != 1 || ((*(uint *)(iVar4 + 0x18) & 0x2000000) == 0)) &&
           (fVar1 = *(float *)(iVar4 + 0x44) - *(float *)(in_EDX + 0x44),
           fVar2 = *(float *)(iVar4 + 0x4c) - *(float *)(in_EDX + 0x4c),
           fVar1 = fVar1 * fVar1 + fVar2 * fVar2, fVar1 < local_18)))))) {
        *(int *)(in_EDX + 0x50) = iVar5 + 1;
        local_18 = fVar1;
        local_10 = iVar4;
      }
      iVar7 = iVar7 + 4;
      iVar6 = iVar6 + 0x150;
      iVar5 = iVar5 + 4;
    } while (iVar7 < DAT_0095df38 + -3);
  }
  if (iVar7 < DAT_0095df38) {
    iVar6 = iVar7 * 0x54;
    do {
      if (((iVar7 != param_2) &&
          (iVar5 = *(int *)(param_1 + 0x5040) + iVar6, (*(byte *)(iVar5 + 0x20) & 1) != 0)) &&
         (((uVar3 = *(uint *)(in_EDX + 0x18) >> 0x19 & 1, uVar3 != 0 ||
           ((*(uint *)(iVar5 + 0x18) & 0x2000000) != 0)) &&
          (((uVar3 != 1 || ((*(uint *)(iVar5 + 0x18) & 0x2000000) == 0)) &&
           (fVar1 = *(float *)(iVar5 + 0x44) - *(float *)(in_EDX + 0x44),
           fVar2 = *(float *)(iVar5 + 0x4c) - *(float *)(in_EDX + 0x4c),
           fVar1 = fVar1 * fVar1 + fVar2 * fVar2, fVar1 < local_18)))))) {
        *(int *)(in_EDX + 0x50) = iVar7;
        local_18 = fVar1;
        local_10 = iVar5;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0x54;
    } while (iVar7 < DAT_0095df38);
  }
  *param_3 = local_18;
  return local_10;
}

