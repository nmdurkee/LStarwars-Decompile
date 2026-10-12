/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464360; label: FUN_00464360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00464360(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_4;
  
  iVar3 = 0;
  iVar2 = 0;
  local_4 = 1;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar3 * 4),"effect");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar3 * 4),"FALSE");
        if (iVar1 == 0) {
          local_4 = 0;
        }
      }
      else {
        iVar2 = FUN_004f1ff0("effect");
        iVar2 = iVar2 + 1 + iVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
    if (iVar2 != 0) {
      FUN_005a8280(iVar2,local_4);
      iVar2 = FUN_0055f450(iVar2,local_4);
      FUN_0048a060(*(undefined4 *)(iVar2 + 0x130));
    }
  }
  return;
}

