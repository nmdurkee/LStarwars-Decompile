/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4cf1b0; label: FUN_004cf1b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004cf1b0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  DAT_0088061c = PTR_DAT_007fd1e4;
  puVar2 = &DAT_00802728;
  puVar3 = &DAT_00880618;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  _DAT_00880620 = 0;
  _DAT_0088062c = 0;
  _DAT_00880630 = 0;
  _DAT_00880634 = 0;
  _DAT_00880638 = 0;
  _DAT_00880654 = 0;
  _DAT_00880658 = 0;
  _DAT_0088065c = 0;
  _DAT_00880660 = 0;
  _DAT_00880670 = 0;
  _DAT_00880674 = 0;
  _DAT_00880678 = 0;
  _DAT_0088067c = 0;
  _DAT_00880680 = 0;
  _DAT_00880684 = 0;
  _DAT_00880688 = 0;
  _DAT_0088068c = 0;
  DAT_00880618 = "Teleport";
  _DAT_00880624 = FUN_004cf0d0;
  _DAT_00880628 = FUN_004cf0f0;
  _DAT_0088063c = &LAB_004cf150;
  _DAT_00880640 = FUN_004cf170;
  _DAT_00880644 = FUN_004cf190;
  _DAT_00880648 = FUN_004cf1a0;
  _DAT_0088064c = FUN_004cf0b0;
  _DAT_00880650 = FUN_004cf070;
  _DAT_007fd248 = param_1;
  return &DAT_00880618;
}

