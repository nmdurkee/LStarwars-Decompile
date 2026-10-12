/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c2ee0; label: FUN_005c2ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c2ee0(int param_1,int param_2)

{
  int in_ECX;
  
  if (*(char *)(param_2 + 0x268) != '\0') {
    return param_1 * 0x380 + 0x2e8 + in_ECX;
  }
  return param_1 * 0x380 + 0x2a4 + in_ECX;
}

