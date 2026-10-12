/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x413230; label: FUN_00413230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00413230(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = (undefined4 *)(param_1 + 0xb8);
  puVar3 = param_2;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_005b5060(param_2,0x8000);
  return;
}

