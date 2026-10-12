/* Ghidra analysis pseudocode, not original source.
 * ev_9c12bf04ecd7f3adbf0375550da3c60080af84bab7b3ceab44ee80aff1422843
 * Entry: 0x5b4c90; label: FUN_005b4c90
 */

void FUN_005b4c90(float *param_1,float param_2)

{
  *param_1 = param_2 * *param_1;
  param_1[1] = param_1[1] * param_2;
  param_1[2] = param_2 * param_1[2];
  return;
}

