/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x465510; label: FUN_00465510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465510(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar3 * 4),&DAT_00758a60);
      if (iVar1 != 0) {
        iVar2 = FUN_004f1ff0("Name=");
        iVar2 = iVar2 + iVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
    if ((iVar2 != 0) && (iVar2 = FUN_005756c0(PTR_DAT_00802c54,iVar2), iVar2 != 0)) {
      FUN_00575c20(PTR_DAT_00802c54,iVar2,1);
    }
  }
  return;
}

