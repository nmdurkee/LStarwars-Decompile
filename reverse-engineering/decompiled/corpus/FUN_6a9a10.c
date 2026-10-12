/* Ghidra analysis pseudocode, not original source.
 * ev_a0c592da085b7a74f005db934e1c866d8df8930552270784c21655c1c3dfc310
 * Entry: 0x6a9a10; label: FUN_006a9a10
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006a9a10(int *param_1,float *param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 auStack_30 [3];
  float *local_10;
  int local_c;
  int local_8;
  
  if (0 < param_1[2]) {
    param_4 = param_4 / *param_1;
    auStack_30[2] = 0x6a9a3f;
    piVar5 = (int *)(&stack0xffffffdc + param_4 * -8);
    auStack_30[2 - param_4] = 0x6a9a49;
    local_8 = 0;
    if (0 < param_4) {
      do {
        auStack_30[param_4 * -2 + 2] = param_3;
        auStack_30[param_4 * -2 + 1] = param_1;
        auStack_30[param_4 * -2] = 0x6a9a6b;
        iVar3 = FUN_006a98d0();
        piVar5[param_4] = iVar3;
        if (iVar3 == -1) {
          return 0xffffffff;
        }
        local_8 = local_8 + 1;
        *piVar5 = param_1[4] + *param_1 * iVar3 * 4;
        piVar5 = piVar5 + 1;
      } while (local_8 < param_4);
    }
    iVar3 = 0;
    local_8 = 0;
    local_c = 0;
    if (0 < *param_1) {
      local_10 = param_2;
      do {
        iVar6 = 0;
        if (3 < param_4) {
          iVar7 = (param_4 - 4U >> 2) + 1;
          iVar6 = iVar7 * 4;
          pfVar4 = local_10;
          piVar5 = (int *)(&stack0xffffffe4 + param_4 * -8);
          do {
            iVar1 = piVar5[-1];
            iVar7 = iVar7 + -1;
            *pfVar4 = *(float *)(piVar5[-2] + iVar3) + *pfVar4;
            iVar2 = *piVar5;
            pfVar4[1] = *(float *)(iVar1 + iVar3) + pfVar4[1];
            iVar1 = piVar5[1];
            pfVar4[2] = *(float *)(iVar3 + iVar2) + pfVar4[2];
            pfVar4[3] = *(float *)(iVar1 + iVar3) + pfVar4[3];
            pfVar4 = pfVar4 + 4;
            piVar5 = piVar5 + 4;
          } while (iVar7 != 0);
        }
        if (iVar6 < param_4) {
          pfVar4 = param_2 + iVar6 + local_c;
          do {
            iVar7 = iVar6 * 4;
            iVar6 = iVar6 + 1;
            *pfVar4 = *(float *)(*(int *)(&stack0xffffffdc + iVar7 + param_4 * -8) + iVar3) +
                      *pfVar4;
            pfVar4 = pfVar4 + 1;
          } while (iVar6 < param_4);
        }
        local_c = local_c + param_4;
        local_8 = local_8 + 1;
        local_10 = local_10 + param_4;
        iVar3 = iVar3 + 4;
      } while (local_8 < *param_1);
    }
  }
  return 0;
}

