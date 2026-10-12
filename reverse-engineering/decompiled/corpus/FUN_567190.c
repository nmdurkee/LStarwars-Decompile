/* Ghidra analysis pseudocode, not original source.
 * ev_b9433c7f5b60e61c8ae549a75e6ee409cf02164bae1bfdd2a40ff6f2bd4737bb
 * Entry: 0x567190; label: FUN_00567190
 */

void FUN_00567190(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  undefined4 local_128 [71];
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)&local_13c;
  local_134 = *(int *)(param_1 + 0x50c4);
  local_12c = param_1;
  local_13c = 0;
  local_138 = 0;
  if (0 < *(int *)(param_1 + 0x50bc)) {
    do {
      iVar3 = *(int *)(param_1 + 0x50c0);
      if (local_13c < iVar3) {
        local_130 = local_13c * 0x114;
        do {
          iVar2 = *(int *)(param_1 + 0x50c8);
          puVar5 = (undefined4 *)(local_130 + iVar2);
          if (*(int *)(local_130 + 0xa4 + iVar2) != local_134) {
            puVar4 = puVar5;
            do {
              puVar7 = puVar4 + 0x45;
              if (puVar7 == (undefined4 *)(iVar3 * 0x114 + iVar2)) goto LAB_00567288;
              piVar1 = puVar4 + 0x6e;
              puVar4 = puVar7;
            } while (*piVar1 != local_134);
            puVar4 = puVar5;
            puVar6 = local_128;
            for (iVar3 = 0x45; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar6 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar6 = puVar6 + 1;
            }
            puVar4 = puVar7;
            for (iVar3 = 0x45; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar5 = *puVar4;
              puVar4 = puVar4 + 1;
              puVar5 = puVar5 + 1;
            }
            puVar5 = local_128;
            for (iVar3 = 0x45; iVar3 != 0; iVar3 = iVar3 + -1) {
              *puVar7 = *puVar5;
              puVar5 = puVar5 + 1;
              puVar7 = puVar7 + 1;
            }
          }
          iVar3 = *(int *)(param_1 + 0x50c0);
          local_13c = local_13c + 1;
          local_130 = local_130 + 0x114;
        } while (local_13c < iVar3);
      }
LAB_00567288:
      local_138 = local_138 + 1;
      local_134 = local_134 + 0x100;
    } while (local_138 < *(int *)(param_1 + 0x50bc));
  }
  __security_check_cookie(local_c ^ (uint)&local_13c);
  return;
}

