/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x612df0; label: FUN_00612df0
 */

void FUN_00612df0(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0xd838);
  while ((*piVar2 == 0 || (*piVar2 != param_2))) {
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 5;
    if (7 < iVar1) {
      return;
    }
  }
  iVar1 = in_ECX + 0xd838 + iVar1 * 0x14;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  return;
}

