/* Ghidra pseudocode, not original source.
 * ev_6c627fdc098d062fc30e762de358fb2844ba9203c9bb8f32313df93bcbce3bd5
 * Entry: 0x69ecc0; label: FUN_0069ecc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_0069ecc0(int *param_1)

{
  return *(byte *)(*param_1 + 5) & 2;
}

