/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69eec0; label: FUN_0069eec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069eec0(void *param_1)

{
  if (param_1 != (void *)0x0) {
    FUN_0069ee70(param_1);
    _free(param_1);
  }
  return 0;
}

