/* Ghidra analysis pseudocode, not original source.
 * ev_afde76c9da02194678eff0a54ce656dfadfb8e6d7e607c68c4e1b37896a76ad5
 * Entry: 0x5fd1c0; label: FUN_005fd1c0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fd1c0(void)

{
  _memset(&DAT_009868a0,0,0x1a4);
  FUN_005b44e0(&DAT_0280d340);
  FUN_005b44e0(&DAT_0097baf0);
  _DAT_0080e190 = 0x3f800000;
  _DAT_009868c0 = _DAT_009868c0 + 1;
  _DAT_009868ce = _DAT_009868ce + 1;
  _DAT_00986a0c = 0;
  _DAT_00986a08 = 0;
  FUN_005fcc80();
  return;
}

