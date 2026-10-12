/* Ghidra analysis pseudocode, not original source.
 * ev_fba68665c2ecb02d4c13d026ba12834cd95aaa1020801387b253bb991a5bde4e
 * Entry: 0x4e2300; label: FUN_004e2300
 */

undefined4 FUN_004e2300(void)

{
  if ((*(int *)(PTR_DAT_00802c54 + 300) == 0) || (*(int *)(PTR_DAT_00802c54 + 300) != DAT_0087af6c))
  {
    return 0;
  }
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b10c) {
    if (((DAT_00951be0 == 0) && (PTR_DAT_008021b4[1] != '\x05')) && (PTR_DAT_008021b4[1] != '\x06'))
    {
      return 0;
    }
  }
  else {
    if (*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b114) {
      return 0;
    }
    if (DAT_00951be0 != 0) {
      return 0;
    }
    if (PTR_DAT_008021b4[1] == '\x1e') {
      return 0;
    }
  }
  return 1;
}

