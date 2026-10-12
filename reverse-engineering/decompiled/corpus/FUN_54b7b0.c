/* Ghidra analysis pseudocode, not original source.
 * ev_cab7855f9e60a8882d7cbeb236f16741d17a2f72b80db65c907162c694b9a361
 * Entry: 0x54b7b0; label: FUN_0054b7b0
 */

void FUN_0054b7b0(undefined4 param_1,undefined4 *param_2,int param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  undefined2 *puVar6;
  byte *pbVar7;
  
  pbVar5 = (byte *)*param_2;
  iVar2 = FUN_004fc860(param_1);
  if (iVar2 == 0) {
    *param_2 = pbVar5;
    return;
  }
  if (*(char *)(iVar2 + 0x578) == '\0') {
    if (*(char *)(iVar2 + 0x579) == '\0') {
      iVar3 = FUN_004fc5b0(iVar2);
      while (iVar3 != 0) {
        iVar3 = FUN_004f9e70(iVar2);
        if ((0 < iVar3) && (iVar3 < param_4)) {
          FUN_004f7fb0(iVar2);
          iVar4 = FUN_0054b6d0();
          if (iVar4 == 0) {
            pbVar7 = *(byte **)(iVar2 + 0x510);
            iVar4 = FUN_004f1ff0(pbVar7);
            if (0 < iVar4) {
              *(byte **)(param_3 + iVar3 * 4) = pbVar5;
              do {
                bVar1 = *pbVar7;
                if (bVar1 < 0x80) {
                  *pbVar5 = bVar1;
                  pbVar5 = pbVar5 + 1;
                }
                else {
                  pbVar5 = (byte *)FUN_004f3070(pbVar5,bVar1);
                }
                iVar4 = iVar4 + -1;
                pbVar7 = pbVar7 + 1;
              } while (0 < iVar4);
              *pbVar5 = 0;
              pbVar5 = pbVar5 + 1;
            }
          }
        }
        iVar3 = FUN_004fc5b0(iVar2);
      }
    }
    else {
      iVar3 = FUN_004fc5b0(iVar2);
      if (iVar3 != 0) {
        do {
          FUN_004f7fb0(iVar2);
          if (((**(char **)(iVar2 + 0x510) != '\0') &&
              (iVar3 = FUN_004f29a0(*(char **)(iVar2 + 0x510)), 0 < iVar3)) && (iVar3 < param_4)) {
            FUN_004f7fb0(iVar2);
            iVar4 = FUN_0054b6d0();
            if (iVar4 == 0) {
              iVar4 = FUN_004f1ff0(*(undefined4 *)(iVar2 + 0x510));
              *(byte **)(param_3 + iVar3 * 4) = pbVar5;
              FUN_004f1f10(pbVar5,*(undefined4 *)(iVar2 + 0x510));
              pbVar5 = pbVar5 + iVar4 + 1;
            }
          }
          iVar3 = FUN_004fc5b0(iVar2);
        } while (iVar3 != 0);
        FUN_004fa300(iVar2);
        *param_2 = pbVar5;
        return;
      }
    }
  }
  else {
    iVar3 = FUN_004fc390();
    if (iVar3 != 0) {
      do {
        iVar3 = FUN_004f9e70(iVar2);
        if ((0 < iVar3) && (iVar3 < param_4)) {
          FUN_004f7df0(iVar2);
          puVar6 = *(undefined2 **)(iVar2 + 0x510);
          iVar4 = FUN_004f2370(puVar6);
          if (0 < iVar4) {
            *(byte **)(param_3 + iVar3 * 4) = pbVar5;
            do {
              pbVar5 = (byte *)FUN_004f3070(pbVar5,*puVar6);
              iVar4 = iVar4 + -1;
              puVar6 = puVar6 + 1;
            } while (0 < iVar4);
            *pbVar5 = 0;
            pbVar5 = pbVar5 + 1;
          }
        }
        iVar3 = FUN_004fc390(iVar2);
      } while (iVar3 != 0);
      FUN_004fa300(iVar2);
      *param_2 = pbVar5;
      return;
    }
  }
  FUN_004fa300(iVar2);
  *param_2 = pbVar5;
  return;
}

