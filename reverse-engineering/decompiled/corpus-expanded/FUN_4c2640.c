/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c2640; label: FUN_004c2640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004c2640(int param_1,int param_2)

{
  return *(uint *)(param_2 * 0x74 + 100 + param_1) <= DAT_0086e4dc;
}

