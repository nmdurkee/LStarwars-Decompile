/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4ef860; label: FUN_004ef860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef860(void)

{
  uint *in_EAX;
  
  *(uint **)((*in_EAX & 0x7fffffff) + 0xc + (int)in_EAX) = in_EAX;
  return;
}

