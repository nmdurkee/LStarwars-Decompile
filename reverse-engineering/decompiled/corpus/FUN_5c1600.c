/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c1600; label: FUN_005c1600
 */

void FUN_005c1600(void)

{
  uint *in_EAX;
  uint *in_ECX;
  
  *in_ECX = *in_EAX & 0x7fffffff;
  in_ECX[1] = in_EAX[1] & 0x7fffffff;
  in_ECX[2] = in_EAX[2] & 0x7fffffff;
  in_ECX[3] = in_EAX[3] & 0x7fffffff;
  return;
}

