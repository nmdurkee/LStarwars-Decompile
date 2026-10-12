/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44d470; label: FUN_0044d470
 */

undefined4
FUN_0044d470(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_4;
  
  iVar3 = 0;
  uVar2 = 0xffffffff;
  local_4 = 0;
  if (param_6 != 0) {
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),&DAT_00757cf4);
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"ignore_done_flag");
          if (iVar1 != 0) {
            local_4 = 1;
          }
        }
        else {
          FUN_005147c0(param_2,iVar1 + 3);
          uVar2 = FUN_006e6b90();
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    FUN_00576910(uVar2,0,local_4);
  }
  return 1;
}

