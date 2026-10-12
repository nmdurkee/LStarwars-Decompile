/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x609ef0; label: FUN_00609ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00609ef0(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == 0) || (*in_ECX != *param_1)) {
    FUN_006e9fe6();
  }
  return in_ECX[1] - param_1[1] >> 3;
}

