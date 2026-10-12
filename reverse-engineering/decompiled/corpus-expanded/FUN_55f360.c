/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55f360; label: FUN_0055f360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

