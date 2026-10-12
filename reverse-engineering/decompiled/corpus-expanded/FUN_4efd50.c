/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4efd50; label: FUN_004efd50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004efd50(void)

{
  int in_EAX;
  undefined4 in_ECX;
  
  DAT_0091ce60 = in_EAX;
  DAT_00917844 = in_ECX;
  _DAT_0088ab40 = *(undefined4 *)(in_EAX + 8);
  _DAT_0088ab44 = *(undefined4 *)(in_EAX + 0xc);
  DAT_0090fba4 = 0;
  return;
}

