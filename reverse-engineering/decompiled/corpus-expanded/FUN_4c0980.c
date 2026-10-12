/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c0980; label: FUN_004c0980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_004c0980(int *param_1)

{
  return *(byte *)(*param_1 + 0x3c) >> 3 & 1;
}

