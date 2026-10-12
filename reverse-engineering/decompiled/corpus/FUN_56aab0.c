/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x56aab0; label: FUN_0056aab0
 */

uint * FUN_0056aab0(int param_1,float *param_2,float param_3)

{
  uint uVar1;
  float fVar2;
  uint *puVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float local_14;
  uint *local_4;
  
  iVar6 = 0;
  if (param_1 == 0) {
    return (uint *)0x0;
  }
  iVar5 = *(int *)(param_1 + 0x50c0);
  if (0 < iVar5) {
    if (param_2 != (float *)0x0) {
      local_14 = param_3;
      local_4 = (uint *)0x0;
      if (3 < iVar5) {
        iVar7 = (iVar5 - 4U >> 2) + 1;
        puVar4 = (uint *)(*(int *)(param_1 + 0x50c8) + 0x94);
        puVar3 = (uint *)(*(int *)(param_1 + 0x50c8) + 0x1a8);
        iVar6 = iVar7 * 4;
        do {
          uVar1 = *puVar4;
          if (((((uVar1 & 0x800000) != 0) && ((uVar1 & 1) == 0)) && ((uVar1 & 0x4000) != 0)) &&
             ((fVar2 = ((float)puVar4[-0x17] - param_2[2]) * ((float)puVar4[-0x17] - param_2[2]) +
                       ((float)puVar4[-0x19] - *param_2) * ((float)puVar4[-0x19] - *param_2) +
                       ((float)puVar4[-0x18] - param_2[1]) * ((float)puVar4[-0x18] - param_2[1]),
              fVar2 < param_3 && (fVar2 < local_14)))) {
            local_4 = puVar4 + -0x25;
            local_14 = fVar2;
          }
          uVar1 = *puVar3;
          if ((((uVar1 & 0x800000) != 0) && ((uVar1 & 1) == 0)) &&
             (((uVar1 & 0x4000) != 0 &&
              ((fVar2 = ((float)puVar3[-0x17] - param_2[2]) * ((float)puVar3[-0x17] - param_2[2]) +
                        ((float)puVar3[-0x19] - *param_2) * ((float)puVar3[-0x19] - *param_2) +
                        ((float)puVar3[-0x18] - param_2[1]) * ((float)puVar3[-0x18] - param_2[1]),
               fVar2 < param_3 && (fVar2 < local_14)))))) {
            local_4 = puVar4 + 0x20;
            local_14 = fVar2;
          }
          uVar1 = puVar3[0x45];
          if (((((uVar1 & 0x800000) != 0) && ((uVar1 & 1) == 0)) && ((uVar1 & 0x4000) != 0)) &&
             ((fVar2 = ((float)puVar3[0x2e] - param_2[2]) * ((float)puVar3[0x2e] - param_2[2]) +
                       ((float)puVar3[0x2c] - *param_2) * ((float)puVar3[0x2c] - *param_2) +
                       ((float)puVar3[0x2d] - param_2[1]) * ((float)puVar3[0x2d] - param_2[1]),
              fVar2 < param_3 && (fVar2 < local_14)))) {
            local_4 = puVar4 + 0x65;
            local_14 = fVar2;
          }
          uVar1 = puVar3[0x8a];
          if ((((uVar1 & 0x800000) != 0) && ((uVar1 & 1) == 0)) &&
             (((uVar1 & 0x4000) != 0 &&
              ((fVar2 = ((float)puVar3[0x73] - param_2[2]) * ((float)puVar3[0x73] - param_2[2]) +
                        ((float)puVar3[0x71] - *param_2) * ((float)puVar3[0x71] - *param_2) +
                        ((float)puVar3[0x72] - param_2[1]) * ((float)puVar3[0x72] - param_2[1]),
               fVar2 < param_3 && (fVar2 < local_14)))))) {
            local_4 = puVar4 + 0xaa;
            local_14 = fVar2;
          }
          puVar4 = puVar4 + 0x114;
          puVar3 = puVar3 + 0x114;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
      if (iVar6 < iVar5) {
        puVar4 = (uint *)(iVar6 * 0x114 + *(int *)(param_1 + 0x50c8));
        iVar5 = iVar5 - iVar6;
        do {
          uVar1 = puVar4[0x25];
          if (((((uVar1 & 0x800000) != 0) && ((uVar1 & 1) == 0)) && ((uVar1 & 0x4000) != 0)) &&
             ((fVar2 = ((float)puVar4[0xe] - param_2[2]) * ((float)puVar4[0xe] - param_2[2]) +
                       ((float)puVar4[0xc] - *param_2) * ((float)puVar4[0xc] - *param_2) +
                       ((float)puVar4[0xd] - param_2[1]) * ((float)puVar4[0xd] - param_2[1]),
              fVar2 < param_3 && (fVar2 < local_14)))) {
            local_14 = fVar2;
            local_4 = puVar4;
          }
          puVar4 = puVar4 + 0x45;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      return local_4;
    }
    return (uint *)0x0;
  }
  return (uint *)0x0;
}

