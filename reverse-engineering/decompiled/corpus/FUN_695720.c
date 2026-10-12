/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x695720; label: FUN_00695720
 */

undefined4 FUN_00695720(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_ECX;
  
  iVar3 = in_ECX[5];
  if ((in_ECX[iVar3 + 1] == 0) ||
     (iVar1 = in_ECX[iVar3 + 3] * 4 + 0xc, *(int *)(iVar1 + in_ECX[iVar3 + 1]) == -1)) {
    return 0xfffffffc;
  }
  iVar2 = in_ECX[6];
  if ((iVar2 != 6) && (((iVar2 != 7 && (iVar2 != 4)) && (iVar2 != 5)))) {
    iVar3 = FUN_006953b0(2,*in_ECX,3,*(undefined4 *)(in_ECX[iVar3 + 1] + iVar1),9,0,6,0,10,
                         (double)*(float *)(in_ECX[iVar3 + 1] + 0x24),1);
    in_ECX[9] = 0;
    FUN_00693e10();
    if (iVar3 != 0) {
      if (in_ECX[6] != 4) {
        in_ECX[6] = 4;
        in_ECX[0xb] = 0;
      }
      return 1;
    }
    return 0xfffffffa;
  }
  return 0xfffffffb;
}

