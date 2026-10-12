/* Ghidra pseudocode, not original source.
 * ev_8bfd975316f8cf2b7f750252451c539d63e4b7da44e3fbde714e6599bb2e7713
 * Entry: 0x5d6240; label: FUN_005d6240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d6240(float *param_1,float param_2,float param_3)

{
  *param_1 = DAT_00966378 * param_2;
  param_1[1] = DAT_0097313c * param_3;
  param_1[2] = 1.0;
  FUN_005b3200();
  return;
}

