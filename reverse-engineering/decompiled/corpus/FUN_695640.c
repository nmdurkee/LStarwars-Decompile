/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x695640; label: FUN_00695640
 */

undefined4 FUN_00695640(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = in_ECX[5];
  if ((in_ECX[iVar1 + 1] == 0) || (iVar1 == 0)) {
    return 0;
  }
  if (*(int *)(in_ECX[iVar1 + 1] + 0x14) == 8) {
    in_ECX[5] = iVar1 + -1;
    if (in_ECX[iVar1] == 0) {
      if (in_ECX[6] != 0) {
        in_ECX[6] = 0;
        in_ECX[0xb] = 0;
      }
      in_ECX[iVar1] = 0;
    }
    else {
      in_ECX[7] = 0;
      FUN_00698400(*in_ECX * 2);
      iVar1 = FUN_006953b0(2,*in_ECX,3,
                           *(undefined4 *)(in_ECX[in_ECX[5] + 1] + 0xc + in_ECX[in_ECX[5] + 3] * 4),
                           9,0,6,0,10,(double)*(float *)(in_ECX[in_ECX[5] + 1] + 0x24),1);
      in_ECX[9] = 0;
      FUN_00693e10();
      if ((iVar1 != 0) && (in_ECX[6] != 4)) {
        in_ECX[6] = 4;
        in_ECX[0xb] = 0;
        return 1;
      }
    }
  }
  return 1;
}

