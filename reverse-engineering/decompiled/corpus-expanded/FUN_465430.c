/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x465430; label: FUN_00465430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465430(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar3 = 0;
  iVar4 = 0;
  local_4 = 0;
  iVar1 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"level=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"cutscene=");
        if (iVar1 != 0) {
          iVar3 = FUN_004f1ff0("cutscene=");
          iVar3 = iVar3 + iVar1;
        }
      }
      else {
        iVar2 = FUN_004f1ff0("level=");
        local_4 = FUN_00578da0(iVar1 + iVar2,0);
      }
      iVar4 = iVar4 + 1;
      iVar1 = local_4;
    } while (iVar4 < param_4);
  }
  if ((((DAT_0093b2a4 != 0) || (iVar3 == 0)) ||
      (iVar3 = FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),iVar3,0), iVar3 == 0)) &&
     ((iVar1 != 0 && (DAT_00951b50 == 0)))) {
    FUN_0057a580((int)*(short *)(iVar1 + 0x62));
  }
  return;
}

