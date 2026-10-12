/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6c9ee0; label: FUN_006c9ee0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c9ee0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0);
  if (iVar1 != 0) {
    uVar2 = FUN_00627bc0(0,&DAT_0081f9a0,DAT_0081fad8 == 0,1,FUN_006c9eb0,"Select");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_0081f9a0,DAT_0081fad8 == 1,1,FUN_006c9eb0,"Create");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(2,&DAT_0081f9a0,DAT_0081fad8 == 2,1,FUN_006c9eb0,"Delete");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(3,&DAT_0081f9a0,DAT_0081fad8 == 3,1,FUN_006c9eb0,&DAT_0076fe08);
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(4,&DAT_0081f9a0,DAT_0081fad8 == 4,1,FUN_006c9eb0,"Rotate");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00627bc0(5,&DAT_0081f9a0,DAT_0081fad8 == 5,1,FUN_006c9eb0,"Scale");
    FUN_00618e10(iVar1,uVar2);
    FUN_006242b0(iVar1,5);
    FUN_00627930(iVar1,1);
    FUN_006279b0(param_1,iVar1);
  }
  return;
}

