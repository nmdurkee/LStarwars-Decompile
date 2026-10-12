/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x609f20; label: FUN_00609f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00609f20(uint param_1,int param_2)

{
  int *in_ECX;
  
  *in_ECX = 0;
  if (((param_2 == 0) || (param_1 < *(uint *)(param_2 + 4))) || (*(uint *)(param_2 + 8) < param_1))
  {
    FUN_006e9fe6();
  }
  *in_ECX = param_2;
  in_ECX[1] = param_1;
  return;
}

