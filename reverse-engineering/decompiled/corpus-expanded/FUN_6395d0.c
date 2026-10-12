/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x6395d0; label: FUN_006395d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006395d0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_a4;
  undefined4 local_a0 [37];
  uint local_c;
  
  puVar3 = DAT_02913824;
  local_c = DAT_00829570 ^ (uint)&local_a4;
  local_a4 = param_1;
  iVar1 = FUN_006379f0(DAT_02913824);
  if (iVar1 != 0) {
    puVar2 = puVar3;
    puVar4 = local_a0;
    for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar2 = &DAT_02913558;
    for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_006378f0();
    puVar3 = local_a0;
    puVar2 = DAT_02913824;
    for (iVar1 = 0x23; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar2 = puVar2 + 1;
    }
  }
  FUN_006279f0(local_a4);
  __security_check_cookie(local_c ^ (uint)&local_a4);
  return;
}

