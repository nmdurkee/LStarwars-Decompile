/* Ghidra pseudocode, not original source.
 * ev_4955bd160544e7c7d97f773b8b388f36e51fe983a9fd069cd072b2ef5022de80
 * Entry: 0x505650; label: FUN_00505650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_00505650(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar4 = 0;
  if (0 < *(int *)(iVar1 + 8)) {
    iVar3 = 0;
    do {
      iVar2 = FUN_004f8b10(*(undefined4 *)(iVar3 + *(int *)(iVar1 + 0xc)),param_2);
      if (iVar2 == 0) {
        return *(byte *)(*(int *)(param_1 + 0xc) + 3 + iVar4 * 4) & 1;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x34;
    } while (iVar4 < *(int *)(iVar1 + 8));
  }
  return 0;
}

