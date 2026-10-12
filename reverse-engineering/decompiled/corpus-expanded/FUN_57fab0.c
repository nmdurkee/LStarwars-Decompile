/* Ghidra pseudocode, not original source.
 * ev_148a09dc694c3f4e6090ec8593a8f5c40e6398f75b0d17d245a3886ccb65c6ec
 * Entry: 0x57fab0; label: FUN_0057fab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057fab0(void)

{
  int in_EAX;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_EAX + 0x88);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_EAX + 0x8c);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_EAX + 0x90);
  if ((*(uint *)(in_EAX + 0xf0) & 0x200) == 0) {
    local_c = 0;
    local_8 = 0;
    local_4 = *(float *)(in_EAX + 0xd8) + *(float *)(in_EAX + 0xd8);
    FUN_005b3200(&local_c,&local_c,in_EAX + 8);
    FUN_005b3800();
    FUN_005b37d0(in_ECX + 0x18,(undefined4 *)(in_EAX + 0x88),&local_c);
  }
  return;
}

