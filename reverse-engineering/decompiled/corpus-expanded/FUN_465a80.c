/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x465a80; label: FUN_00465a80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465a80(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar3 * 4),"name=");
      if (iVar1 != 0) {
        iVar2 = FUN_004f1ff0("name=");
        iVar2 = iVar2 + iVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  iVar2 = FUN_0055f450(iVar2,0);
  FUN_0057cd30(0,*(undefined4 *)(iVar2 + 0x2ab0));
  return;
}

