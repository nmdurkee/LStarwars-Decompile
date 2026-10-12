/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x650cd0; label: FUN_00650cd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00650cd0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (int)(short)(&DAT_02920d88)[param_1 * 4];
  iVar2 = *(short *)(&DAT_02920d8a + param_1 * 8) + iVar1;
  while( true ) {
    if (iVar2 <= iVar1) {
      return 0;
    }
    if (*(short *)(&DAT_02921260 + iVar1 * 2) == param_2) break;
    iVar1 = iVar1 + 1;
  }
  return 1;
}

