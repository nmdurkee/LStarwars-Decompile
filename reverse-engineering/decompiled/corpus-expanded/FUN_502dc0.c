/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x502dc0; label: FUN_00502dc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00502dc0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (*(short *)(*(int *)(param_1 + 0x2c) + param_3 * 2) == 10) {
    return *(undefined4 *)(param_2 + param_3 * 4);
  }
  if (*(float *)(param_2 + param_3 * 4) < 0.0) {
    uVar1 = FUN_006e6b90();
    return uVar1;
  }
  uVar1 = FUN_006e6b90();
  return uVar1;
}

