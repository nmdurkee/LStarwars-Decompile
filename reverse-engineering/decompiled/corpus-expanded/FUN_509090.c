/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x509090; label: FUN_00509090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00509090(int param_1)

{
  int in_ECX;
  
  return param_1 * 0x10 + *(int *)(in_ECX + 0x61c);
}

