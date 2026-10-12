/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x4507b0; label: FUN_004507b0
 */

undefined4
FUN_004507b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  undefined1 uVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  float10 fVar5;
  int local_1c;
  float local_18;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_10 = 0.0;
  local_18 = 0.0;
  iVar4 = 0;
  pfVar3 = (float *)0x0;
  local_c = 1e+09;
  local_8 = 1e+09;
  uVar1 = 1;
  local_4 = 1e+09;
  local_1c = 0;
  if (param_6 == 0) {
    return 1;
  }
  if (0 < param_5) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"name=");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"playcount=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"repdelay=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"startdelay=");
            if (iVar2 == 0) {
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_0075785c);
              if (iVar2 == 0) {
                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757858);
                if (iVar2 == 0) {
                  iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_00757854);
                  if (iVar2 == 0) {
                    iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character_pos=");
                    if (iVar2 != 0) {
                      iVar2 = FUN_00440120(param_1,iVar2 + 0xe);
                      pfVar3 = (float *)(iVar2 + 0x80);
                    }
                  }
                  else {
                    fVar5 = (float10)FUN_005147c0(param_2,iVar2 + 2);
                    local_4 = (float)fVar5;
                  }
                }
                else {
                  fVar5 = (float10)FUN_005147c0(param_2,iVar2 + 2);
                  local_8 = (float)fVar5;
                }
              }
              else {
                fVar5 = (float10)FUN_005147c0(param_2,iVar2 + 2);
                local_c = (float)fVar5;
              }
            }
            else {
              fVar5 = (float10)FUN_005147c0(param_2,iVar2 + 0xb);
              local_10 = (float)fVar5;
            }
          }
          else {
            fVar5 = (float10)FUN_005147c0(param_2,iVar2 + 9);
            local_18 = (float)fVar5;
          }
        }
        else {
          FUN_005147c0(param_2,iVar2 + 10);
          uVar1 = FUN_006e6b90();
        }
      }
      else {
        local_1c = iVar2 + 5;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5);
    if (pfVar3 != (float *)0x0) goto LAB_00450997;
  }
  if (((local_c != 1e+09) && (local_8 != 1e+09)) && (local_4 != 1e+09)) {
    pfVar3 = &local_c;
  }
LAB_00450997:
  if (local_1c != 0) {
    FUN_005487c0(local_1c,0xffffffff,local_10,uVar1,local_18,pfVar3);
  }
  return 1;
}

