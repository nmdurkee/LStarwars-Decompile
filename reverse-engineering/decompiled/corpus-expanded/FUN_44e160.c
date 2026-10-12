/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44e160; label: FUN_0044e160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044e160(int param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_8;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  local_8 = 0;
  if (param_6 == 0) {
    return 1;
  }
  if (param_1 == 0) {
    return 1;
  }
  pbVar1 = *(byte **)(param_1 + 0x10);
  if (pbVar1 == (byte *)0x0) {
    return 1;
  }
  if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
    local_8 = **(int **)(param_3 + 0xd0);
  }
  iVar2 = 0;
  if (0 < param_5) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"character=");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"path=LevelPath");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757e68);
          if (iVar2 != 0) {
            iVar6 = 0;
            if (*pbVar1 != 0) {
              do {
                iVar4 = FUN_004f8b10(*(undefined4 *)(*(int *)(pbVar1 + 4) + iVar6 * 4),iVar2 + 5);
                if (iVar4 == 0) {
                  local_4 = *(int *)(*(int *)(pbVar1 + 4) + iVar6 * 4);
                  break;
                }
                iVar6 = iVar6 + 1;
              } while (iVar6 < (int)(uint)*pbVar1);
            }
          }
        }
        else {
          local_4 = *(int *)(*(int *)(param_1 + 0x10) + 8);
        }
      }
      else if ((DAT_00923904 == (code *)0x0) ||
              (piVar3 = (int *)(*DAT_00923904)(param_1,iVar2 + 10), piVar3 == (int *)0x0)) {
        local_8 = 0;
      }
      else {
        local_8 = *piVar3;
      }
      iVar5 = iVar5 + 1;
      iVar2 = local_4;
    } while (iVar5 < param_5);
  }
  if ((local_8 != 0) && (iVar2 != 0)) {
    FUN_0051a7c0(local_8 + 0x2c8,iVar2);
    FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),local_8,local_8 + 0x2c8,0xff,1);
  }
  return 1;
}

