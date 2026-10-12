/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x5356b0; label: FUN_005356b0
 */

undefined4
FUN_005356b0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  float10 fVar6;
  undefined1 local_c [12];
  
  if (param_3 == 0) {
    return 1;
  }
  if ((param_6 != 0) && (iVar5 = 0, 0 < param_5)) {
    do {
      if ((DAT_009238b0 == (code *)0x0) ||
         (iVar3 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar5 * 4),param_3 + 0x13f), iVar3 == 0)
         ) {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"ANTICLOCKWISE");
        if (iVar3 == 0) {
          *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffdff;
        }
        else {
          iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"CLOCKWISE");
          if (iVar3 == 0) {
LAB_00535743:
            *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x200;
          }
          else {
            iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"REVERSE");
            if (iVar3 == 0) {
              *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) ^ 0x200;
            }
            else {
              iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"RANDOM");
              if (iVar3 == 0) {
                fVar6 = (float10)FUN_005b9dd0();
                if ((float10)0.5 <= fVar6) goto LAB_00535743;
                *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffdff;
              }
              else {
                iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"facing");
                if (iVar3 == 0) {
                  *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
                }
                else {
                  iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"can_go_off_path");
                  if (iVar3 == 0) {
                    *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
                  }
                  else {
                    iVar3 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar5 * 4),"currentdist");
                    if (iVar3 == 0) {
                      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 4;
                    }
                    else {
                      fVar6 = (float10)FUN_00514920(param_3,param_2,
                                                    *(undefined4 *)(param_4 + iVar5 * 4));
                      *(float *)(param_3 + 0x180) = (float)fVar6;
                    }
                  }
                }
              }
            }
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
  }
  if ((*(int *)(param_3 + 0xe4) != 0) &&
     (iVar5 = *(int *)(*(int *)(param_3 + 0xe4) + 4), iVar5 != 0)) {
    if ((*(byte *)(param_2 + 0x68) & 4) != 0) {
      fVar6 = (float10)FUN_005bed80(param_3 + 0x14c,iVar5 + 0x170,local_c);
      *(float *)(param_3 + 0x180) = (float)fVar6;
    }
    piVar1 = (int *)(*(int *)(param_3 + 0xe4) + 4);
    iVar5 = *piVar1;
    if ((*(byte *)(param_2 + 0x68) & 2) == 0) {
      puVar4 = (undefined4 *)(iVar5 + 0x170);
    }
    else {
      puVar4 = (undefined4 *)(iVar5 + 0x14c);
    }
    iVar5 = *piVar1;
    uVar2 = *(undefined4 *)(iVar5 + 0x120);
    if (puVar4 != (undefined4 *)0x0) {
      *(undefined4 *)(param_3 + 0x1b4) = *puVar4;
      *(undefined4 *)(param_3 + 0x1b8) = puVar4[1];
      *(undefined4 *)(param_3 + 0x1bc) = puVar4[2];
    }
    if ((undefined4 *)(iVar5 + 0x158) != (undefined4 *)0x0) {
      *(undefined4 *)(param_3 + 0x1cc) = *(undefined4 *)(iVar5 + 0x158);
      *(undefined4 *)(param_3 + 0x1d0) = *(undefined4 *)(iVar5 + 0x15c);
      *(undefined4 *)(param_3 + 0x1d4) = *(undefined4 *)(iVar5 + 0x160);
      *(undefined4 *)(param_3 + 0x1d8) = *(undefined4 *)(iVar5 + 0x164);
      *(undefined4 *)(param_3 + 0x1dc) = *(undefined4 *)(iVar5 + 0x168);
      *(undefined4 *)(param_3 + 0x1e0) = *(undefined4 *)(iVar5 + 0x16c);
    }
    *(undefined4 *)(param_3 + 0x1c0) = uVar2;
    *(undefined4 *)(param_3 + 0x1c4) = *(undefined4 *)(param_3 + 0x180);
    *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffffb | 3;
    if ((*(byte *)(param_2 + 0x68) & 1) != 0) {
      *(undefined4 **)(param_3 + 0x1e4) = puVar4;
    }
  }
  return 0;
}

