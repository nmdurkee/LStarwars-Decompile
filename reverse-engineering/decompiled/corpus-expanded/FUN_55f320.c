/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55f320; label: FUN_0055f320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055f320(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0056e0f0(0x400);
  if ((iVar1 == 0) && ((param_1 == 0 || (*(float *)(param_1 + 0xdec) <= 0.0)))) {
    return 0;
  }
  return 1;
}

