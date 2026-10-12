/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x548780; label: FUN_00548780
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

