/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x652010; label: FUN_00652010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00652010(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = true;
  iVar3 = -1;
  iVar2 = FUN_004f7fb0(param_1);
  do {
    if (iVar2 == 0) {
      return;
    }
    iVar2 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
    if (bVar1) {
      if (iVar2 == -1) {
        return;
      }
      iVar3 = FUN_00650c50(iVar2);
      bVar1 = false;
    }
    else {
      iVar2 = FUN_00650dc0(*(undefined4 *)(param_1 + 0x510));
      if ((iVar2 != -1) && (DAT_02962020 != 0x200)) {
        *(short *)(&DAT_02921260 + DAT_02962020 * 2) = (short)iVar2;
        DAT_02962020 = DAT_02962020 + 1;
        *(short *)(&DAT_02920d8a + iVar3 * 8) = *(short *)(&DAT_02920d8a + iVar3 * 8) + 1;
        *(undefined2 *)(&DAT_02920d8c + iVar3 * 8) = 0;
      }
    }
    iVar2 = FUN_004f7fb0(param_1);
  } while( true );
}

