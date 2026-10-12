/* Ghidra pseudocode, not original source.
 * ev_e1a2c2f5e90166cb5ef7597416632d6b9968be44632f575ffe69a13c5b8ac55c
 * Entry: 0x55f2c0; label: FUN_0055f2c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055f2c0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((*(uint *)(param_1 + 0xf0) & 1) == 0) {
    if ((*(uint *)(param_1 + 0xf0) & 2) == 0) {
      return 0;
    }
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  iVar1 = (&DAT_0093d7f0)[iVar1];
  iVar2 = FUN_0056e0f0(2);
  if ((iVar2 == 0) && ((iVar1 == 0 || (*(float *)(iVar1 + 0xdec) <= 0.0)))) {
    return 0;
  }
  return 1;
}

