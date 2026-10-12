/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57fb30; label: FUN_0057fb30
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

