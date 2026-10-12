/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69f3a0; label: FUN_0069f3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069f3a0(int param_1)

{
  undefined4 uVar1;
  
  if ((((*(int *)(param_1 + 0x148) == 0) || (*(int *)(param_1 + 0x1c) == 0)) &&
      (*(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) < 0x1001)) &&
     ((*(int *)(param_1 + 0x1c) < 0xff &&
      ((*(int *)(param_1 + 0x1c) == 0 || (*(int *)(param_1 + 0x14c) != 0)))))) {
    return 0;
  }
  uVar1 = FUN_0069f190();
  return uVar1;
}

