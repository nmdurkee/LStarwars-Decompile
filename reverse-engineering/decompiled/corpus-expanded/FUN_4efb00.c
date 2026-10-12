/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4efb00; label: FUN_004efb00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004efb00(uint *param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined4 uVar3;
  uint *puVar4;
  
  uVar2 = *param_1;
  if (((param_2 != 0) && (uVar2 <= param_2)) && (param_2 <= param_1[1] + uVar2)) {
    *(uint *)(param_2 - 0xc) = *(uint *)(param_2 - 0xc) & 0x7fffffff;
    param_1[2] = param_1[2] - 1;
    puVar1 = (uint *)(param_2 - 0xc);
    param_1[3] = param_1[3] + (-0x10 - (*puVar1 & 0x7fffffff));
    if (*(int *)(uVar2 + 0x14) != 0) {
      *(uint **)(*(int *)(uVar2 + 0x14) + 8) = puVar1;
    }
    uVar3 = *(undefined4 *)(uVar2 + 0x14);
    *(uint *)(param_2 - 4) = uVar2 + 0x10;
    *(undefined4 *)(param_2 - 8) = uVar3;
    *(uint **)(uVar2 + 0x14) = puVar1;
    uVar2 = *puVar1;
    if ((*(uint *)((uVar2 & 0x7fffffff) + 0x10 + (int)puVar1) & 0x80000000) == 0) {
      FUN_004ef870();
      uVar2 = (*(uint *)((uVar2 & 0x7fffffff) + 0x10 + (int)puVar1) & 0x7fffffff) + 0x10 +
              (*puVar1 & 0x7fffffff);
      *puVar1 = *puVar1 & 0x80000000 | uVar2;
      *(uint **)((uVar2 & 0x7fffffff) + 0xc + (int)puVar1) = puVar1;
    }
    puVar4 = *(uint **)(param_2 - 0x10);
    if ((*puVar4 & 0x80000000) == 0) {
      FUN_004ef870();
      uVar2 = (*puVar1 & 0x7fffffff) + 0x10 + (*puVar4 & 0x7fffffff);
      *puVar4 = *puVar4 & 0x80000000 | uVar2;
      *(uint **)((uVar2 & 0x7fffffff) + 0xc + (int)puVar4) = puVar4;
    }
  }
  return;
}

