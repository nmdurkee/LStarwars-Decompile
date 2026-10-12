/* Ghidra pseudocode, not original source.
 * ev_65739642fe41f5b8b860334b2741f542947d362cd0074980e50397e4ea9361e6
 * Entry: 0x6da970; label: FUN_006da970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006da970(int param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar4 = 0;
  if (0 < param_1) {
    do {
      iVar1 = FUN_004f48e0(iVar4);
      if (iVar5 < 0xe) {
        uVar2 = iVar5 - 10;
        pcVar3 = (char *)(iVar5 * 0x17c + 0x4e5c + in_ECX);
        do {
          if ((*(int *)(pcVar3 + -0x28) != 0) && ((3 < uVar2 || (*pcVar3 != '\0')))) {
            if (iVar5 != iVar1) {
              FUN_004f47f0(iVar4,iVar5);
              FUN_004f4340(iVar5,1);
              iVar1 = FUN_006d43e0(7,iVar5,*(undefined4 *)(in_ECX + 0x6604));
              if ((iVar1 != 0) || (iVar1 = FUN_006d43e0(7,iVar5,0xffffffff), iVar1 != 0)) {
                FUN_006d45f0(iVar1,iVar5,(int)*(short *)(iVar1 + 0x5e),0,0);
              }
            }
            iVar5 = iVar5 + 1;
            break;
          }
          uVar2 = uVar2 + 1;
          iVar5 = iVar5 + 1;
          pcVar3 = pcVar3 + 0x17c;
        } while ((int)uVar2 < 4);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_1);
  }
  return;
}

