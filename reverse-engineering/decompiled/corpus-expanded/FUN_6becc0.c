/* Ghidra pseudocode, not original source.
 * ev_22f771e0c18b367a4d7c01bf756cd775085513b89e8d82bf660ad444254c899f
 * Entry: 0x6becc0; label: FUN_006becc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006becc0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 != 0) {
    FUN_005f33b0(in_ECX + 0x18,param_1);
    return;
  }
  uVar1 = FUN_005d0330(in_ECX + 0x18);
  FUN_005f33b0(in_ECX + 0x18,uVar1);
  return;
}

