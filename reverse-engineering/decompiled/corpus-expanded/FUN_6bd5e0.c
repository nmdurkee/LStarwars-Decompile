/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd5e0; label: FUN_006bd5e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bd5e0(undefined4 param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_40 [16];
  
  puVar1 = (undefined4 *)(**(code **)(*in_ECX + 0x18))();
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = auStack_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_005b4900(auStack_40,param_1);
    return;
  }
  FUN_005b4500(auStack_40,param_1);
  return;
}

