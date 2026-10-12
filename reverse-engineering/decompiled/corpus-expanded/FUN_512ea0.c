/* Ghidra pseudocode, not original source.
 * ev_2ffc02f844b111bcf8c927080cf20237220999a93cf27a25e92d9f9e0dff8274
 * Entry: 0x512ea0; label: FUN_00512ea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined ** FUN_00512ea0(void)

{
  undefined *puVar1;
  int iVar2;
  undefined **ppuVar3;
  
  if (DAT_00922224 != (undefined **)0x0) {
    puVar1 = *DAT_00922224;
    ppuVar3 = DAT_00922224;
    while (puVar1 != (undefined *)0x0) {
      iVar2 = FUN_004f8b10();
      if (iVar2 == 0) {
        return ppuVar3;
      }
      ppuVar3 = ppuVar3 + 3;
      puVar1 = *ppuVar3;
    }
  }
  ppuVar3 = &PTR_s_PreviousResult_00801768;
  puVar1 = PTR_s_PreviousResult_00801768;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      return (undefined **)0x0;
    }
    iVar2 = FUN_004f8b10();
    if (iVar2 == 0) break;
    ppuVar3 = ppuVar3 + 3;
    puVar1 = *ppuVar3;
  }
  return ppuVar3;
}

