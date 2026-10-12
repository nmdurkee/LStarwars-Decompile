/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x526560; label: FUN_00526560
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00526560(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined8 uVar7;
  
  if ((((DAT_00923890 != (code *)0x0) && (*(int *)(DAT_009238e4 + 0x4868) != 0)) &&
      (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) != 0)) &&
     (iVar3 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_005264d0,"Select route users"),
     iVar3 != 0)) {
    iVar6 = 0;
    iVar4 = (*DAT_00923890)(0);
    if (iVar4 != 0) {
      do {
        if (0x3f < iVar6) {
          return;
        }
        iVar1 = *(int *)(DAT_009238e4 + 0x4868);
        uVar7 = __allshl();
        iVar2 = *(int *)(iVar1 + 0x28);
        iVar1 = iVar6 + 1;
        uVar5 = FUN_00627b80(iVar6,&DAT_00801cb4,
                             ((uint)uVar7 & *(uint *)(iVar2 + 0x10)) != 0 ||
                             ((uint)((ulonglong)uVar7 >> 0x20) & *(uint *)(iVar2 + 0x14)) != 0,iVar1
                             ,FUN_005264e0,iVar4);
        FUN_00618e10(iVar3,uVar5);
        FUN_006279b0(param_1,iVar3);
        iVar4 = (*DAT_00923890)(iVar1);
        iVar6 = iVar1;
      } while (iVar4 != 0);
      if (0x3f < iVar1) {
        return;
      }
    }
    uVar5 = FUN_00627b80(0x3f,&DAT_00801cb4,
                         (*(uint *)(*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) + 0x14) &
                         0x80000000) != 0,0x40,FUN_005264e0,"Everyone");
    FUN_00618e10(iVar3,uVar5);
  }
  return;
}

