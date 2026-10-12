/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4ef800; label: FUN_004ef800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef800(uint param_1)

{
  uint *in_EAX;
  
  *in_EAX = *in_EAX & 0x80000000 | param_1;
  return;
}

