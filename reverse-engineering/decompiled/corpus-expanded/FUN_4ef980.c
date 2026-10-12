/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4ef980; label: FUN_004ef980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004ef980(int *param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 < 0x50) {
    return 0;
  }
  iVar4 = *param_1;
  iVar3 = iVar4 + param_3;
  *param_1 = iVar3;
  *(undefined4 *)(iVar4 + 0x18) = 0;
  puVar1 = (undefined4 *)(iVar4 + 0x10);
  *puVar1 = 0;
  puVar2 = (uint *)(iVar4 + 0x30);
  *(uint **)(iVar4 + 0x14) = puVar2;
  *(undefined4 **)(iVar4 + 0x1c) = puVar1;
  *(undefined4 *)(iVar4 + 0x24) = 0;
  *(undefined4 *)(iVar4 + 0x28) = 0;
  *(undefined4 *)(iVar4 + 0x20) = 0x80000000;
  *(undefined4 **)(iVar4 + 0x2c) = (undefined4 *)(iVar4 + 0x20);
  *(undefined4 *)(iVar3 + -0xc) = 0;
  *(undefined4 *)(iVar3 + -8) = 0;
  *(undefined4 *)(iVar3 + -0x10) = 0x80000000;
  *(undefined4 **)(iVar3 + -4) = (undefined4 *)(iVar3 + -0x10);
  *puVar2 = param_3 - 0x50;
  *(undefined4 *)(iVar4 + 0x34) = 0;
  *(undefined4 **)(iVar4 + 0x38) = puVar1;
  *(uint **)((param_3 - 0x50 & 0x7fffffff) + 0xc + (int)puVar2) = puVar2;
  *(uint *)(iVar4 + 4) = param_3;
  *(undefined4 *)(iVar4 + 8) = 0;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(int *)iVar4 = iVar4;
  return iVar4;
}

