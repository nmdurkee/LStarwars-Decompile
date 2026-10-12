/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x531450; label: FUN_00531450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00531450(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if ((*(int *)(DAT_009238e4 + 0x41208) != 0) &&
     (iVar2 = FUN_00619250(0xf0,0x5a,0xf0,0xfa,DAT_02912e80,FUN_00531420,"Rename Locator Set"),
     iVar2 != 0)) {
    uVar3 = FUN_00627c00(0,&DAT_00801cb4,FUN_00522340,&DAT_00758a60);
    FUN_00618e10(iVar2,uVar3);
    pcVar4 = (char *)(*(int *)(DAT_009238e4 + 0x41208) + 8);
    pcVar5 = (char *)(DAT_02900c84 + 0x4c);
    do {
      cVar1 = *pcVar4;
      *pcVar5 = cVar1;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    *(undefined2 *)(DAT_02900c84 + 0x15a) = 0xf;
    FUN_006279b0(param_1,iVar2);
    *(int *)(iVar2 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(iVar2 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}

