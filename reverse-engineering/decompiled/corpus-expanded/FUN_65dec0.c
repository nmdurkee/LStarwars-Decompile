/* Ghidra pseudocode, not original source.
 * ev_b07f36f396508f1f1c6b60e4fa7f99c8658995938fec5aefc7408e7826e0de77
 * Entry: 0x65dec0; label: FUN_0065dec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065dec0(void)

{
  int iVar1;
  
  FUN_00621140();
  FUN_0065d990();
  if (DAT_02947c14 != -1) {
    iVar1 = DAT_02947c14 * 0x44;
    FUN_0065bf70(*(undefined4 *)(&DAT_02947d9c + iVar1),*(undefined4 *)(&DAT_02947da0 + iVar1),
                 *(undefined4 *)(&DAT_02947da4 + iVar1),0x3e000000,0xff80ffff,DAT_02947c9c);
  }
  if (DAT_02962954 != 0) {
    FUN_00626b50(DAT_02962954);
  }
  return;
}

