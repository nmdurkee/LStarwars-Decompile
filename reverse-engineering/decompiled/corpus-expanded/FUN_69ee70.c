/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69ee70; label: FUN_0069ee70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069ee70(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    if ((void *)*param_1 != (void *)0x0) {
      _free((void *)*param_1);
    }
    if ((void *)param_1[4] != (void *)0x0) {
      _free((void *)param_1[4]);
    }
    if ((void *)param_1[5] != (void *)0x0) {
      _free((void *)param_1[5]);
    }
    _memset(param_1,0,0x168);
  }
  return 0;
}

