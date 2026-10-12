/* Ghidra analysis pseudocode, not original source.
 * ev_1cd547681849579fe9db2ab86a66300dc334807e6004e2ad8358d218d877a353
 * Entry: 0x6d7430; label: FUN_006d7430
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

