/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51ba10; label: FUN_0051ba10
 */

char * FUN_0051ba10(int param_1,undefined4 param_2,int *param_3,int param_4,char *param_5,
                   int param_6,float *param_7)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  float10 fVar11;
  char *local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  piVar6 = param_3;
  *(ushort *)((int)param_3 + 0xe) = *(ushort *)((int)param_3 + 0xe) & 0xfffe;
  pcVar7 = (char *)0x0;
  if (((param_1 != 0) && (pcVar7 = *(char **)(param_1 + 0x10), pcVar7 != (char *)0x0)) &&
     (*pcVar7 != '\0')) {
    if (param_6 == 0) {
      if (param_4 == 0) {
        param_4 = *(int *)(pcVar7 + 8);
      }
      if (*param_3 != param_4) {
        *param_3 = param_4;
        param_3[1] = 0;
        *(undefined2 *)(param_3 + 3) = 0;
      }
    }
    else {
      if (*param_3 == 0) {
        *param_3 = **(int **)(pcVar7 + 4);
        param_3[1] = 0;
        *(undefined2 *)(param_3 + 3) = 0;
      }
      param_4 = *param_3;
    }
    FUN_0051a760();
    iVar8 = param_3[1];
    if (iVar8 != 0) {
      pcVar7 = (char *)FUN_0051b1f0(param_1,param_2,param_4,iVar8,1,0,0xff,0xff,param_3,0,1);
      if (pcVar7 != (char *)0x0) {
        return pcVar7;
      }
      iVar9 = (uint)*(byte *)(*(byte *)(param_3 + 2) + 0x10 + iVar8) * 0x5c +
              *(int *)(*param_3 + 0x7c);
      param_3 = (int *)0x0;
      if (*(char *)(iVar9 + 0x28) != '\0') {
        do {
          iVar10 = *(int *)(*(int *)(iVar9 + 0x34) + (int)param_3 * 4);
          if ((iVar10 != iVar8) &&
             (pcVar7 = (char *)FUN_0051b1f0(param_1,param_2,param_4,iVar10,1,0,0xff,0xff,piVar6,0,1)
             , pcVar7 != (char *)0x0)) {
            return pcVar7;
          }
          param_3 = (int *)((int)param_3 + 1);
        } while ((int)param_3 < (int)(uint)*(byte *)(iVar9 + 0x28));
      }
      iVar9 = (uint)*(byte *)(((char)piVar6[2] == '\0') + 0x10 + iVar8) * 0x5c +
              *(int *)(*piVar6 + 0x7c);
      param_3 = (int *)0x0;
      if (*(char *)(iVar9 + 0x28) != '\0') {
        do {
          iVar10 = *(int *)(*(int *)(iVar9 + 0x34) + (int)param_3 * 4);
          if ((iVar10 != iVar8) &&
             (pcVar7 = (char *)FUN_0051b1f0(param_1,param_2,param_4,iVar10,1,0,0xff,0xff,piVar6,0,1)
             , pcVar7 != (char *)0x0)) {
            return pcVar7;
          }
          param_3 = (int *)((int)param_3 + 1);
        } while ((int)param_3 < (int)(uint)*(byte *)(iVar9 + 0x28));
      }
    }
    if (param_6 == 0) {
      pcVar7 = (char *)(uint)*(byte *)(*piVar6 + 0x10);
      local_1c = param_5;
      if ((int)pcVar7 < (int)param_5) {
        local_1c = pcVar7;
      }
      if (local_1c != (char *)0x0) {
        do {
          iVar9 = (uint)*(ushort *)(piVar6 + 3) * 0x5c + *(int *)(*piVar6 + 0x7c);
          iVar8 = 0;
          if (*(char *)(iVar9 + 0x28) != '\0') {
            do {
              pcVar7 = (char *)FUN_0051b1f0(param_1,param_2,param_4,
                                            *(undefined4 *)(*(int *)(iVar9 + 0x34) + iVar8 * 4),1,0,
                                            0xff,0xff,piVar6,0,1);
              if (pcVar7 != (char *)0x0) {
                return pcVar7;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 < (int)(uint)*(byte *)(iVar9 + 0x28));
          }
          uVar3 = *(ushort *)(piVar6 + 3);
          bVar1 = *(byte *)(*piVar6 + 0x10);
          local_1c = local_1c + -1;
          *(short *)(piVar6 + 3) =
               (short)((ulonglong)(uVar3 + 1) % (ulonglong)(longlong)(int)(uint)bVar1);
        } while (local_1c != (char *)0x0);
        return (char *)((ulonglong)(uVar3 + 1) / (ulonglong)(longlong)(int)(uint)bVar1);
      }
    }
    else {
      bVar1 = *(byte *)(piVar6 + 2);
      local_14 = *piVar6;
      local_10 = piVar6[1];
      if ((*(byte *)((int)piVar6 + 9) == 0xffffffff) || (*(byte *)((int)piVar6 + 9) == 0xff)) {
        *(undefined1 *)((int)piVar6 + 9) = *(undefined1 *)(local_14 + 0x15);
      }
      if (**(byte **)(param_1 + 0x10) <= *(byte *)((int)piVar6 + 9)) {
        *(undefined1 *)((int)piVar6 + 9) = 0;
      }
      iVar8 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) + (uint)*(byte *)((int)piVar6 + 9) * 4
                      );
      *piVar6 = iVar8;
      if ((ushort)*(byte *)(iVar8 + 0x10) <= *(ushort *)(piVar6 + 3)) {
        *(undefined2 *)(piVar6 + 3) = 0;
      }
      FUN_0051a760();
      cVar2 = *(char *)((int)piVar6 + 9);
      iVar8 = piVar6[3];
      local_18 = 0;
      do {
        if (param_5 == (char *)0x0) break;
        if ((local_18 != 0) || (local_18 = FUN_005173b0(*piVar6,param_2), local_18 != 0)) {
          iVar10 = (uint)*(ushort *)(piVar6 + 3) * 0x5c + *(int *)(*piVar6 + 0x7c);
          iVar9 = 0;
          if (*(char *)(iVar10 + 0x28) != '\0') {
            do {
              iVar4 = *(int *)(*(int *)(iVar10 + 0x34) + iVar9 * 4);
              pcVar7 = (char *)FUN_0051b1f0(param_1,param_2,*piVar6,iVar4,1,0,0xff,0xff,piVar6,0,1);
              if (pcVar7 != (char *)0x0) {
                return pcVar7;
              }
              if (param_7 != (float *)0x0) {
                iVar5 = *(int *)(*(int *)(iVar10 + 0x34) + iVar9 * 4);
                fVar11 = (float10)FUN_005bf910((uint)*(byte *)(iVar5 + 0x10) * 0x5c + 4 +
                                               *(int *)(*piVar6 + 0x7c),
                                               (uint)*(byte *)(iVar5 + 0x11) * 0x5c + 4 +
                                               *(int *)(*piVar6 + 0x7c),param_2,0);
                if ((float)fVar11 < *param_7) {
                  *param_7 = (float)fVar11;
                  local_14 = *piVar6;
                  local_10 = iVar4;
                }
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < (int)(uint)*(byte *)(iVar10 + 0x28));
          }
        }
        *(short *)(piVar6 + 3) = (short)piVar6[3] + 1;
        if (((ushort)*(byte *)(*piVar6 + 0x10) <= *(ushort *)(piVar6 + 3)) || (local_18 == 0)) {
          *(char *)((int)piVar6 + 9) = *(char *)((int)piVar6 + 9) + '\x01';
          *(undefined2 *)(piVar6 + 3) = 0;
          if (**(byte **)(param_1 + 0x10) <= *(byte *)((int)piVar6 + 9)) {
            *(undefined1 *)((int)piVar6 + 9) = 0;
          }
          iVar9 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) +
                          (uint)*(byte *)((int)piVar6 + 9) * 4);
          *piVar6 = iVar9;
          piVar6[1] = 0;
          if (((iVar9 != 0) && (*(int *)(iVar9 + 0x7c) != 0)) && (*(byte *)(iVar9 + 0x10) != 0)) {
            pcVar7 = (char *)(iVar9 + 0x78);
            *pcVar7 = *pcVar7 + '\x01';
            if (*pcVar7 == '\0') {
              *(undefined1 *)(iVar9 + 0x78) = 1;
            }
            *(char *)(iVar9 + 0x79) = *(char *)(iVar9 + 0x79) + '\x01';
            if (*(byte *)(iVar9 + 0x10) <= *(byte *)(iVar9 + 0x79)) {
              *(undefined1 *)(iVar9 + 0x79) = 0;
            }
            iVar9 = (uint)*(byte *)(iVar9 + 0x79) * 0x5c + *(int *)(iVar9 + 0x7c);
            iVar10 = 0;
            if (*(char *)(iVar9 + 0x28) != '\0') {
              do {
                *(undefined1 *)(*(int *)(*(int *)(iVar9 + 0x34) + iVar10 * 4) + 0x17) = 0;
                iVar10 = iVar10 + 1;
              } while (iVar10 < (int)(uint)*(byte *)(iVar9 + 0x28));
            }
          }
          local_18 = 0;
        }
        param_5 = param_5 + -1;
      } while ((*(char *)((int)piVar6 + 9) != cVar2) || ((short)piVar6[3] != (short)iVar8));
      pcVar7 = (char *)(uint)bVar1;
      *piVar6 = local_14;
      piVar6[1] = local_10;
      *(byte *)(piVar6 + 2) = bVar1;
    }
  }
  return pcVar7;
}

