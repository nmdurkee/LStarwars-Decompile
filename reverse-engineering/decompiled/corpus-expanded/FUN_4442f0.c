/* Ghidra pseudocode, not original source.
 * ev_20f8c411b4261e575accf39560ead20e25095f356798bee204490bf31a6f5756
 * Entry: 0x4442f0; label: FUN_004442f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004442f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar3 = *(int **)(param_3 + 0xd0), piVar3 != (int *)0x0)) &&
       (*piVar3 != 0)) {
      iVar5 = *piVar3;
    }
    iVar6 = 0;
    if (0 < param_5) {
      uVar4 = 0;
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"character=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),&DAT_00757700);
          if (iVar2 != 0) {
            FUN_005147c0(param_2,iVar2 + 4);
            uVar4 = FUN_006e6b90();
            if (((int)uVar4 < 0) || (0x10 < (int)uVar4)) {
              uVar4 = 0;
            }
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 10), piVar3 == (int *)0x0)) {
          iVar5 = 0;
        }
        else {
          iVar5 = *piVar3;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_5);
      if (uVar4 != 0) {
        iVar6 = 0;
        iVar5 = DAT_0093d504;
        if (DAT_0093d500 < 1) {
          return 1;
        }
        do {
          if (((*(uint *)(iVar5 + 0x1fc) & 1) != 0) && (*(byte *)(iVar5 + 0x378) == uVar4)) {
            if (*(char *)(iVar5 + 0x400) == -1) {
              *(uint *)(iVar5 + 0x1fc) = *(uint *)(iVar5 + 0x1fc) | 0x1000;
              FUN_0052c790(iVar5 + 0x2c8,&DAT_00753270);
            }
            else {
              FUN_0041c120(iVar5,param_1);
            }
            (&DAT_00876847)[uVar4] = (&DAT_00876847)[uVar4] + '\x01';
          }
          iVar6 = iVar6 + 1;
          iVar5 = iVar5 + 0x10d8;
        } while (iVar6 < DAT_0093d500);
        return 1;
      }
    }
    if (iVar5 != 0) {
      if (*(char *)(iVar5 + 0x400) == -1) {
        *(uint *)(iVar5 + 0x1fc) = *(uint *)(iVar5 + 0x1fc) | 0x1000;
        FUN_0052c790(iVar5 + 0x2c8,&DAT_00753270);
      }
      else {
        FUN_0041c120(iVar5,param_1);
      }
      bVar1 = *(byte *)(iVar5 + 0x378);
      if ((bVar1 != 0) && (bVar1 < 0x11)) {
        (&DAT_00876847)[bVar1] = (&DAT_00876847)[bVar1] + '\x01';
      }
    }
  }
  return 1;
}

