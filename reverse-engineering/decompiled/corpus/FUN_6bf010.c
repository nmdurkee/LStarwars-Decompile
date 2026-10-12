/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6bf010; label: FUN_006bf010
 */

void FUN_006bf010(undefined4 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = *(int *)(param_2 + 0xc);
  FUN_005d0480(&local_c);
  piVar2 = (int *)FUN_006bd880(0,&LAB_006befb0);
  do {
    if (piVar2 == (int *)0x0) {
LAB_006bf090:
      iVar4 = FUN_005cfac0(&local_c);
      if (iVar4 != 0) {
        uVar3 = FUN_005cfa50(&local_c);
        FUN_0061e530(param_2,uVar3);
        (**(code **)(**(int **)(iVar1 + 8) + 8))
                  (*(undefined4 *)(iVar1 + 0xc),DAT_02973acc,&local_c,0,0);
      }
      return;
    }
    uVar3 = (**(code **)(*piVar2 + 0xc))();
    iVar4 = FUN_004f8b10(*(undefined4 *)(param_2 + 100),uVar3);
    if (iVar4 == 0) {
      puVar5 = (undefined4 *)(**(code **)(*piVar2 + 0x3c))();
      local_c = *puVar5;
      uStack_8 = puVar5[1];
      uStack_4 = puVar5[2];
      goto LAB_006bf090;
    }
    piVar2 = (int *)FUN_006bd880(piVar2,&LAB_006befb0);
  } while( true );
}

