/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44b150; label: FUN_0044b150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044b150(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  uVar4 = 0xffffffff;
  bVar1 = true;
  if (param_6 != 0) {
    if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
      iVar5 = **(int **)(param_3 + 0xd0);
    }
    iVar6 = 0;
    if (0 < param_5) {
      do {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"character=");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar6 * 4),"messageval=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"dont_set_max");
            if (iVar2 == 0) {
              bVar1 = false;
            }
            else {
              iVar2 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar6 * 4),"default");
              if (iVar2 != 0) {
                FUN_005147c0(param_2,*(undefined4 *)(param_4 + iVar6 * 4));
                goto LAB_0044b244;
              }
            }
          }
          else {
            iVar2 = FUN_005aac00(DAT_0095df4c,iVar2 + 0xb,0);
            if (iVar2 != 0) {
LAB_0044b244:
              uVar4 = FUN_006e6b90();
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
    }
    if (iVar5 != 0) {
      if (uVar4 == 0xffffffff) {
        uVar4 = (uint)*(byte *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0xf4);
      }
      if (bVar1) {
        *(char *)(iVar5 + 0x107e) = (char)uVar4;
      }
      *(char *)(iVar5 + 0x107f) = (char)uVar4;
    }
  }
  return 1;
}

