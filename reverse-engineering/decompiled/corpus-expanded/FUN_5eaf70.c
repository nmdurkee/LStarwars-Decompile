/* Ghidra pseudocode, not original source.
 * ev_bb04fbbbd27a84d29838025e356b4a832b57e1ec23fb072545eb7050db0a5426
 * Entry: 0x5eaf70; label: FUN_005eaf70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005eaf70(int param_1,uint param_2,int param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  
  if (param_1 == 0) {
    FUN_005c12e0();
  }
  uVar8 = *param_4;
  uVar6 = uVar8 + 0xf & 0xfffffff0;
  *param_4 = uVar6;
  uVar6 = uVar6 + *(int *)(param_1 + 8);
  *param_4 = uVar6;
  uVar8 = uVar8 + 0xf & 0xfffffff0;
  if (uVar6 < *param_5) {
    FUN_004ef660(uVar8,param_1,*(undefined4 *)(param_1 + 8));
    *(ushort *)(uVar8 + 6) = *(ushort *)(uVar8 + 6) | 1;
    *(int *)(uVar8 + 0x34) = *(int *)(uVar8 + 0x34) + (uVar8 - param_1);
    *(int *)(uVar8 + 0x38) = *(int *)(uVar8 + 0x38) + (uVar8 - param_1);
  }
  if ((0x17 < param_3) || (param_3 < 0)) {
    param_3 = FUN_005c12e0();
  }
  iVar5 = DAT_00973ff4;
  DAT_00973ff4 = param_3;
  uVar7 = FUN_005e4b20((param_2 & 8) != 0);
  *(undefined4 *)(uVar8 + 0x40) = uVar7;
  iVar3 = *(int *)(param_1 + 0x40);
  iVar4 = *(int *)(uVar8 + 0x40);
  *(undefined4 *)(iVar4 + 0x40) = *(undefined4 *)(iVar3 + 0x40);
  *(undefined4 *)(iVar4 + 0x44) = *(undefined4 *)(iVar3 + 0x44);
  *(undefined2 *)(*(int *)(uVar8 + 0x40) + 0x74) = *(undefined2 *)(*(int *)(param_1 + 0x40) + 0x74);
  *(undefined2 *)(*(int *)(uVar8 + 0x40) + 0x76) = *(undefined2 *)(*(int *)(param_1 + 0x40) + 0x76);
  *(uint *)(*(int *)(uVar8 + 0x40) + 0x40) =
       *(uint *)(*(int *)(uVar8 + 0x40) + 0x40) & 0xfffeffff | 0x20000;
  if ((param_2 & 8) != 0) {
    puVar1 = (uint *)(*(int *)(uVar8 + 0x40) + 0x44);
    *puVar1 = *puVar1 & 0xff7fffff;
  }
  if ((param_2 & 0x40) != 0) {
    puVar1 = (uint *)(*(int *)(uVar8 + 0x40) + 0x40);
    *puVar1 = *puVar1 & 0xffff3fff;
  }
  iVar3 = *(int *)(uVar8 + 0x40);
  FUN_00601030(iVar3);
  psVar2 = (short *)(iVar3 + 0x2c0);
  *psVar2 = *psVar2 + 1;
  if ((0x17 < iVar5) || (iVar5 < 0)) {
    FUN_005c12e0();
  }
  DAT_00973ff4 = iVar5;
  return uVar8;
}

