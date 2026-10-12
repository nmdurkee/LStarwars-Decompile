/* Ghidra pseudocode, not original source.
 * ev_f37daf0a5dc4028c7f86144cc3857775ddac8ffa4172b341c81015a8a14d5d27
 * Entry: 0x5c2170; label: FUN_005c2170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005c2170(void)

{
  int *in_EAX;
  int *in_ECX;
  
  if ((*in_ECX == *in_EAX) && (in_ECX[1] == in_EAX[1])) {
    return 1;
  }
  return 0;
}

