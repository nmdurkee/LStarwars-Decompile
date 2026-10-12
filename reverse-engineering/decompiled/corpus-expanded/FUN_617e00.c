/* Ghidra pseudocode, not original source.
 * ev_34bcce3fa22e23c2ab9571957a9a402fab0be6cbc2b7d858acbf9422b22923c6
 * Entry: 0x617e00; label: FUN_00617e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617e00(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = DAT_02912e78;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_00603cc0();
  return;
}

