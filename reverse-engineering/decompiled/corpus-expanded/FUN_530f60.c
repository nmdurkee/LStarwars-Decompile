/* Ghidra pseudocode, not original source.
 * ev_46856ff831ab396d087503af3f2d098038d70627b695f8c2598b186b09430fbf
 * Entry: 0x530f60; label: FUN_00530f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00530f60(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if ((*(int *)(DAT_009238e4 + 0x3cbe0) != 0) &&
     (iVar2 = FUN_00619250(0xf0,0x5a,0xf0,0xfa,DAT_02912e80,FUN_00522330,"Rename Locator"),
     iVar2 != 0)) {
    uVar3 = FUN_00627c00(0,&DAT_00801cb4,FUN_00522290,"Locator Name");
    FUN_00618e10(iVar2,uVar3);
    pcVar4 = (char *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 8);
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

