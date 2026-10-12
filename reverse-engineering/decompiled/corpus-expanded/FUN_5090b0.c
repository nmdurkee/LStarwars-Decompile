/* Ghidra pseudocode, not original source.
 * ev_0b3cdb0849a5c3a2f544331fa814d8282bd684db9c1ec6ffa505f1c54b54b4d0
 * Entry: 0x5090b0; label: FUN_005090b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005090b0(int param_1)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x63c) != '\0') && (*(int *)(in_ECX + 0x640 + param_1 * 4) != -1)) {
    return 1;
  }
  return 0;
}

