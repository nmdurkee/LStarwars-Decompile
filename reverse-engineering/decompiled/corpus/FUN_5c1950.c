/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c1950; label: FUN_005c1950
 */

void FUN_005c1950(void)

{
  uint *in_EAX;
  uint *in_ECX;
  
  *in_ECX = *in_EAX & 0x7fffffff;
  in_ECX[1] = in_EAX[1] & 0x7fffffff;
  in_ECX[2] = in_EAX[2] & 0x7fffffff;
  in_ECX[3] = in_EAX[3] & 0x7fffffff;
  return;
}

