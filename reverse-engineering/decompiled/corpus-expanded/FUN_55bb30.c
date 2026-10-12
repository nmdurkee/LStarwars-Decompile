/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55bb30; label: FUN_0055bb30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0055bb30(short *param_1,short *param_2,uint param_3)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar5 = 0;
  if ((param_1 == (short *)0x0) || (param_2 == (short *)0x0)) {
    return 0;
  }
  iVar7 = *param_1 * 0x120 + DAT_0093b284;
  param_1 = (short *)0x0;
  uVar2 = 1;
  do {
    if (((param_3 & uVar2) != 0) && (uVar6 = (uint)*(byte *)(iVar7 + 0x11f), iVar5 < (int)uVar6)) {
      if (*(int *)(iVar7 + 8) == 0) {
        uVar3 = 0;
        if (uVar6 != 0) {
          psVar4 = (short *)(*(int *)(iVar7 + 4) + 0x18);
          do {
            if (*psVar4 == iVar5) break;
            uVar3 = uVar3 + 1;
            psVar4 = psVar4 + 0xe;
          } while ((int)uVar3 < (int)uVar6);
        }
        if (uVar3 == uVar6) goto LAB_0055bbd4;
      }
      else {
        uVar3 = (uint)*(char *)(*(int *)(iVar7 + 8) + iVar5);
      }
      if ((uVar3 != 0xffffffff) &&
         (sVar1 = *(short *)(*(int *)(iVar7 + 4) + 0x1a + uVar3 * 0x1c), sVar1 != -1)) {
        *param_2 = sVar1;
        param_2 = param_2 + 1;
        param_1 = (short *)((int)param_1 + 1);
      }
    }
LAB_0055bbd4:
    iVar5 = iVar5 + 1;
    uVar2 = uVar2 * 2;
    if (0x1f < iVar5) {
      return (int)param_1;
    }
  } while( true );
}

