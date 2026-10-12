/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65c760; label: FUN_0065c760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0065c760(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = 0;
  if (0 < DAT_02962944) {
    puVar3 = &DAT_029231b8;
    do {
      iVar1 = FUN_004f8b80(puVar3,param_1,0xf);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 0x14;
    } while (iVar2 < DAT_02962944);
  }
  return -1;
}

