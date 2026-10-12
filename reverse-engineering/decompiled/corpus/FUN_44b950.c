/* Ghidra analysis pseudocode, not original source.
 * ev_85221e19b589e64a8fe755bb04b61125e19a0862eea90b9888a564ab90d68d8b
 * Entry: 0x44b950; label: FUN_0044b950
 */

undefined4
FUN_0044b950(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  int local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = 0.0;
  local_1c = -1;
  local_8 = 0.0;
  local_4 = 0.0;
  if ((param_6 != 0) && (iVar2 = 0, 0 < param_5)) {
    do {
      iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_0075782c);
      if (iVar1 == 0) {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757c64);
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757c60);
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757c5c);
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_0075785c);
              if (iVar1 == 0) {
                iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757858);
                if (iVar1 == 0) {
                  iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),&DAT_00757854);
                  if (iVar1 == 0) {
                    iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"character=");
                    if ((iVar1 != 0) && (iVar1 = FUN_00440120(param_1,iVar1 + 10), iVar1 != 0)) {
                      local_18 = *(float *)(iVar1 + 0x80);
                      local_14 = *(float *)(iVar1 + 0x84);
                      local_10 = *(float *)(iVar1 + 0x88);
                    }
                  }
                  else {
                    fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 2);
                    local_10 = (float)fVar3;
                  }
                }
                else {
                  fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 2);
                  local_14 = (float)fVar3;
                }
              }
              else {
                fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 2);
                local_18 = (float)fVar3;
              }
            }
            else {
              fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 3);
              local_4 = (float)fVar3;
            }
          }
          else {
            fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 3);
            local_8 = (float)fVar3;
          }
        }
        else {
          fVar3 = (float10)FUN_005147c0(param_2,iVar1 + 3);
          local_c = (float)fVar3;
        }
      }
      else {
        local_1c = FUN_0064afd0(iVar1 + 5);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_5);
    if (local_1c != -1) {
      FUN_005b37d0(&local_18,&local_18,&local_c);
      FUN_0064b370(local_1c,&local_18,1);
    }
  }
  return 1;
}

