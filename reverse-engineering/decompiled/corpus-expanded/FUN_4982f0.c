/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x4982f0; label: FUN_004982f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004982f0(void)

{
  int in_EAX;
  
  if ((((in_EAX != 5) && (in_EAX != 0x28)) && (in_EAX != 0x4b)) && (in_EAX != 0x4c)) {
    return in_EAX == 0x74;
  }
  return true;
}

