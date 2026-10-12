/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x464480; label: FUN_00464480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00464480(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = 0;
  uVar2 = 1;
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar3 * 4),"name=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar3 * 4),"FALSE");
        if (iVar1 != 0) {
          uVar2 = 0;
        }
      }
      else {
        FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&local_c,iVar1 + 5,1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_4);
  }
  iVar3 = FUN_005cfac0(&local_c);
  if (iVar3 != 0) {
    FUN_005cfc00(&local_c,uVar2);
  }
  return;
}

