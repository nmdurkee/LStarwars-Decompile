/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5daa80; label: FUN_005daa80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005daa80(int param_1,byte param_2)

{
  *(uint *)(*(int *)(param_1 + 0x110) + 0x74) =
       (uint)param_2 << 5 | *(uint *)(*(int *)(param_1 + 0x110) + 0x74) & 0xffffe01f;
  return *(uint *)(*(int *)(param_1 + 0x110) + 0x74) >> 5;
}

