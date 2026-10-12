/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x42df70; label: FUN_0042df70
 */

void FUN_0042df70(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (DAT_007f5db8 < 0) {
    puVar2 = (undefined4 *)(PTR_DAT_008021b4 + 0xb8);
    puVar3 = &DAT_00876648;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_00876648;
    puVar3 = &DAT_00876608;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    DAT_007f5db8 = 0;
  }
  FUN_005d51f0(&DAT_00876608 + DAT_007f5db8 * 0x10);
  DAT_007f5db8 = 1 - DAT_007f5db8;
  puVar2 = (undefined4 *)(PTR_DAT_008021b4 + 0xb8);
  puVar3 = &DAT_00876608 + DAT_007f5db8 * 0x10;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}

