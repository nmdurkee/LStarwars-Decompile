/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48a430; label: FUN_0048a430
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048a430(void)

{
  DAT_00951234 = 0;
  if (DAT_00803784 == -1) {
    DAT_00951230 = 0;
  }
  else {
    DAT_00951230 = (uint)(byte)(&DAT_0086e0f9)[DAT_00803784 * 0xc];
  }
  DAT_00951238 = DAT_00951230;
  DAT_00951240 = 0;
  DAT_00951420 = 0;
  DAT_0087b994 = 0;
  DAT_0087b980 = 0;
  DAT_00951224 = 0;
  DAT_0095122c = 0;
  _DAT_00951248 = 0;
  DAT_00951250 = 0;
  _DAT_0095124c = 0;
  _DAT_00951254 = 0;
  DAT_0095123c = 0;
  if (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087afb4) {
    FUN_004e8640();
    return;
  }
  return;
}

