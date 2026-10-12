/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x609fb0; label: FUN_00609fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00609fb0(int param_1)

{
  uint uVar1;
  int *in_ECX;
  
  if (*in_ECX == 0) {
    FUN_006e9fe6();
  }
  uVar1 = in_ECX[1] + param_1 * 8;
  if ((*(uint *)(*in_ECX + 8) < uVar1) || (uVar1 < *(uint *)(*in_ECX + 4))) {
    FUN_006e9fe6();
  }
  in_ECX[1] = in_ECX[1] + param_1 * 8;
  return;
}

