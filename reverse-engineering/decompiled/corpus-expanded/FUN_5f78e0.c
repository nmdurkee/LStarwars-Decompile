/* Ghidra pseudocode, not original source.
 * ev_051ca52d2d0f5927e6fa186b1b96c133d3b61d010079a76ac2917bb13fe5eb00
 * Entry: 0x5f78e0; label: FUN_005f78e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005f78e0(void)

{
  int *in_EAX;
  int *in_ECX;
  
  if ((*in_ECX == *in_EAX) && (in_ECX[1] == in_EAX[1])) {
    return 1;
  }
  return 0;
}

