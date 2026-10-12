/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x423c30; label: FUN_00423c30
 */

void FUN_00423c30(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  char *_Dest;
  ushort *puVar6;
  short *local_c4;
  int local_bc;
  int local_b8;
  int local_b4 [27];
  int local_48;
  int local_4;
  
  local_b8 = -1;
  if (param_1 != 0) {
    local_c4 = (short *)(param_1 + 0x6c);
    _Dest = (char *)(param_1 + 0x70);
    puVar6 = &DAT_0086e4ec;
    local_bc = 0;
    do {
      if ((param_2 == -1) || (local_bc == param_2)) {
        *_Dest = '\0';
        iVar5 = 0;
        local_4 = 0;
        local_48 = 0;
        local_b4[0] = 0;
        local_b4[1] = 0;
        local_b4[2] = 0;
        local_b4[3] = 0;
        local_b4[4] = 0;
        local_b4[5] = 0;
        local_b4[6] = 0;
        local_b4[7] = 0;
        local_b4[8] = 0;
        local_b4[9] = 0;
        local_b4[10] = 0;
        iVar4 = 0;
        do {
          if (0 < *(int *)(param_1 + 0x48 + iVar4 * 4)) {
            if (iVar4 == 0) {
              if ((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)puVar6[1] * 0x28) & 1) == 0) {
LAB_00423d1c:
                iVar2 = *(int *)(param_1 + 0x24 + iVar4 * 4);
                iVar1 = iVar2 + (uint)puVar6[iVar4] * 0x28;
                if (*(char *)(iVar2 + 0x10 + (uint)puVar6[iVar4] * 0x28) != -1) {
                  local_b4[*(char *)(iVar1 + 0x10)] =
                       local_b4[*(char *)(iVar1 + 0x10)] +
                       (int)*(char *)(*(int *)(param_1 + iVar4 * 4) + 6);
                }
                if ((local_48 == 0) && (*(short *)(iVar1 + 10) != 0)) {
                  local_48 = iVar1;
                }
                else if ((local_4 == 0) && (*(short *)(iVar1 + 0xc) != 0)) {
                  local_4 = iVar1;
                }
                else if ((iVar5 == 0) && (*(short *)(iVar1 + 0xe) != 0)) {
                  iVar5 = iVar1;
                }
              }
            }
            else if (((iVar4 != 1) ||
                     ((*(byte *)(*(int *)(param_1 + 0x24) + 0x12 + (uint)*puVar6 * 0x28) & 2) == 0))
                    || ((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)puVar6[1] * 0x28) & 1) !=
                        0)) goto LAB_00423d1c;
          }
          if (((0 < *(int *)(param_1 + 0x4c + iVar4 * 4)) &&
              ((iVar4 != -1 ||
               ((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)puVar6[1] * 0x28) & 1) == 0))))
             && ((iVar4 != 0 ||
                 (((*(byte *)(*(int *)(param_1 + 0x24) + 0x12 + (uint)*puVar6 * 0x28) & 2) == 0 ||
                  ((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)puVar6[1] * 0x28) & 1) != 0)))
                 ))) {
            iVar1 = *(int *)(param_1 + 0x28 + iVar4 * 4) + (uint)puVar6[iVar4 + 1] * 0x28;
            if (*(char *)(iVar1 + 0x10) != -1) {
              local_b4[*(char *)(iVar1 + 0x10)] =
                   local_b4[*(char *)(iVar1 + 0x10)] +
                   (int)*(char *)(*(int *)(param_1 + 4 + iVar4 * 4) + 6);
            }
            if ((local_48 == 0) && (*(short *)(iVar1 + 10) != 0)) {
              local_48 = iVar1;
            }
            else if ((local_4 == 0) && (*(short *)(iVar1 + 0xc) != 0)) {
              local_4 = iVar1;
            }
            else if ((iVar5 == 0) && (*(short *)(iVar1 + 0xe) != 0)) {
              iVar5 = iVar1;
            }
          }
          if (((0 < *(int *)(param_1 + 0x50 + iVar4 * 4)) &&
              ((iVar1 = iVar4 + 2, iVar1 != 0 ||
               ((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)puVar6[1] * 0x28) & 1) == 0))))
             && ((iVar1 != 1 ||
                 (((*(byte *)(*(int *)(param_1 + 0x24) + 0x12 + (uint)*puVar6 * 0x28) & 2) == 0 ||
                  ((*(byte *)(*(int *)(param_1 + 0x28) + 0x12 + (uint)puVar6[1] * 0x28) & 1) != 0)))
                 ))) {
            iVar2 = *(int *)(param_1 + 0x2c + iVar4 * 4) + (uint)puVar6[iVar1] * 0x28;
            if (*(char *)(iVar2 + 0x10) != -1) {
              local_b4[*(char *)(iVar2 + 0x10)] =
                   local_b4[*(char *)(iVar2 + 0x10)] +
                   (int)*(char *)(*(int *)(param_1 + iVar1 * 4) + 6);
            }
            if ((local_48 == 0) && (*(short *)(iVar2 + 10) != 0)) {
              local_48 = iVar2;
            }
            else if ((local_4 == 0) && (*(short *)(iVar2 + 0xc) != 0)) {
              local_4 = iVar2;
            }
            else if ((iVar5 == 0) && (*(short *)(iVar2 + 0xe) != 0)) {
              iVar5 = iVar2;
            }
          }
          iVar4 = iVar4 + 3;
        } while (iVar4 < 9);
        iVar5 = 0;
        do {
          if ((3 < local_b4[iVar5]) && ((local_b8 == -1 || (local_b4[local_b8] < local_b4[iVar5]))))
          {
            local_b8 = iVar5;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < 0xb);
        _sprintf(_Dest,"%s %i",*(undefined4 *)(DAT_00926c20 + DAT_00880f80 * 4),local_bc + 1);
        uVar3 = FUN_00593920(param_1,puVar6,local_bc);
        *(undefined2 *)(*local_c4 * 0x4c + 0x42 + DAT_0093b274) = uVar3;
      }
      local_c4 = local_c4 + 1;
      local_bc = local_bc + 1;
      _Dest = _Dest + 0x80;
      puVar6 = puVar6 + 0x1c;
    } while (local_bc < 2);
  }
  return;
}

