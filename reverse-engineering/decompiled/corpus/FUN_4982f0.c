/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x4982f0; label: FUN_004982f0
 */

bool FUN_004982f0(void)

{
  int in_EAX;
  
  if ((((in_EAX != 5) && (in_EAX != 0x28)) && (in_EAX != 0x4b)) && (in_EAX != 0x4c)) {
    return in_EAX == 0x74;
  }
  return true;
}

