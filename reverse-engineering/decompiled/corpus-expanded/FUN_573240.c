/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x573240; label: FUN_00573240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00573240(uint *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_10c;
  uint *local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_10c;
  local_108 = param_1;
  if (DAT_00951354 != 0) {
    *param_1 = *param_1 + 3 & 0xfffffffc;
    local_10c = 0;
    iVar5 = DAT_00951354;
    if (0 < DAT_00951360) {
      do {
        iVar4 = 0;
        *(undefined4 *)(iVar5 + 0x98) = 0;
        if ((*(byte *)(iVar5 + 0x7a) & 2) == 0) {
          FUN_004f1f10(local_104,"levels\\");
          FUN_004f1e80(local_104,iVar5);
          FUN_004f1e80(local_104,&DAT_0075a204);
          FUN_004f1e80(local_104,iVar5 + 0x40);
          FUN_004f1e80(local_104,&DAT_0075d39c);
          iVar1 = FUN_004fc860(local_104);
          if (iVar1 != 0) {
            iVar2 = FUN_004fc5b0(iVar1);
            while (iVar2 != 0) {
              iVar2 = FUN_004f7fb0(iVar1);
              if ((((iVar2 != 0) &&
                   (iVar2 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"character"), iVar2 == 0))
                  && (iVar2 = FUN_004f7fb0(iVar1), iVar2 != 0)) &&
                 (((iVar2 = FUN_0055b1c0(*(undefined4 *)(iVar1 + 0x510)), iVar2 != -1 &&
                   (iVar3 = FUN_004f7fb0(iVar1), iVar3 != 0)) &&
                  (iVar3 = FUN_004f8b10(*(undefined4 *)(iVar1 + 0x510),"resident"), iVar3 == 0)))) {
                if (*(int *)(iVar5 + 0x98) == 0) {
                  *(uint *)(iVar5 + 0x98) = *local_108;
                }
                *(short *)(*(int *)(iVar5 + 0x98) + iVar4 * 2) = (short)iVar2;
                iVar4 = iVar4 + 1;
              }
              iVar2 = FUN_004fc5b0(iVar1);
              param_1 = local_108;
            }
            FUN_004fa300(iVar1);
            if (0 < iVar4) {
              *(undefined2 *)(*(int *)(iVar5 + 0x98) + iVar4 * 2) = 0xffff;
              *param_1 = *(int *)(iVar5 + 0x98) + 2 + iVar4 * 2;
            }
          }
        }
        local_10c = local_10c + 1;
        iVar5 = iVar5 + 0x9c;
      } while (local_10c < DAT_00951360);
    }
    *param_1 = *param_1 + 3 & 0xfffffffc;
  }
  __security_check_cookie(local_4 ^ (uint)&local_10c);
  return;
}

