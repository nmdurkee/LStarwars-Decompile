/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65c620; label: FUN_0065c620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0065c620(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_c [12];
  
  if (param_2 != 0) {
    iVar3 = 0;
    iVar1 = FUN_005da840(param_2);
    if (0 < iVar1) {
      do {
        FUN_005da860(local_c,param_2,iVar3);
        uVar2 = FUN_005cfa50(local_c,param_1,0x13);
        iVar1 = FUN_004f8b80(uVar2);
        if (iVar1 == 0) {
          return iVar3;
        }
        iVar3 = iVar3 + 1;
        iVar1 = FUN_005da840(param_2);
      } while (iVar3 < iVar1);
    }
  }
  return -1;
}

