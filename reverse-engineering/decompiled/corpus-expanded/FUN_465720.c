/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x465720; label: FUN_00465720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465720(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  iVar5 = 0;
  bVar1 = true;
  bVar2 = false;
  if (0 < param_4) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar6 * 4),&DAT_00758a60);
      if (iVar3 == 0) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"BACKWARD");
        if (iVar3 == 0) {
          bVar1 = false;
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"FORWARD");
          if (iVar3 == 0) {
            bVar1 = true;
          }
          else {
            iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),&DAT_00757e88);
            if (iVar3 == 0) {
              bVar2 = true;
            }
          }
        }
      }
      else {
        iVar5 = FUN_004f1ff0(&DAT_00758a60);
        iVar5 = iVar5 + 1 + iVar3;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_4);
    if (((iVar5 != 0) &&
        (piVar4 = (int *)FUN_0055a020(*param_1,DAT_00805ebc,iVar5), piVar4 != (int *)0x0)) &&
       (iVar5 = *piVar4, iVar5 != 0)) {
      if (bVar1) {
        if (!bVar2) {
          FUN_005a1030(*(undefined4 *)(iVar5 + 0x20),0x3f800000,0);
          return;
        }
        FUN_005a11f0(*(undefined4 *)(iVar5 + 0x20));
        return;
      }
      if (bVar2) {
        FUN_005a1230(*(undefined4 *)(iVar5 + 0x20));
        return;
      }
      FUN_005a1030(*(undefined4 *)(iVar5 + 0x20),0xbf800000,0);
    }
  }
  return;
}

