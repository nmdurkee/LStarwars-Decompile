/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57ce40; label: FUN_0057ce40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0057ce40(void)

{
  int in_EAX;
  
  DAT_00951be0 = 1;
  DAT_00951c68 = *(uint *)(in_EAX + 0x50) & 2;
  _DAT_00951bf8 = *(uint *)(in_EAX + 0x50) & 4;
  DAT_00951be8 = in_EAX;
  FUN_00656e40((int)*(char *)(in_EAX + 0xf3));
  _DAT_00925058 = 0;
  _DAT_009250ac = 0;
  FUN_006df320(1);
  return;
}

