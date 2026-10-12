/* Ghidra pseudocode, not original source.
 * ev_8d558f2b7d37f7c2d88d0d36eae1cf7a4b5788ac1ea6cb26aea78645de7b2f49
 * Entry: 0x60bc40; label: FUN_0060bc40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060bc40(uint param_1,int param_2)

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

