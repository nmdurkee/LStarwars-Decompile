/* Ghidra pseudocode, not original source.
 * ev_3b3808edeffc7046af602211c0d6f30bd8b518f734faefbc322523a0a631579d
 * Entry: 0x6d61b0; label: FUN_006d61b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d61b0(int param_1,short *param_2)

{
  short *psVar1;
  short sVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 != (short *)0x0) {
    iVar5 = 0;
    uVar3 = 0;
    while (*(int *)((int)&DAT_00825000 + uVar3) != param_1) {
      uVar3 = uVar3 + 0x9c;
      iVar5 = iVar5 + 1;
      if (0xe9f < uVar3) {
        return;
      }
    }
    iVar5 = iVar5 * 0x9c;
    if (iVar5 != -0x824fc0) {
      puVar4 = (undefined1 *)(iVar5 + 0x825025);
      iVar6 = 4;
      do {
        puVar4[-1] = 10;
        *puVar4 = (char)*param_2;
        puVar4[1] = (char)param_2[1];
        param_2 = param_2 + 2;
        puVar4 = puVar4 + 3;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      puVar4 = (undefined1 *)(iVar5 + 0x825031);
      iVar6 = 4;
      do {
        puVar4[-1] = 0;
        *puVar4 = 0;
        puVar4[1] = 0;
        puVar4 = puVar4 + 3;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      puVar4 = (undefined1 *)(iVar5 + 0x82503d);
      iVar6 = 0x10;
      do {
        if (*param_2 == -1) {
          puVar4[-1] = 0;
          *puVar4 = 0;
        }
        else {
          puVar4[-1] = 7;
          *puVar4 = (char)*param_2;
        }
        param_2 = param_2 + 1;
        puVar4 = puVar4 + 2;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
      sVar2 = *param_2;
      while (sVar2 != -1) {
        *(char *)(iVar5 + 0x82503c + sVar2 * 2) = (char)param_2[1];
        sVar2 = *param_2;
        psVar1 = param_2 + 2;
        param_2 = param_2 + 3;
        *(char *)(iVar5 + 0x82503d + sVar2 * 2) = (char)*psVar1;
        sVar2 = *param_2;
      }
    }
  }
  return;
}

