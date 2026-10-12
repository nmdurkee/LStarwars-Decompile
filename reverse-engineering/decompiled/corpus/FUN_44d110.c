/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44d110; label: FUN_0044d110
 */

undefined4
FUN_0044d110(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float local_4;
  
  iVar2 = 0;
  local_4 = 0.1;
  if (param_6 != 0) {
    iVar3 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"axis=x");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"axis=y");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"axis=z");
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),&DAT_00757ca8);
              if (iVar1 != 0) {
                fVar4 = (float10)FUN_005147c0(param_2,iVar1 + 5);
                local_4 = (float)fVar4;
              }
            }
            else {
              iVar2 = 2;
            }
          }
          else {
            iVar2 = 1;
          }
        }
        else {
          iVar2 = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
      if ((iVar2 == 2) && (iVar3 = FUN_0054fa60(), iVar3 < 0x8000)) {
        local_4 = -local_4;
      }
    }
    FUN_00549de0(PTR_DAT_008021b4,local_4,iVar2,0);
  }
  return 1;
}

