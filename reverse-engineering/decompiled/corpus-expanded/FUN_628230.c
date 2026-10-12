/* Ghidra pseudocode, not original source.
 * ev_089833714d61d65eb350d99c3da767c9514a7b314bb0b1f84b7d509473600b9f
 * Entry: 0x628230; label: FUN_00628230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00628230(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int in_ECX;
  size_t sVar7;
  int local_40c;
  int local_408;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_40c;
  piVar6 = DAT_02912eac;
  if (DAT_02912f18 != (void *)0x0) {
    *(undefined2 *)(param_1 + 0x56) = 0;
    DAT_02912b3c = param_1;
    DAT_02912b44 = in_ECX;
    local_40c = in_ECX;
    piVar1 = (int *)FUN_00619250(*(int *)(in_ECX + 0x14) + 0x14,*(int *)(in_ECX + 0x18) + 0x14,0xfa,
                                 300,*(undefined4 *)(in_ECX + 0x2c),FUN_006280d0,"Directory");
    piVar6 = DAT_02912eac;
    if (piVar1 != (int *)0x0) {
      FUN_004f2740(local_404,&DAT_00751c00,param_1 + 0x98,param_1 + 0x198);
      iVar2 = FUN_004ffc20(local_404);
      local_408 = iVar2;
      if (iVar2 != 0) {
        DAT_02912f1c = 0;
        iVar3 = FUN_004ffd80(iVar2,DAT_02912f18);
        while ((0 < iVar3 && ((int)DAT_02912f1c < DAT_0080f590))) {
          DAT_02912f1c = DAT_02912f1c + 1;
          iVar3 = FUN_004ffd80(iVar2,(void *)(DAT_02912f1c * 0x118 + (int)DAT_02912f18));
        }
        if (*(_PtFuncCompare **)(param_1 + 0x2a0) != (_PtFuncCompare *)0x0) {
          _qsort(DAT_02912f18,DAT_02912f1c,0x118,*(_PtFuncCompare **)(param_1 + 0x2a0));
        }
        if (*(char *)(param_1 + 0x198) != '\0') {
          iVar2 = FUN_00627a80(9999,param_1 + 0x28,0,1,FUN_00628110,&DAT_0076b00c);
          *(undefined1 *)(iVar2 + 0x12) = 0x10;
          FUN_00618e10(piVar1,iVar2);
        }
        iVar2 = 0;
        pvVar5 = DAT_02912f18;
        sVar7 = DAT_02912f1c;
        if (0 < (int)DAT_02912f1c) {
          iVar3 = 0;
          do {
            if ((*(byte *)(iVar3 + (int)pvVar5) & 8) != 0) {
              FUN_004f2740(local_404,&DAT_0076b004,iVar3 + 0x18 + (int)pvVar5);
              DAT_02900c84 = (undefined4 *)
                             FUN_00627a80(iVar2,param_1 + 0x28,0,1,FUN_00628110,local_404);
              *(undefined1 *)((int)DAT_02900c84 + 0x12) = 0x10;
              if ((undefined4 *)piVar1[1] == (undefined4 *)0x0) {
                *piVar1 = (int)DAT_02900c84;
              }
              else {
                *(undefined4 *)piVar1[1] = DAT_02900c84;
              }
              DAT_02900c84[1] = piVar1[1];
              sVar7 = DAT_02912f1c;
              *DAT_02900c84 = 0;
              piVar1[1] = (int)DAT_02900c84;
              piVar1[3] = *piVar1;
              pvVar5 = DAT_02912f18;
              piVar1[4] = 0;
            }
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + 0x118;
          } while (iVar2 < (int)sVar7);
        }
        iVar2 = 0;
        if (0 < (int)sVar7) {
          iVar3 = 0;
          do {
            if (((*(char *)(param_1 + 0x298) == '\0') ||
                (iVar4 = FUN_004f8a70(iVar3 + 0x18 + (int)pvVar5,param_1 + 0x298),
                pvVar5 = DAT_02912f18, sVar7 = DAT_02912f1c, iVar4 != 0)) &&
               ((*(byte *)(iVar3 + (int)pvVar5) & 8) == 0)) {
              FUN_004f2740(local_404,"%s  ( size=%d  date=%d/%d/%d %d:%d )",
                           iVar3 + 0x18 + (int)pvVar5,*(undefined4 *)(iVar3 + 4 + (int)pvVar5),
                           (int)*(char *)(iVar3 + 0x13 + (int)pvVar5),
                           (int)*(char *)(iVar3 + 0x14 + (int)pvVar5),
                           (int)*(short *)(iVar3 + 0x16 + (int)pvVar5),
                           (int)*(char *)(iVar3 + 0x12 + (int)pvVar5),
                           (int)*(char *)(iVar3 + 0x11 + (int)pvVar5));
              DAT_02900c84 = (undefined4 *)
                             FUN_00627a80(iVar2,param_1 + 0x28,0,1,FUN_00628110,local_404);
              *(undefined1 *)((int)DAT_02900c84 + 0x12) = 0x10;
              if ((undefined4 *)piVar1[1] == (undefined4 *)0x0) {
                *piVar1 = (int)DAT_02900c84;
              }
              else {
                *(undefined4 *)piVar1[1] = DAT_02900c84;
              }
              DAT_02900c84[1] = piVar1[1];
              sVar7 = DAT_02912f1c;
              *DAT_02900c84 = 0;
              piVar1[1] = (int)DAT_02900c84;
              piVar1[3] = *piVar1;
              pvVar5 = DAT_02912f18;
              piVar1[4] = 0;
            }
            iVar2 = iVar2 + 1;
            iVar3 = iVar3 + 0x118;
          } while (iVar2 < (int)sVar7);
        }
        if (*piVar1 == 0) {
          DAT_02900c84 = (undefined4 *)
                         FUN_00627a80(iVar2,param_1 + 0x28,0,1,FUN_006280f0,"No Files");
          if ((undefined4 *)piVar1[1] == (undefined4 *)0x0) {
            *piVar1 = (int)DAT_02900c84;
          }
          else {
            *(undefined4 *)piVar1[1] = DAT_02900c84;
          }
          DAT_02900c84[1] = piVar1[1];
          *DAT_02900c84 = 0;
          piVar1[1] = (int)DAT_02900c84;
          piVar1[3] = *piVar1;
          piVar1[4] = 0;
        }
        FUN_004ffd20(local_408);
        in_ECX = local_40c;
      }
      FUN_006242b0(piVar1,8);
      piVar6 = DAT_02912eac;
      if (piVar1[0x10] == 0) {
        iVar2 = *(int *)(in_ECX + 0x3c);
        while (iVar2 != 0) {
          in_ECX = *(int *)(in_ECX + 0x3c);
          iVar2 = *(int *)(in_ECX + 0x3c);
        }
        piVar1[0x10] = in_ECX;
        *(int **)(in_ECX + 0x3c) = piVar1;
        piVar6 = DAT_02912eac;
        if ((DAT_02912f30 != 0) && (piVar6 = piVar1, piVar1[0xf] != 0)) {
          piVar6 = (int *)FUN_0061f070();
        }
      }
    }
  }
  DAT_02912eac = piVar6;
  __security_check_cookie(local_4 ^ (uint)&local_40c);
  return;
}

