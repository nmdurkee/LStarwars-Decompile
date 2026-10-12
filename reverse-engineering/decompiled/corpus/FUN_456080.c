/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x456080; label: FUN_00456080
 */

undefined4
FUN_00456080(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  
  if ((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
      (**(int **)(param_3 + 0xd0) != 0)) &&
     ((*(int *)(param_3 + 0x158) != 0 && (*(int *)(param_3 + 0x15c) != 0)))) {
    if (param_6 != 0) {
      *(undefined1 *)(param_2 + 0x68) = 0;
      *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_2 + 0xa4);
      if ((param_5 != 0) && (iVar4 = 0, 0 < param_5)) {
        do {
          if ((DAT_009238b0 == (code *)0x0) ||
             (iVar1 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar4 * 4),param_3 + 0x13f),
             iVar1 == 0)) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"name=");
            if ((iVar1 == 0) &&
               (iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"teleport"), iVar1 == 0))
            {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"goalrange");
              if (iVar1 == 0) {
                iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"reverse");
                if (iVar1 == 0) {
                  *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) ^ 0x200;
                }
                else {
                  iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"anticlockwise");
                  if (iVar1 == 0) {
                    *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) & 0xfffffdff;
                  }
                  else {
                    iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"clockwise");
                    if (iVar1 == 0) {
                      *(uint *)(param_3 + 0x1e8) = *(uint *)(param_3 + 0x1e8) | 0x200;
                    }
                    else {
                      fVar5 = (float10)FUN_00514920(param_3,param_2,
                                                    *(undefined4 *)(param_4 + iVar4 * 4));
                      *(float *)(param_3 + 0x180) = (float)fVar5;
                    }
                  }
                }
              }
              else {
                iVar2 = FUN_004f1ff0("goalrange");
                fVar5 = (float10)FUN_00514920(param_3,param_2,iVar1 + 1 + iVar2);
                *(float *)(param_3 + 0x180) = (float)fVar5;
              }
            }
            else {
              iVar2 = FUN_004f1ff0("name=");
              uVar3 = FUN_0051ac10(param_1,iVar1 + iVar2);
              *(undefined4 *)(param_2 + 0x6c) = uVar3;
            }
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_5);
      }
    }
    iVar4 = *(int *)(param_2 + 0x6c);
    if (iVar4 != 0) {
      FUN_0052fcb0(param_3,iVar4 + 0x10,*(undefined4 *)(param_3 + 0x180),iVar4 + 0x20,3,
                   *(undefined4 *)(param_3 + 0x180));
      return 0;
    }
  }
  return 1;
}

