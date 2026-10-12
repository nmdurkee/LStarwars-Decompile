/* Ghidra pseudocode, not original source.
 * ev_6fa6af6f6c20542b4b3f476ed9727be59ab920ff8cd58abbde73c8c49552840b
 * Entry: 0x5caa70; label: FUN_005caa70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x005caa85) */

float10 FUN_005caa70(void)

{
  uint in_EAX;
  char in_CL;
  
  return (float10)((float)(in_EAX >> (in_CL * '\x06' & 0x1fU) & 0x3f) * 0.01587302);
}

