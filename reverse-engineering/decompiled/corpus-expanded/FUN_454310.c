/* Ghidra pseudocode, not original source.
 * ev_b55b7a309ed021766e38758a92fbc8c97c8db4b0d277f859ab4c7f52da556e16
 * Entry: 0x454310; label: FUN_00454310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00454310(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int local_4;
  
  iVar5 = 0;
  uVar4 = 0;
  local_4 = 0;
  if ((param_6 != 0) && (0 < param_5)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"turret=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"controller=");
        if (iVar1 != 0) {
          if ((DAT_00923904 == (code *)0x0) ||
             (puVar3 = (undefined4 *)(*DAT_00923904)(param_1,iVar1 + 0xb),
             puVar3 == (undefined4 *)0x0)) {
            uVar4 = 0;
          }
          else {
            uVar4 = *puVar3;
          }
        }
      }
      else {
        piVar2 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00805e24,
                                     iVar1 + 7);
        if ((piVar2 != (int *)0x0) && (*piVar2 != 0)) {
          local_4 = *piVar2;
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
    if (local_4 != 0) {
      *(undefined4 *)(local_4 + 0xe8) = uVar4;
    }
  }
  return 1;
}

