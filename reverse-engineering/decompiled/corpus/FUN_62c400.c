/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62c400; label: FUN_0062c400
 */

int * FUN_0062c400(int *param_1,undefined4 param_2,int param_3,int param_4,int param_5,
                  undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)(*param_1 + 0xfU & 0xfffffff0);
  *param_1 = (*param_1 + 0xfU & 0xfffffff0) + 0xc;
  if (piVar4 != (int *)0x0) {
    piVar4[2] = 0;
    *piVar4 = param_4;
    piVar4[1] = param_3;
    piVar4[2] = *param_1 + 0xfU & 0xfffffff0;
    *param_1 = (*param_1 + 0xfU & 0xfffffff0) + param_3 * 0x14;
    if ((void *)piVar4[2] != (void *)0x0) {
      _memset((void *)piVar4[2],-1,param_3 * 0x14);
      iVar5 = 0;
      if (0 < *piVar4) {
        iVar2 = 0;
        do {
          FUN_004f1f10(piVar4[2] + 4 + iVar2,*(undefined4 *)(param_5 + iVar5 * 4));
          *(undefined4 *)(iVar2 + piVar4[2]) = 0xffffffff;
          uVar1 = FUN_00658470(piVar4[2] + 4 + iVar2,param_6);
          *(undefined4 *)(iVar2 + piVar4[2]) = uVar1;
          iVar5 = iVar5 + 1;
          iVar2 = iVar2 + 0x14;
        } while (iVar5 < *piVar4);
      }
      iVar2 = 1;
      if (iVar5 < piVar4[1]) {
        iVar3 = iVar5 * 0x14;
        do {
          if (DAT_02962098 <= iVar2) break;
          *(undefined4 *)(iVar3 + piVar4[2]) = 0xffffffff;
          if (*(int *)(DAT_0296209c + iVar2 * 4) != 0) {
            FUN_004f1f10(piVar4[2] + 4 + iVar3,*(undefined4 *)(DAT_0296209c + iVar2 * 4));
            uVar1 = FUN_00658490(piVar4[2] + 4 + iVar3,param_6);
            *(undefined4 *)(iVar3 + piVar4[2]) = uVar1;
            iVar5 = iVar5 + 1;
            iVar3 = iVar3 + 0x14;
          }
          iVar2 = iVar2 + 1;
        } while (iVar5 < piVar4[1]);
        if (iVar5 < piVar4[1]) {
          iVar2 = iVar5 * 0x14;
          do {
            *(undefined4 *)(iVar2 + piVar4[2]) = 0xffffffff;
            iVar5 = iVar5 + 1;
            iVar2 = iVar2 + 0x14;
          } while (iVar5 < piVar4[1]);
        }
      }
      return piVar4;
    }
  }
  return (int *)0x0;
}

