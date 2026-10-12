/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x651530; label: FUN_00651530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00651530(int param_1)

{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  param_1 = param_1 * 0x40;
  puVar1 = (uint *)(param_1 + 4 + DAT_02947b74);
  *puVar1 = *puVar1 | 0x7fff;
  *(undefined **)(param_1 + DAT_02947b74) = &DAT_0293b318 + DAT_0296201c * 0x20;
  *(undefined4 *)(param_1 + 8 + DAT_02947b74) = 0x5622;
  *(undefined1 *)(param_1 + 0xc + DAT_02947b74) = 0;
  *(undefined4 *)(param_1 + 0x18 + DAT_02947b74) = 0;
  puVar1 = (uint *)(param_1 + 4 + DAT_02947b74);
  *puVar1 = *puVar1 & 0xffbfffff;
  *(undefined2 *)(param_1 + 0x12 + DAT_02947b74) = 0x3fff;
  *(undefined4 *)(param_1 + 0x1c + DAT_02947b74) = 0;
  *(undefined4 *)(param_1 + 0x20 + DAT_02947b74) = 0;
  *(undefined2 *)(param_1 + 0x14 + DAT_02947b74) = 0xffff;
  puVar1 = (uint *)(param_1 + 4 + DAT_02947b74);
  *puVar1 = *puVar1 & 0xffff7fff;
  puVar1 = (uint *)(param_1 + 4 + DAT_02947b74);
  *puVar1 = *puVar1 & 0xfffeffff;
  puVar1 = (uint *)(param_1 + 4 + DAT_02947b74);
  *puVar1 = *puVar1 & 0xfffdffff;
  puVar1 = (uint *)(param_1 + 4 + DAT_02947b74);
  *puVar1 = *puVar1 & 0xfffbffff;
  puVar1 = (uint *)(param_1 + 4 + DAT_02947b74);
  *puVar1 = *puVar1 & 0xffefffff;
  *(undefined4 *)(param_1 + 0x24 + DAT_02947b74) = 0;
  *(undefined4 *)(param_1 + 0x28 + DAT_02947b74) = 0;
  *(undefined4 *)(param_1 + 0x2c + DAT_02947b74) = 0;
  *(undefined4 *)(param_1 + 0x30 + DAT_02947b74) = 0;
  *(undefined4 *)(param_1 + 0x34 + DAT_02947b74) = 0;
  *(undefined4 *)(param_1 + 0x38 + DAT_02947b74) = 0;
  *(undefined2 *)(param_1 + 0x16 + DAT_02947b74) = 0;
  puVar1 = (uint *)(param_1 + 4 + DAT_02947b74);
  *puVar1 = *puVar1 & 0xffdfffff;
  puVar3 = (undefined4 *)(param_1 + DAT_02947b74);
  puVar4 = (undefined4 *)(param_1 + DAT_0292fda4);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  return;
}

