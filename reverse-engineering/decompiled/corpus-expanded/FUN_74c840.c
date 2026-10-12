/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74c840; label: FUN_0074c840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074c840(uint param_1,int param_2)

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

