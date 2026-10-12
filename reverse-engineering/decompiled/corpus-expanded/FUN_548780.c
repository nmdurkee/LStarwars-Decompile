/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548780; label: FUN_00548780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548780(void)

{
  int iVar1;
  
  _memset(&DAT_00924af8,0,0x200);
  DAT_00924adc = 0;
  iVar1 = 0x20;
  do {
    iVar1 = iVar1 + -1;
    _DAT_00924af8 = 0xffff;
  } while (iVar1 != 0);
  return;
}

