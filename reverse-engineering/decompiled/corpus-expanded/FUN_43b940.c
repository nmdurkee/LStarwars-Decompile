/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43b940; label: FUN_0043b940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043b940(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = param_1;
  if ((param_1 != 0) && (DAT_00951b50 == 0)) {
    if (*(char **)(param_1 + 0x10) != (char *)0x0) {
      iVar6 = 0;
      if (**(char **)(param_1 + 0x10) != '\0') {
        do {
          iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) + iVar6 * 4);
          *(undefined4 *)(iVar5 + 0x18) = 0;
          *(undefined4 *)(iVar5 + 0x1c) = 0;
          *(undefined4 *)(iVar5 + 0x20) = 0;
          *(undefined4 *)(iVar5 + 0x24) = 0;
          *(undefined4 *)(iVar5 + 0x28) = 0;
          *(undefined4 *)(iVar5 + 0x2c) = 0;
          *(undefined4 *)(iVar5 + 0x30) = 0;
          *(undefined4 *)(iVar5 + 0x34) = 0;
          iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) + iVar6 * 4);
          FUN_004ef660(iVar5 + 0x38,iVar5 + 0x58,0x20);
          iVar5 = *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 4) + iVar6 * 4);
          *(undefined4 *)(iVar5 + 0x58) = 0;
          *(undefined4 *)(iVar5 + 0x5c) = 0;
          *(undefined4 *)(iVar5 + 0x60) = 0;
          *(undefined4 *)(iVar5 + 100) = 0;
          *(undefined4 *)(iVar5 + 0x68) = 0;
          *(undefined4 *)(iVar5 + 0x6c) = 0;
          *(undefined4 *)(iVar5 + 0x70) = 0;
          *(undefined4 *)(iVar5 + 0x74) = 0;
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)(uint)**(byte **)(param_1 + 0x10));
      }
      iVar6 = 0;
      if (**(char **)(param_1 + 0x10) != '\0') {
        do {
          iVar5 = 0;
          param_1 = 0;
          if (*(short *)(*(int *)(*(int *)(*(int *)(iVar1 + 0x10) + 4) + iVar6 * 4) + 0x12) != 0) {
            do {
              iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x10) + 4) + iVar6 * 4);
              iVar3 = *(int *)(iVar2 + 0x80);
              iVar2 = (uint)*(byte *)(iVar3 + 0x10 + iVar5) * 0x5c + *(int *)(iVar2 + 0x7c);
              if (*(char *)(iVar2 + 0x2a) != '\0') {
                FUN_0051af40(iVar1,*(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x10) + 4) + iVar6 * 4)
                             ,iVar2);
              }
              iVar2 = *(int *)(*(int *)(*(int *)(iVar1 + 0x10) + 4) + iVar6 * 4);
              iVar3 = (uint)*(byte *)(iVar3 + iVar5 + 0x11) * 0x5c + *(int *)(iVar2 + 0x7c);
              if (*(char *)(iVar3 + 0x2a) != '\0') {
                FUN_0051af40(iVar1,iVar2,iVar3);
              }
              param_1 = param_1 + 1;
              iVar5 = iVar5 + 0x24;
            } while (param_1 < (int)(uint)*(ushort *)
                                           (*(int *)(*(int *)(*(int *)(iVar1 + 0x10) + 4) +
                                                    iVar6 * 4) + 0x12));
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < (int)(uint)**(byte **)(iVar1 + 0x10));
      }
    }
    if ((int)(uint)*(byte *)(iVar1 + 0x1384) < *(int *)(iVar1 + 0x34)) {
      FUN_0043b7c0();
      *(char *)(iVar1 + 0x1384) = *(char *)(iVar1 + 0x1384) + '\x01';
      if (*(int *)(iVar1 + 0x34) <= (int)(uint)*(byte *)(iVar1 + 0x1384)) {
        *(undefined1 *)(iVar1 + 0x1384) = 0;
      }
    }
    iVar6 = 0;
    if (0 < *(int *)(PTR_DAT_00802c54 + 0x2aec)) {
      iVar5 = 0;
      puVar4 = PTR_DAT_00802c54;
      do {
        if ((puVar4[iVar5 + 0x2b50] & 2) == 0) {
          FUN_0052cc90(iVar1,0,0,puVar4 + iVar5 + 0x2b00,_DAT_00925018);
          puVar4 = PTR_DAT_00802c54;
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0xdc;
      } while (iVar6 < *(int *)(puVar4 + 0x2aec));
    }
  }
  return;
}

