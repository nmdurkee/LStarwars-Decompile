/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x48ff00; label: FUN_0048ff00
 */

void FUN_0048ff00(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x5068) != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x506c))) {
    iVar3 = 0;
    do {
      uVar1 = FUN_0067c4f0(*(int *)(param_1 + 0x5068) + iVar3,3);
      *(undefined2 *)(iVar3 + 0x8c + *(int *)(param_1 + 0x5068)) = uVar1;
      FUN_0067c7b0((int)*(short *)(iVar3 + 0x8c + *(int *)(param_1 + 0x5068)),1);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0xa0;
    } while (iVar2 < *(int *)(param_1 + 0x506c));
  }
  return;
}

