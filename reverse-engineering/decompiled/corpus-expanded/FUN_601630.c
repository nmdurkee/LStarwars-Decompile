/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x601630; label: FUN_00601630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00601630(ushort *param_1,undefined4 *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  ushort *puVar14;
  undefined4 *puVar15;
  undefined4 local_24 [9];
  
  uVar1 = *param_1;
  uVar2 = *param_1;
  uVar3 = *param_1;
  uVar4 = *param_1;
  uVar5 = *param_1;
  uVar6 = param_1[1];
  puVar14 = param_1 + 2;
  puVar15 = local_24;
  for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
    *puVar15 = *(undefined4 *)puVar14;
    puVar14 = puVar14 + 2;
    puVar15 = puVar15 + 1;
  }
  uVar7 = *(undefined4 *)(param_1 + 0x14);
  uVar8 = *(undefined4 *)(param_1 + 0x16);
  uVar9 = *(undefined4 *)(param_1 + 0x18);
  uVar10 = *(undefined4 *)(param_1 + 0x1a);
  uVar11 = *(undefined4 *)(param_1 + 0x1c);
  uVar12 = *(undefined4 *)(param_1 + 0x1e);
  puVar14 = param_1;
  for (iVar13 = 0xb1; iVar13 != 0; iVar13 = iVar13 + -1) {
    *(undefined4 *)puVar14 = *param_2;
    param_2 = param_2 + 1;
    puVar14 = puVar14 + 2;
  }
  *param_1 = (((((short)(uVar5 << 4) >> 8 & 0xffU) * 2 | (short)(uVar4 << 0xc) >> 0xf & 1U) * 2 |
              (short)(uVar3 << 0xd) >> 0xf & 1U) * 2 | (short)(uVar2 << 0xe) >> 0xf & 1U) * 2 |
             *param_1 & 0xf000 | (short)(uVar1 << 0xf) >> 0xf & 1U;
  param_1[1] = uVar6;
  puVar15 = local_24;
  puVar14 = param_1 + 2;
  for (iVar13 = 9; iVar13 != 0; iVar13 = iVar13 + -1) {
    *(undefined4 *)puVar14 = *puVar15;
    puVar15 = puVar15 + 1;
    puVar14 = puVar14 + 2;
  }
  *(undefined4 *)(param_1 + 0x14) = uVar7;
  *(undefined4 *)(param_1 + 0x16) = uVar8;
  *(undefined4 *)(param_1 + 0x18) = uVar9;
  *(undefined4 *)(param_1 + 0x1a) = uVar10;
  *(undefined4 *)(param_1 + 0x1c) = uVar11;
  *(undefined4 *)(param_1 + 0x1e) = uVar12;
  return;
}

