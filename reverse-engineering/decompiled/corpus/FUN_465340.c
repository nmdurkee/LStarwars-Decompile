/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x465340; label: FUN_00465340
 */

void FUN_00465340(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar3 = 0;
  local_4 = 0;
  if (DAT_00951b50 != 0) {
    return;
  }
  iVar4 = 0;
  iVar1 = 0;
  if (0 < param_4) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"cutscene=");
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"newlevel=");
        if (iVar1 != 0) {
          iVar2 = FUN_004f1ff0("newlevel=");
          local_4 = FUN_00578da0(iVar1 + iVar2,0);
        }
      }
      else {
        iVar3 = FUN_004f1ff0("cutscene=");
        iVar3 = iVar3 + iVar1;
      }
      iVar4 = iVar4 + 1;
      iVar1 = local_4;
    } while (iVar4 < param_4);
  }
  if (DAT_0093b2a4 == 0) {
    if (iVar3 != 0) {
      iVar3 = FUN_0057cd30(0,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab0),iVar3,1);
      if (iVar3 != 0) {
        return;
      }
      if (DAT_0093b2a4 != 0) goto LAB_00465418;
    }
    if (iVar1 != 0) {
      FUN_0057a580((int)*(short *)(iVar1 + 0x62));
      return;
    }
  }
LAB_00465418:
  FUN_0057a5b0(PTR_DAT_00802c54);
  return;
}

