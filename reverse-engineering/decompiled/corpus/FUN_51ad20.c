/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51ad20; label: FUN_0051ad20
 */

undefined4 FUN_0051ad20(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  if (((param_1 != 0) && (pbVar1 = *(byte **)(param_1 + 0x10), pbVar1 != (byte *)0x0)) &&
     (iVar3 = 0, *pbVar1 != 0)) {
    do {
      iVar2 = FUN_004f8b10(*(undefined4 *)(*(int *)(pbVar1 + 4) + iVar3 * 4),param_2);
      pbVar1 = *(byte **)(param_1 + 0x10);
      if (iVar2 == 0) {
        return *(undefined4 *)(*(int *)(pbVar1 + 4) + iVar3 * 4);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)(uint)*pbVar1);
  }
  return 0;
}

