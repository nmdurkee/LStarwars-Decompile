/* Ghidra pseudocode, not original source.
 * ev_0952b0bbf23c1bfc131ce83756decc1784d73ed65e88e3a7d77cb66c992cfe6b
 * Entry: 0x639900; label: FUN_00639900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00639900(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_2 != 0) {
    piVar1 = (int *)(param_2 + 0xf4);
    iVar2 = 8;
    do {
      if (piVar1[-9] != 0) {
        iVar4 = iVar4 + 1;
      }
      if (*piVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      if (piVar1[9] != 0) {
        iVar4 = iVar4 + 1;
      }
      if (piVar1[0x12] != 0) {
        iVar4 = iVar4 + 1;
      }
      piVar1 = piVar1 + 0x24;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    FUN_006211c0(1);
    iVar2 = FUN_00621270(param_1,1);
    if (iVar2 != 0) {
      FUN_006211b0(1);
      FUN_00621520(5);
      FUN_00621520(iVar4);
      FUN_006214d0(*(undefined4 *)(param_2 + 0x24));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x14));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x1c));
      FUN_006214d0(*(undefined4 *)(param_2 + 0xb8));
      FUN_006214d0(*(undefined4 *)(param_2 + 0xbc));
      FUN_006214d0(*(undefined4 *)(param_2 + 0xc0));
      FUN_006214d0(*(undefined4 *)(param_2 + 0xc4));
      FUN_006214d0(*(undefined4 *)(param_2 + 200));
      FUN_006214d0(*(undefined4 *)(param_2 + 0xcc));
      iVar4 = param_2 + 0xd4;
      iVar2 = 0x20;
      do {
        iVar3 = iVar2;
        if (*(int *)(iVar4 + -4) != 0) {
          FUN_00621620(iVar4);
          FUN_006214d0(*(undefined4 *)(iVar4 + 0xc));
          FUN_006214d0(*(undefined4 *)(iVar4 + 0x10));
          FUN_006214d0(*(undefined4 *)(iVar4 + 0x14));
          FUN_006214d0(*(undefined4 *)(iVar4 + 0x18));
          FUN_006214d0(*(undefined4 *)(iVar4 + 0x1c));
        }
        iVar4 = iVar4 + 0x24;
        iVar2 = iVar3 + -1;
      } while (iVar2 != 0);
      FUN_006214d0(*(undefined4 *)(param_2 + 4));
      FUN_006214d0(*(undefined4 *)(param_2 + 8));
      FUN_006214d0(*(undefined4 *)(param_2 + 0xc));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x10));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x20));
      FUN_00621520(*(undefined4 *)(param_2 + 0x28));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x2c));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x30));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x34));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x38));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x3c));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x40));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x44));
      FUN_006214d0(*(undefined4 *)(param_2 + 0x48));
      FUN_006213e0();
      FUN_006211b0(0);
      return iVar3;
    }
  }
  return 0;
}

