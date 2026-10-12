/* Ghidra analysis pseudocode, not original source.
 * ev_8e6c58f632ba894c996161736f16e550f9c9cdfbb0c94bd06c2a8d698c289bc5
 * Entry: 0x5d4e70; label: FUN_005d4e70
 */

void FUN_005d4e70(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_009718f8;
  for (iVar1 = 0x15; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}

