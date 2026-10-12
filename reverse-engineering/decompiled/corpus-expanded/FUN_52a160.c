/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x52a160; label: FUN_0052a160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0052a160(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
     (iVar2 = FUN_00619250(0xf0,0x5a,0xf0,0xfa,DAT_02912e80,FUN_00528d00,"Rename Creature"),
     iVar2 != 0)) {
    uVar3 = FUN_00627c00(0,&DAT_00801cb4,&LAB_0052a0c0,"Creature Name");
    FUN_00618e10(iVar2,uVar3);
    pcVar4 = (char *)(*(int *)(DAT_009238e4 + 0x371b0) + 8);
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

