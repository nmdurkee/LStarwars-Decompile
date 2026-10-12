/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44cbf0; label: FUN_0044cbf0
 */

undefined4
FUN_0044cbf0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  local_4 = 1;
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    iVar4 = *piVar2;
    if (param_6 != 0) {
      iVar3 = 0;
      iVar1 = 1;
      if (0 < param_5) {
        do {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"FALSE");
            if (iVar1 == 0) {
              local_4 = 0;
            }
          }
          else if ((DAT_00923904 == (code *)0x0) ||
                  (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
            iVar4 = 0;
          }
          else {
            iVar4 = *piVar2;
          }
          iVar3 = iVar3 + 1;
          iVar1 = local_4;
        } while (iVar3 < param_5);
      }
      if (iVar4 != 0) {
        *(uint *)(iVar4 + 0xef4) =
             *(uint *)(iVar4 + 0xef4) ^ (iVar1 << 0x19 ^ *(uint *)(iVar4 + 0xef4)) & 0x2000000;
      }
    }
    return 1;
  }
  return 1;
}

