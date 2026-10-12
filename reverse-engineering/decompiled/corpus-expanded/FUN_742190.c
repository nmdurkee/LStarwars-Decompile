/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x742190; label: FUN_00742190
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float FUN_00742190(float param_1)

{
  if (param_1 < -16.0) {
    return -16.0;
  }
  if (15.96875 < param_1) {
    param_1 = 15.96875;
  }
  return param_1;
}

