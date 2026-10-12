/* Ghidra pseudocode, not original source.
 * ev_6d32088aadafc0ff590ef2b7105f938147ee95ce1444f973b36a6fd6e03e3889
 * Entry: 0x5263f0; label: FUN_005263f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005263f0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (((*(int *)(DAT_009238e4 + 0x4868) != 0) &&
      (*(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28) != 0)) &&
     (iVar2 = FUN_00619250(0xf0,0x5a,0xf0,0xfa,DAT_02912e80,FUN_005263e0,"Rename Route"), iVar2 != 0
     )) {
    uVar3 = FUN_00627c00(0,&DAT_00801cb4,&LAB_00526350,"Route Name");
    FUN_00618e10(iVar2,uVar3);
    pcVar4 = *(char **)(*(int *)(DAT_009238e4 + 0x4868) + 0x28);
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

