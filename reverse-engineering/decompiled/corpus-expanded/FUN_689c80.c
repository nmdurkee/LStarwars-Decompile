/* Ghidra pseudocode, not original source.
 * ev_129ae85c041da73e18ad3e5240adb251de7047e60e981c2b1daa2599efa26a06
 * Entry: 0x689c80; label: FUN_00689c80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00689c80(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_c;
  int local_8;
  int local_4;
  
  uVar3 = DAT_0292fc68;
  iVar7 = (int)(char)param_1;
  iVar2 = iVar7 * 4;
  if ((((&DAT_02920acc)[iVar7] != 0) && (*(int *)(&DAT_02961f54 + iVar2) != 0)) &&
     ((&DAT_029211a8)[iVar7] == 0)) {
    DAT_0292fc68 = *(undefined4 *)(&DAT_02921844 + iVar2);
    if ((&DAT_0292fc0c)[iVar7] == 0) {
      if ((&DAT_0292fd10)[iVar7] == 0) {
        FUN_0065e0e0(param_1,1);
        (&DAT_0292fd10)[iVar7] = 1;
      }
      else {
        FUN_0065e0e0(param_1,0);
      }
      (&DAT_0292fc0c)[iVar7] = 1;
    }
    iVar6 = 0;
    if (0 < DAT_02962a08) {
      iVar8 = 0;
      iVar4 = DAT_02962a14;
      iVar5 = DAT_029629d8;
      do {
        iVar9 = *(int *)(iVar8 + 4 + iVar4);
        if ((iVar9 != 0) && (*(char *)(iVar8 + 0x24 + iVar4) == (char)param_1)) {
          if (0x3000 < iVar5 + iVar9) {
            iVar9 = 0x3000 - iVar5;
          }
          if (0 < iVar9) {
            local_c = *(int *)(&DAT_02961f54 + iVar2);
            if (*(int *)(local_c + 0x110) == 0) {
              local_8 = *(int *)(iVar8 + iVar4) * 0x4c + *(int *)(local_c + 0x28);
              local_4 = 0;
            }
            else {
              local_8 = 0;
              local_4 = *(int *)(iVar8 + iVar4) * 0xd0 + *(int *)(*(int *)(local_c + 0x110) + 0x70);
            }
            cVar1 = *(char *)(iVar8 + 0x27 + iVar4);
            if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
              FUN_00545860(&local_c,*(undefined4 *)(iVar8 + 0x48 + iVar4),iVar9,
                           *(undefined4 *)(iVar8 + 0x38 + iVar4),
                           *(undefined4 *)(iVar8 + 0x3c + iVar4),
                           *(undefined4 *)(iVar8 + 0x1c + iVar4));
            }
            else {
              FUN_00545ea0(&local_c,*(undefined4 *)(iVar8 + 0x48 + iVar4),iVar9,
                           *(undefined4 *)(iVar8 + 0x18 + iVar4),
                           *(undefined4 *)(iVar8 + 0x20 + iVar4),
                           *(undefined4 *)(iVar8 + 0x1c + iVar4),
                           *(undefined4 *)(iVar8 + 0x38 + iVar4),
                           *(undefined4 *)(iVar8 + 0x3c + iVar4));
            }
            iVar5 = DAT_029629d8 + iVar9;
            iVar4 = DAT_02962a14;
            DAT_029629d8 = iVar5;
          }
        }
        iVar6 = iVar6 + 1;
        iVar8 = iVar8 + 0x50;
      } while (iVar6 < DAT_02962a08);
    }
    (&DAT_029211a8)[iVar7] = 1;
  }
  DAT_0292fc68 = uVar3;
  return;
}

