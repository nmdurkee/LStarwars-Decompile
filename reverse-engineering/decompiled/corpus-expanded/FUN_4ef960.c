/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4ef960; label: FUN_004ef960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004ef960(void)

{
  uint *in_EAX;
  
  return (*in_EAX & 0x7fffffff) + 0x10 + (int)in_EAX;
}

