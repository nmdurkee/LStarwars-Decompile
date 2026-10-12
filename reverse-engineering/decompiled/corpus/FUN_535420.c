/* Ghidra analysis pseudocode, not original source.
 * ev_b3428d17d7a525986d1be417305dad2f8f354c51dc50a167d24fd678dc156e11
 * Entry: 0x535420; label: FUN_00535420
 */

undefined4 FUN_00535420(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  float10 fVar5;
  undefined1 local_c [12];
  
  if (((param_3 != 0) && (param_1 != 0)) && (*(int *)(param_1 + 0x138c) != 0)) {
    if ((param_6 != 0) && (iVar4 = 0, 0 < param_5)) {
      do {
        if ((DAT_009238b0 == (code *)0x0) ||
           (iVar2 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar4 * 4),param_3 + 0x13f),
           iVar2 == 0)) {
          iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"ANTICLOCKWISE");
          if (iVar2 == 0) {
            *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffdff;
          }
          else {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"CLOCKWISE");
            if (iVar2 == 0) {
              *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x200;
            }
            else {
              iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"REVERSE");
              if (iVar2 == 0) {
                *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) ^ 0x200;
              }
              else {
                iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"facing");
                if (iVar2 == 0) {
                  *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 1;
                }
                else {
                  iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"can_go_off_path");
                  if (iVar2 == 0) {
                    *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 2;
                  }
                  else {
                    iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"currentdist");
                    if (iVar2 == 0) {
                      *(byte *)(param_2 + 0x68) = *(byte *)(param_2 + 0x68) | 4;
                    }
                    else {
                      fVar5 = (float10)FUN_00514920(param_3,param_2,
                                                    *(undefined4 *)(param_4 + iVar4 * 4));
                      *(float *)(param_3 + 0x180) = (float)fVar5;
                    }
                  }
                }
              }
            }
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if (*(int *)(param_1 + 0x138c) != 0) {
      if ((*(byte *)(param_2 + 0x68) & 4) != 0) {
        fVar5 = (float10)FUN_005bed80(param_3 + 0x14c,
                                      *(int *)(*(int *)(param_1 + 0x138c) + 4) + 0x170,local_c);
        *(float *)(param_3 + 0x180) = (float)fVar5;
      }
      if ((*(byte *)(param_2 + 0x68) & 2) == 0) {
        puVar3 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x138c) + 4) + 0x170);
      }
      else {
        puVar3 = (undefined4 *)(*(int *)(*(int *)(param_1 + 0x138c) + 4) + 0x14c);
      }
      iVar4 = *(int *)(*(int *)(param_1 + 0x138c) + 4);
      uVar1 = *(undefined4 *)(iVar4 + 0x120);
      if (puVar3 != (undefined4 *)0x0) {
        *(undefined4 *)(param_3 + 0x1b4) = *puVar3;
        *(undefined4 *)(param_3 + 0x1b8) = puVar3[1];
        *(undefined4 *)(param_3 + 0x1bc) = puVar3[2];
      }
      if ((undefined4 *)(iVar4 + 0x158) != (undefined4 *)0x0) {
        *(undefined4 *)(param_3 + 0x1cc) = *(undefined4 *)(iVar4 + 0x158);
        *(undefined4 *)(param_3 + 0x1d0) = *(undefined4 *)(iVar4 + 0x15c);
        *(undefined4 *)(param_3 + 0x1d4) = *(undefined4 *)(iVar4 + 0x160);
        *(undefined4 *)(param_3 + 0x1d8) = *(undefined4 *)(iVar4 + 0x164);
        *(undefined4 *)(param_3 + 0x1dc) = *(undefined4 *)(iVar4 + 0x168);
        *(undefined4 *)(param_3 + 0x1e0) = *(undefined4 *)(iVar4 + 0x16c);
      }
      *(undefined4 *)(param_3 + 0x1c0) = uVar1;
      *(undefined4 *)(param_3 + 0x1c4) = *(undefined4 *)(param_3 + 0x180);
      *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffffb | 3;
      if ((*(byte *)(param_2 + 0x68) & 1) != 0) {
        *(undefined4 **)(param_3 + 0x1e4) = puVar3;
      }
    }
    return 0;
  }
  return 1;
}

