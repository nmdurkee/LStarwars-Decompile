/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x59fdd0; label: FUN_0059fdd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059fdd0(float param_1)

{
  int in_EAX;
  undefined4 *in_ECX;
  
  *in_ECX = *(undefined4 *)(in_EAX + 0x80);
  in_ECX[2] = *(undefined4 *)(in_EAX + 0x88);
  in_ECX[1] = *(float *)(in_EAX + 0x17c) +
              param_1 * (*(float *)(in_EAX + 0x188) - *(float *)(in_EAX + 0x17c));
  return;
}

