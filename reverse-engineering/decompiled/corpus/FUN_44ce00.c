/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44ce00; label: FUN_0044ce00
 */

undefined4
FUN_0044ce00(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = -1;
  bVar1 = true;
  if (param_6 == 0) {
    return 1;
  }
  iVar4 = 0;
  if (0 < param_5) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757c4c);
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"name=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"FALSE");
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
        FUN_005147c0(param_2,iVar2 + 3);
        iVar3 = FUN_006e6b90();
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5);
    if (!bVar1) {
      FUN_00541460(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar3);
      return 1;
    }
  }
  FUN_00541430(*(undefined4 *)(PTR_DAT_00802c54 + 0x2988),iVar3);
  return 1;
}

