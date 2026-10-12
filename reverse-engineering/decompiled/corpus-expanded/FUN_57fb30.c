/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57fb30; label: FUN_0057fb30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057fb30(void)

{
  int in_EAX;
  ushort local_8 [2];
  undefined2 local_4 [2];
  
  FUN_0054ff40(in_EAX + 0xac,local_8,local_4);
  FUN_005b45f0(in_EAX + 0x48,local_8[0] + 0x4000);
  FUN_005b4f70(in_EAX + 0x48,local_4[0]);
  FUN_005b45f0(in_EAX + 8,local_8[0]);
  FUN_005b4f70(in_EAX + 8,local_4[0]);
  return;
}

