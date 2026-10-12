/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f360; label: FUN_0055f360
 */

undefined4 FUN_0055f360(int param_1)

{
  uint uVar1;
  
  if ((((*(byte *)(param_1 * 0x120 + 0x90 + DAT_0093b284) & 0x10) == 0) &&
      (uVar1 = *(uint *)(param_1 * 0x4c + 4 + DAT_0093b274),
      (undefined *)(uVar1 & 0x1000010) != &DAT_01000010)) && ((uVar1 & 0x40088) != 0)) {
    return 1;
  }
  return 0;
}

