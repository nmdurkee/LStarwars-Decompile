/* Ghidra pseudocode, not original source.
 * ev_c05a879289b990ff88cf7a9522290ffc2251a9afe27d1f4d8d300c11e053da0d
 * Entry: 0x521fd0; label: FUN_00521fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00521fd0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float10 fVar7;
  float local_18;
  float local_c;
  float local_8;
  float local_4;
  
  local_18 = 3.4028235e+38;
  iVar5 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
  iVar3 = 0;
  fVar4 = local_18;
  while (iVar5 != 0) {
    fVar7 = (float10)FUN_005b3cf0(DAT_009238e4 + 0x28,iVar5 + 0x18,&local_c);
    fVar1 = (float)fVar7;
    iVar6 = iVar3;
    local_18 = fVar4;
    if (((((fVar1 < fVar4) && (iVar6 = iVar5, local_18 = fVar1, param_1 != 0)) &&
         (FUN_005b3620(&local_c,&local_c,-*(int *)(iVar5 + 0x24)), iVar6 = iVar3, local_18 = fVar4,
         local_c < _DAT_00801cc4)) && ((local_8 < _DAT_00801cc4 && (local_4 < _DAT_00801cc4)))) &&
       ((fVar2 = -_DAT_00801cc4, fVar2 < local_c && ((fVar2 < local_8 && (fVar2 < local_4)))))) {
      iVar6 = iVar5;
      local_18 = fVar1;
    }
    iVar5 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar5);
    iVar3 = iVar6;
    fVar4 = local_18;
  }
  return iVar3;
}

