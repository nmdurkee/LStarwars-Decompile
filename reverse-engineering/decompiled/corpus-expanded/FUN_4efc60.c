/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4efc60; label: FUN_004efc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint * FUN_004efc60(int *param_1,uint *param_2)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  
  if (param_2 != (uint *)0x0) {
    uVar3 = param_2[-3] & 0x7fffffff;
    uVar5 = *(uint *)(uVar3 + 4 + (int)param_2);
    puVar2 = param_2;
    if (-1 < (int)uVar5) {
      iVar6 = *(int *)(uVar3 + 0xc + (int)param_2);
      uVar5 = uVar5 & 0x7fffffff;
      if (iVar6 != 0) {
        *(undefined4 *)(iVar6 + 4) = *(undefined4 *)(uVar3 + 8 + (int)param_2);
      }
      iVar6 = *(int *)(uVar3 + 8 + (int)param_2);
      if (iVar6 != 0) {
        *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(uVar3 + 0xc + (int)param_2);
      }
      iVar6 = uVar3 - 1;
      iVar1 = uVar5 + 0x1c + (int)param_2;
      if (-1 < iVar6) {
        puVar4 = (undefined1 *)(iVar6 + iVar1);
        do {
          *puVar4 = puVar4[(int)param_2 - iVar1];
          iVar6 = iVar6 + -1;
          puVar4 = puVar4 + -1;
        } while (-1 < iVar6);
      }
      puVar2 = (uint *)(uVar5 + 0x10 + (int)param_2);
      puVar2[1] = 0;
      puVar2[2] = 0;
      *puVar2 = uVar3 | 0x80000000;
      *(uint **)(uVar3 + 0xc + (int)puVar2) = puVar2;
      *param_2 = uVar5;
      puVar2 = puVar2 + 3;
      param_2[1] = 0;
      param_2[2] = 0;
      *(uint **)(uVar5 + 0xc + (int)param_2) = param_2;
      iVar6 = *param_1;
      if (*(int *)(iVar6 + 0x14) != 0) {
        *(uint **)(*(int *)(iVar6 + 0x14) + 8) = param_2;
      }
      param_2[1] = *(uint *)(iVar6 + 0x14);
      param_2[2] = iVar6 + 0x10;
      *(uint **)(iVar6 + 0x14) = param_2;
    }
    return puVar2;
  }
  return (uint *)0x0;
}

