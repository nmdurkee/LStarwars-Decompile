/* Ghidra pseudocode, not original source.
 * ev_184291d84d57a0e0f71d3c8a05fa8a71135e786a990f62c870cdb26b01607f61
 * Entry: 0x60f4c0; label: FUN_0060f4c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060f4c0(int *param_1)

{
  int *in_ECX;
  
  *in_ECX = *in_ECX + *param_1;
  in_ECX[1] = in_ECX[1] + param_1[1];
  in_ECX[2] = in_ECX[2] + param_1[2];
  in_ECX[3] = in_ECX[3] + param_1[3];
  return;
}

