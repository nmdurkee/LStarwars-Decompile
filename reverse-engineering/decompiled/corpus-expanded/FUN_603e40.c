/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x603e40; label: FUN_00603e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603e40(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (PTR_DAT_0080e864 != &DAT_0280c478) {
    puVar2 = &DAT_009736e8;
    puVar3 = (undefined4 *)PTR_DAT_0080e864;
    for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    *(int *)(PTR_DAT_0080e864 + 0x78) = (int)DAT_009868cc;
    PTR_DAT_0080e864 = PTR_DAT_0080e864 + 0x7c;
    return;
  }
  FUN_005f7490();
  return;
}

