/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x567130; label: FUN_00567130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00567130(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_128 [71];
  uint local_c;
  
  local_c = DAT_00829570 ^ (uint)local_128;
  puVar2 = param_1;
  puVar3 = local_128;
  for (iVar1 = 0x45; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = param_2;
  for (iVar1 = 0x45; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  puVar2 = local_128;
  for (iVar1 = 0x45; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  __security_check_cookie(local_c ^ (uint)local_128);
  return;
}

