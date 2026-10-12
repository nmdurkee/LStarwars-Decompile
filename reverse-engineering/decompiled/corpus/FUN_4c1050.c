/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c1050; label: FUN_004c1050
 */

bool FUN_004c1050(void)

{
  int in_EAX;
  int iVar1;
  
  if (in_EAX == DAT_007f17d4) {
    return DAT_0086e4e5 != '\0';
  }
  iVar1 = FUN_00594870();
  return iVar1 != 0;
}

