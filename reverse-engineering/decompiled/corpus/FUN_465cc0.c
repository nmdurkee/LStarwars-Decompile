/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x465cc0; label: FUN_00465cc0
 */

void FUN_00465cc0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = -1;
  bVar1 = true;
  if (0 < param_4) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),&DAT_00757c4c);
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"name=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_3 + iVar4 * 4),"FALSE");
          if (iVar2 != 0) {
            bVar1 = false;
          }
        }
        else {
          iVar2 = FUN_0053f7e0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar2 + 5);
          if (iVar2 != 0) {
            iVar3 = (iVar2 - **(int **)(PTR_DAT_00802c54 + 0x2988)) / 0x13c;
          }
        }
      }
      else {
        FUN_004f28e0(iVar2 + 3);
        iVar3 = FUN_006e6b90();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_4);
    if (!bVar1) {
      FUN_00541460(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar3);
      return;
    }
  }
  FUN_00541430(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar3);
  return;
}

