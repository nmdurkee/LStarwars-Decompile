/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x465590; label: FUN_00465590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465590(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_8;
  uint local_4;
  
  iVar7 = 0;
  iVar6 = 0;
  bVar1 = true;
  bVar2 = false;
  local_4 = 0;
  local_8 = 0;
  if (0 < param_4) {
    do {
      iVar3 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar7 * 4),&DAT_00758a60);
      if (iVar3 == 0) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar7 * 4),"BACKWARD");
        if (iVar3 == 0) {
          bVar1 = false;
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar7 * 4),"FORWARD");
          if (iVar3 == 0) {
            bVar1 = true;
          }
          else {
            iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar7 * 4),&DAT_00757e88);
            if (iVar3 == 0) {
              bVar2 = true;
            }
            else {
              iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar7 * 4),"STAYOPEN");
              if (iVar3 == 0) {
                local_4 = 1;
              }
              else {
                iVar3 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar7 * 4),"STAYSHUT");
                if (iVar3 == 0) {
                  iVar6 = 1;
                }
              }
            }
          }
        }
      }
      else {
        iVar4 = FUN_004f1ff0(&DAT_00758a60);
        local_8 = iVar4 + 1 + iVar3;
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_4);
    if (((local_8 != 0) &&
        (piVar5 = (int *)FUN_0055a020(*param_1,DAT_00802644,local_8), piVar5 != (int *)0x0)) &&
       (iVar7 = *piVar5, iVar7 != 0)) {
      if (bVar1) {
        if (bVar2) {
          FUN_00558990();
        }
        else {
          FUN_00557960();
        }
      }
      else if (bVar2) {
        FUN_00558970();
      }
      else {
        FUN_005579d0(iVar7);
      }
      *(uint *)(iVar7 + 0x9c) = (iVar6 * 2 | local_4) * 4 | *(uint *)(iVar7 + 0x9c) & 0xfffffff3;
    }
  }
  return;
}

