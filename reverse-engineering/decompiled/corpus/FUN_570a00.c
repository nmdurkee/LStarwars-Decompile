/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x570a00; label: FUN_00570a00
 */

void FUN_00570a00(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined **ppuVar3;
  undefined *local_50 [6];
  undefined4 local_38;
  code *local_c;
  undefined1 local_1;
  
  puVar2 = &DAT_00802cd8;
  ppuVar3 = local_50;
  for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
    *ppuVar3 = (undefined *)*puVar2;
    puVar2 = puVar2 + 1;
    ppuVar3 = ppuVar3 + 1;
  }
  local_50[0] = DAT_00926c34;
  if (DAT_00926c34 == (undefined *)0x0) {
    local_50[0] = PTR_DAT_0080233c;
  }
  local_50[3] = (undefined *)0x3f19999a;
  local_50[1] = (undefined *)param_1;
  local_38 = 0x40083;
  local_1 = 4;
  local_c = FUN_005706b0;
  FUN_00560b60(local_50);
  return;
}

