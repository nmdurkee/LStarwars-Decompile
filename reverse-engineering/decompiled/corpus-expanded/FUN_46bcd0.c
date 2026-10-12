/* Ghidra pseudocode, not original source.
 * ev_21d1b4024f0628b99911cc952efca6864ea092f4299a0ea9bb41a534640658fb
 * Entry: 0x46bcd0; label: FUN_0046bcd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0046bcd0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [16];
  
  if (((DAT_0087b014 == 0) ||
      (local_4c = _DAT_007f9048, *(int *)(PTR_DAT_00802c54 + 300) != DAT_0087b014)) &&
     (((DAT_0087b01c != 0 && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087b01c)) ||
      ((local_4c = _DAT_007f9050, DAT_0087af78 != 0 &&
       (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af78)))))) {
    local_4c = _DAT_007f904c;
  }
  local_4c = (1.0 - (float)param_1[0x40] / _DAT_007f903c) * local_4c;
  if (0.0 < local_4c) {
    puVar2 = param_1;
    puVar3 = local_40;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    local_48 = local_4c;
    local_44 = local_4c;
    FUN_005b4c30(local_40,&local_4c);
    iVar1 = FUN_005f33b0(param_1 + 0x52,local_40);
    if (iVar1 != 0) {
      param_1[0x51] = param_1[0x51] | 0x600;
      return 0;
    }
  }
  return 0;
}

