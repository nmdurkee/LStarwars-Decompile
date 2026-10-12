/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x633c40; label: FUN_00633c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00633c40(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  DAT_02913238 = FUN_00619250(0x1e,0x1e,0xfa,0x140,0,FUN_00633b40,"Timings");
  if (DAT_02913238 != 0) {
    uVar3 = FUN_00627a80(0,&DAT_0080fce4,0,1,FUN_00633b60,&DAT_0076b29c);
    FUN_00618e10(DAT_02913238,uVar3);
    uVar3 = FUN_00627a80(1,&DAT_0080fce4,0,2,FUN_00633b60,"System");
    FUN_00618e10(DAT_02913238,uVar3);
    uVar3 = FUN_00627a80(2,&DAT_0080fce4,0,3,FUN_00633b60,"No Things");
    FUN_00618e10(DAT_02913238,uVar3);
    uVar3 = FUN_00627a80(3,&DAT_0080fce4,0,4,FUN_00633b60,"All Things");
    FUN_00618e10(DAT_02913238,uVar3);
    if (0 < *(int *)(DAT_02913234 + 0xc)) {
      iVar4 = 0;
      iVar5 = 4;
      do {
        piVar1 = *(int **)(iVar4 + *(int *)(DAT_02913234 + 4));
        iVar2 = piVar1[3];
        uVar3 = (**(code **)(*piVar1 + 4))();
        uVar3 = FUN_00627bc0(iVar5,&DAT_0080fce4,iVar2,iVar5 + 1,FUN_00633b60,uVar3);
        FUN_00618e10(DAT_02913238,uVar3);
        iVar2 = iVar5 + -3;
        iVar4 = iVar4 + 4;
        iVar5 = iVar5 + 1;
      } while (iVar2 < *(int *)(DAT_02913234 + 0xc));
    }
  }
  return;
}

