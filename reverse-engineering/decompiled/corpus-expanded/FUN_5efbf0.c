/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5efbf0; label: FUN_005efbf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005efbf0(uint *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  puVar3 = param_1;
  FUN_005dde00(&DAT_00973dbc,param_1,param_2,DAT_0080baa8 * 600,600,0,0,600,0,0);
  DAT_00973e1c = 0;
  iVar4 = 0xc;
  param_1 = (uint *)0x0;
  _DAT_00973dbc = PTR_s_Dynamic_Material_Display_Scene_0080c0e0;
  local_8 = DAT_0080baa8 * 0x50;
  local_10 = DAT_0080baa8 << 6;
  local_14 = DAT_0080baa8 * 0x30;
  local_1c = DAT_0080baa8 << 5;
  local_24 = DAT_0080baa8 << 4;
  local_28 = DAT_0080baac << 4;
  local_c = (DAT_0080baac + DAT_0080baa8 * 4) * 0x10;
  local_18 = (DAT_0080baac + DAT_0080baa8 * 2) * 0x10;
  iVar5 = DAT_0080baa8 * 0x60;
  iVar7 = (DAT_0080baac + DAT_0080baa8 * 3) * 0x10;
  local_20 = (DAT_0080baa8 + DAT_0080baac) * 0x10;
  iVar6 = 2;
  local_4 = (DAT_0080baac + DAT_0080baa8 * 5) * 0x10;
  do {
    *(int *)(*(int *)(iVar4 + -0xc + DAT_00973e10) + 0xc) = (int)param_1 + DAT_00973dc4;
    *(int *)(*(int *)(iVar4 + -0xc + DAT_00973e10) + 0x18) = local_28 + DAT_00973dc4;
    **(undefined4 **)(iVar4 + -0xc + DAT_00973e10) = &DAT_00973dbc;
    *(int *)(*(int *)(iVar4 + -0xc + DAT_00973e10) + 4) = iVar6 + -2;
    *(int *)(*(int *)(iVar4 + -8 + DAT_00973e10) + 0xc) = local_24 + DAT_00973dc4;
    *(int *)(*(int *)(iVar4 + -8 + DAT_00973e10) + 0x18) = local_20 + DAT_00973dc4;
    **(undefined4 **)(iVar4 + -8 + DAT_00973e10) = &DAT_00973dbc;
    *(int *)(*(int *)(iVar4 + -8 + DAT_00973e10) + 4) = iVar6 + -1;
    *(int *)(*(int *)(iVar4 + -4 + DAT_00973e10) + 0xc) = local_1c + DAT_00973dc4;
    *(int *)(*(int *)(iVar4 + -4 + DAT_00973e10) + 0x18) = local_18 + DAT_00973dc4;
    **(undefined4 **)(iVar4 + -4 + DAT_00973e10) = &DAT_00973dbc;
    *(int *)(*(int *)(iVar4 + -4 + DAT_00973e10) + 4) = iVar6;
    *(int *)(*(int *)(iVar4 + DAT_00973e10) + 0xc) = local_14 + DAT_00973dc4;
    *(int *)(*(int *)(iVar4 + DAT_00973e10) + 0x18) = DAT_00973dc4 + iVar7;
    **(undefined4 **)(iVar4 + DAT_00973e10) = &DAT_00973dbc;
    *(int *)(*(int *)(iVar4 + DAT_00973e10) + 4) = iVar6 + 1;
    *(int *)(*(int *)(iVar4 + 4 + DAT_00973e10) + 0xc) = local_10 + DAT_00973dc4;
    *(int *)(*(int *)(iVar4 + 4 + DAT_00973e10) + 0x18) = local_c + DAT_00973dc4;
    **(undefined4 **)(iVar4 + 4 + DAT_00973e10) = &DAT_00973dbc;
    *(int *)(*(int *)(iVar4 + 4 + DAT_00973e10) + 4) = iVar6 + 2;
    *(int *)(*(int *)(iVar4 + 8 + DAT_00973e10) + 0xc) = local_8 + DAT_00973dc4;
    param_1 = (uint *)((int)param_1 + iVar5);
    local_28 = local_28 + iVar5;
    local_24 = local_24 + iVar5;
    local_20 = local_20 + iVar5;
    local_1c = local_1c + iVar5;
    local_18 = local_18 + iVar5;
    local_14 = local_14 + iVar5;
    local_10 = local_10 + iVar5;
    local_c = local_c + iVar5;
    local_8 = local_8 + iVar5;
    *(int *)(*(int *)(iVar4 + 8 + DAT_00973e10) + 0x18) = local_4 + DAT_00973dc4;
    **(undefined4 **)(iVar4 + 8 + DAT_00973e10) = &DAT_00973dbc;
    *(int *)(*(int *)(iVar4 + 8 + DAT_00973e10) + 4) = iVar6 + 3;
    iVar1 = iVar6 + 4;
    iVar7 = iVar7 + iVar5;
    iVar4 = iVar4 + 0x18;
    iVar6 = iVar6 + 6;
    local_4 = local_4 + iVar5;
  } while (iVar1 < 600);
  *puVar3 = *puVar3 + 0xf & 0xfffffff0;
  DAT_00973e4c = 0;
  DAT_00973e50 = *puVar3;
  *puVar3 = *puVar3 + 0x960;
  DAT_00973e54 = 0;
  DAT_00973e58 = *puVar3;
  *puVar3 = *puVar3 + 0x960;
  DAT_00973e5c = (void *)*puVar3;
  *puVar3 = *puVar3 + 600;
  DAT_00973e6c = (void *)*puVar3;
  *puVar3 = *puVar3 + 600;
  _memset(DAT_00973e5c,0,600);
  _memset(DAT_00973e6c,0,600);
  DAT_00973e64 = *puVar3 + 0xf & 0xfffffff0;
  DAT_00973e68 = (*puVar3 + 0xf & 0xfffffff0) + 0x12c00;
  *puVar3 = DAT_00973e68;
  puVar2 = DAT_00973e80;
  *DAT_00973e80 = 0x8d;
  *(undefined4 *)(puVar2 + 4) = 0;
  puVar2[1] = 1;
  DAT_00973e84 = DAT_00973e80;
  DAT_00973e78 = *puVar3 + 3 & 0xfffffffc;
  *puVar3 = (*puVar3 + 3 & 0xfffffffc) + 0x34;
  FUN_005fca40(DAT_00973e78);
  DAT_00973e30 = DAT_00973e30 | 0x10;
  DAT_00973e84 = DAT_00973e80;
  return;
}

