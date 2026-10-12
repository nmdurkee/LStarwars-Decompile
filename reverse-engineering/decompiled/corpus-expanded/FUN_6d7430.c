/* Ghidra pseudocode, not original source.
 * ev_581650960e40fbf8034e5bec09e71430d76f0976c291edf1f63134fb2e6d6ade
 * Entry: 0x6d7430; label: FUN_006d7430
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d7430(int param_1,int param_2)

{
  int iVar1;
  short *psVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  
  if (*(int *)(in_ECX + 0x6558 + param_1 * 4) - 10U < 4) {
    iVar7 = 0;
    iVar1 = param_1 * 0x80 + 0x6358 + in_ECX;
    if (0 < param_2) {
      piVar4 = (int *)(in_ECX + 0x6558);
      psVar5 = (short *)(in_ECX + 0x635a);
      iVar6 = (iVar1 - in_ECX) + -0x6358;
      do {
        if ((iVar7 != param_1) && (*piVar4 - 10U < 4)) {
          iVar3 = 0;
          psVar2 = psVar5;
          do {
            if ((*(short *)(iVar6 + (int)psVar2) == *psVar2) &&
               (*(char *)(iVar1 + iVar3 * 4) == (char)psVar2[-1])) {
              *psVar2 = 0;
              *(undefined1 *)(psVar2 + -1) = 0;
            }
            iVar3 = iVar3 + 1;
            psVar2 = psVar2 + 2;
          } while (iVar3 < 0x20);
        }
        iVar7 = iVar7 + 1;
        piVar4 = piVar4 + 1;
        iVar6 = iVar6 + -0x80;
        psVar5 = psVar5 + 0x40;
      } while (iVar7 < param_2);
    }
  }
  return;
}

