/* Ghidra analysis pseudocode, not original source.
 * ev_7906274d0bf06d109a71291565ad9b380751ea78f5df54402dc74cb176b33c5a
 * Entry: 0x559e20; label: FUN_00559e20
 */

int FUN_00559e20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((((DAT_0093b268 != (int *)0x0) && (param_1 != 0)) && (param_2 != 0)) &&
     (iVar2 = 0, 0 < *DAT_0093b268)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f20f0(DAT_0093b268[2] + iVar3,param_2);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x9c;
    } while (iVar2 < *DAT_0093b268);
  }
  return -1;
}

