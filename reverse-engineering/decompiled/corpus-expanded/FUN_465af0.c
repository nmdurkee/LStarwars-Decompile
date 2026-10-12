/* Ghidra pseudocode, not original source.
 * ev_8835491dd236cf2d19dd2fa5a5f724a0610b648b7dd0bb4146e1223777a8cf17
 * Entry: 0x465af0; label: FUN_00465af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00465af0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_4;
  
  iVar6 = 0;
  iVar5 = 0;
  bVar1 = false;
  local_4 = 0;
  if (0 < param_4) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar6 * 4),"name=");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"BLOWUP");
        if (iVar2 == 0) {
          bVar1 = false;
        }
        else {
          iVar2 = FUN_004f8b10(*(undefined4 *)(param_3 + iVar6 * 4),"TURRET");
          if (iVar2 == 0) {
            bVar1 = true;
          }
          else {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar6 * 4),"damage=");
            if (iVar2 != 0) {
              iVar3 = FUN_004f1ff0("damage=");
              FUN_004f28e0(iVar2 + iVar3);
              local_4 = FUN_006e6b90();
            }
          }
        }
      }
      else {
        iVar5 = FUN_004f1ff0("name=");
        iVar5 = iVar5 + iVar2;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_4);
    if ((iVar5 != 0) && (local_4 != 0)) {
      if (bVar1) {
        if (((bVar1) &&
            (piVar4 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00805e24,
                                          iVar5), piVar4 != (int *)0x0)) && (*piVar4 != 0)) {
          FUN_005ad540(PTR_DAT_00802c54,*piVar4,0,0xffffffff,local_4);
          return;
        }
      }
      else {
        piVar4 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802f54,iVar5);
        if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
          FUN_00567800(*piVar4,1,0xffffffff,local_4,0,1);
        }
      }
    }
  }
  return;
}

