/* Ghidra pseudocode, not original source.
 * ev_8506f68535ad223f61af74cca875ccd9b44b8142143265b685ac08963c75a37f
 * Entry: 0x4550a0; label: FUN_004550a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004550a0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *local_4;
  
  iVar4 = 0;
  iVar3 = 0;
  uVar5 = 0xffffffff;
  local_4 = (char *)0x0;
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar3 = *piVar1;
  }
  if ((param_6 != 0) && (0 < param_5)) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_0075772c);
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"script");
        if (iVar2 != 0) {
          local_4 = (char *)(iVar2 + 7);
        }
      }
      else if ((DAT_00923884 != (code *)0x0) && (DAT_00923894 != (code *)0x0)) {
        uVar5 = (*DAT_00923884)(iVar2 + 5);
        uVar5 = uVar5 & 0xff;
        if (uVar5 != 0xff) {
          uVar5 = (*DAT_00923894)(uVar5);
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5);
    if ((uVar5 != 0xffffffff) && (*(int *)(iVar3 + 0xcd0) == 0)) {
      if (local_4 == (char *)0x0) {
        local_4 = "default";
      }
      iVar4 = FUN_0043d890(uVar5,iVar3 + 0x80,0,local_4,0,0,0,0,0,0,0);
      if (iVar4 != 0) {
        FUN_00488730(iVar4,iVar3,0,1);
      }
    }
  }
  return 1;
}

