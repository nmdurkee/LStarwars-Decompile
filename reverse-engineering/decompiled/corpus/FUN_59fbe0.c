/* Ghidra analysis pseudocode, not original source.
 * ev_619d50b6392102a54c9e38c540a3f8930ee6fdfe94aeb342acdefb90820d232e
 * Entry: 0x59fbe0; label: FUN_0059fbe0
 */

void FUN_0059fbe0(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  int local_4;
  
  if (DAT_00951b50 == 0) {
    bVar1 = *(byte *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 200);
    uVar2 = (uint)(char)bVar1;
    local_4 = 0;
    if (0 < DAT_00956608) {
      pbVar6 = &DAT_00956460;
      do {
        if ((param_1 != 0) || (*pbVar6 != uVar2)) {
          pbVar6[-0xffffffff00000028] = 0;
          pbVar6[-0xffffffff00000027] = 0;
          pbVar6[-0xffffffff00000026] = 0;
          pbVar6[-0xffffffff00000025] = 0;
        }
        if (pbVar6[2] != 0xff) {
          *pbVar6 = bVar1;
        }
        if (pbVar6[-1] == uVar2) {
          if (*(int *)(pbVar6 + -0x28) == 0) {
            if (pbVar6[-2] == 0xff) {
              if (*pbVar6 == uVar2) {
                uVar3 = FUN_0043d890((int)*(short *)(pbVar6 + -4),pbVar6 + -0x24,
                                     *(undefined4 *)(pbVar6 + -0x18),pbVar6 + -0x14,0,0,1,0,0,0,0);
                *(undefined4 *)(pbVar6 + -0x28) = uVar3;
              }
            }
            else {
              iVar4 = 0;
              iVar5 = DAT_0093d504;
              if (0 < DAT_0093d500) {
                do {
                  if (*(byte *)(iVar5 + 0x400) == pbVar6[-2]) {
                    *(int *)(pbVar6 + -0x28) = iVar5;
                    break;
                  }
                  iVar4 = iVar4 + 1;
                  iVar5 = iVar5 + 0x10d8;
                } while (iVar4 < DAT_0093d500);
              }
            }
          }
          if ((*(int *)(pbVar6 + -0x28) != 0) && (*pbVar6 != uVar2)) {
            FUN_004364e0(*(int *)(pbVar6 + -0x28),5,0);
            pbVar6[-0xffffffff00000028] = 0;
            pbVar6[-0xffffffff00000027] = 0;
            pbVar6[-0xffffffff00000026] = 0;
            pbVar6[-0xffffffff00000025] = 0;
          }
        }
        else if ((*pbVar6 == uVar2) && (*(int *)(pbVar6 + -0x28) == 0)) {
          uVar3 = FUN_0043d890((int)*(short *)(pbVar6 + -4),pbVar6 + -0x24,
                               *(undefined4 *)(pbVar6 + -0x18),pbVar6 + -0x14,0,0,1,0,0,0,0);
          *(undefined4 *)(pbVar6 + -0x28) = uVar3;
        }
        if (*(int *)(pbVar6 + -0x28) != 0) {
          *(byte *)(*(int *)(pbVar6 + -0x28) + 0x107f) = pbVar6[1];
          if ((pbVar6[2] == 0xff) || (iVar5 = (&DAT_0093d7f0)[pbVar6[2]], iVar5 == 0)) {
            FUN_0055d720(*(undefined4 *)(pbVar6 + -0x28),pbVar6 + -0x24,
                         *(undefined4 *)(pbVar6 + -0x18),0,1);
          }
          else {
            *(undefined1 *)(*(int *)(pbVar6 + -0x28) + 0x28b) = 0;
            *(uint *)(*(int *)(pbVar6 + -0x28) + 0x1fc) =
                 *(uint *)(*(int *)(pbVar6 + -0x28) + 0x1fc) | 0x1000;
            *(uint *)(*(int *)(pbVar6 + -0x28) + 0x1fc) =
                 *(uint *)(*(int *)(pbVar6 + -0x28) + 0x1fc) | 1;
            *(undefined1 *)(*(int *)(pbVar6 + -0x28) + 0x406) = 2;
            FUN_0055d720(*(undefined4 *)(pbVar6 + -0x28),iVar5 + 0x5c,*(undefined2 *)(iVar5 + 0x27a)
                         ,iVar5 + 0x420,1);
            FUN_0041b0a0(iVar5);
            FUN_00488730(iVar5,*(undefined4 *)(pbVar6 + -0x28),0,1);
          }
        }
        local_4 = local_4 + 1;
        pbVar6 = pbVar6 + 0x2c;
      } while (local_4 < DAT_00956608);
    }
  }
  return;
}

