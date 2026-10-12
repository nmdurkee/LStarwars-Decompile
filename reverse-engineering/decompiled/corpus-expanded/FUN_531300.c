/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x531300; label: FUN_00531300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00531300(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_2 + 0xc);
    if (iVar1 == 0) {
      iVar1 = FUN_00619250(0xf0,0x5a,0xf0,0xfa,DAT_02912e80,0,"Empty current locator set?");
      if (iVar1 != 0) {
        uVar2 = FUN_00627a80(2,&DAT_00801cb4,0,0,FUN_00531300,&DAT_0075f2d0);
        FUN_00618e10(iVar1,uVar2);
        uVar2 = FUN_00627a80(1,&DAT_00801cb4,0,0,FUN_00531300,&PTR_DAT_0075f2d4);
        FUN_00618e10(iVar1,uVar2);
        FUN_006279b0(param_1,iVar1);
      }
    }
    else if (iVar1 == 1) {
      if (*(int *)(DAT_009238e4 + 0x41208) != 0) {
        iVar1 = 0x18;
        do {
          *(undefined4 *)(iVar1 + *(int *)(DAT_009238e4 + 0x41208)) = 0;
          iVar1 = iVar1 + 4;
        } while (iVar1 < 0x118);
      }
      if (*(int *)(DAT_009238e4 + 4) != 0) {
        uVar2 = *(undefined4 *)(DAT_009238e4 + 4);
        goto LAB_0053137a;
      }
    }
    else if ((iVar1 == 2) && (*(int *)(DAT_009238e4 + 4) != 0)) {
      uVar2 = *(undefined4 *)(DAT_009238e4 + 4);
LAB_0053137a:
      FUN_00624220(uVar2);
      *(undefined4 *)(DAT_009238e4 + 4) = 0;
      return;
    }
  }
  return;
}

