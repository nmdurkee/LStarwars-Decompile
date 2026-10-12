/* Ghidra pseudocode, not original source.
 * ev_00f52e189c4008d6734275378e3b7e7cc775b5c4744fc695c4d739e43a001eb2
 * Entry: 0x6341a0; label: FUN_006341a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006341a0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x30) = *param_1;
  *(undefined4 *)(in_ECX + 0x34) = param_1[1];
  *(undefined4 *)(in_ECX + 0x38) = param_1[2];
  *(undefined4 *)(in_ECX + 0x3c) = param_1[3];
  *(undefined4 *)(in_ECX + 0x3c) = 0x3f800000;
  return;
}

