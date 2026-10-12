/* Ghidra pseudocode, not original source.
 * ev_e52d6ac25f00059e86c3f4cc44b478706554e879f89108396fea801d3c4db5da
 * Entry: 0x6c41c0; label: FUN_006c41c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c41c0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 local_c [12];
  
  DAT_02973a5c = *(int *)(param_2 + 0xc);
  iVar1 = FUN_00619250(*(int *)(param_1 + 0x1c) + *(int *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),0xb4,0xfa,DAT_02973a78,FUN_006bc860,0);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(DAT_02973a5c + 8) + 4))
              (*(undefined4 *)(DAT_02973a5c + 0xc),DAT_02973ac8,local_c,0);
    uVar2 = FUN_00624e20(0,param_2 + 0x28,FUN_006c4090,"Colour");
    FUN_0061ad60(uVar2,unaff_EBX,unaff_EDI,unaff_ESI);
    FUN_00618e10(iVar1,uVar2);
    FUN_006279b0(param_1,iVar1);
    *(uint *)(param_2 + 0x4c) = *(uint *)(param_2 + 0x4c) & 0xfffffff7;
  }
  return;
}

