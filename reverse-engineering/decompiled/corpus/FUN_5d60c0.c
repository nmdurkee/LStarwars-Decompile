/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d60c0; label: FUN_005d60c0
 */

void FUN_005d60c0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_009736e8;
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

