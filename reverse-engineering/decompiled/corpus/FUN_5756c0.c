/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x5756c0; label: FUN_005756c0
 */

int FUN_005756c0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4698);
  if ((iVar3 != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x469c))) {
    do {
      iVar1 = FUN_004f8b10(param_2,iVar3);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x128;
    } while (iVar2 < *(int *)(param_1 + 0x469c));
  }
  return 0;
}

