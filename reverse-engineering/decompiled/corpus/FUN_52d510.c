/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x52d510; label: FUN_0052d510
 */

undefined4
FUN_0052d510(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int aiStack_80 [32];
  
  if ((((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) &&
      (**(int **)(param_3 + 0xd0) != 0)) && (param_6 != 0)) {
    iVar2 = 0;
    iVar3 = 0;
    *(undefined4 *)(param_3 + 0x1b0) = *(undefined4 *)(param_2 + 0xa4);
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"locator");
        if ((iVar1 != 0) && (iVar2 < 0x20)) {
          iVar1 = FUN_0051ac10(param_1,iVar1 + 8);
          aiStack_80[iVar2] = iVar1;
          if (iVar1 != 0) {
            iVar2 = iVar2 + 1;
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
      if (iVar2 != 0) {
        iVar3 = FUN_005b9e90(0);
        *(int *)(param_3 + 0x1b0) = aiStack_80[iVar3 % iVar2];
      }
    }
  }
  return 1;
}

