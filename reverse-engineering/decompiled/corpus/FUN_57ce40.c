/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57ce40; label: FUN_0057ce40
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

