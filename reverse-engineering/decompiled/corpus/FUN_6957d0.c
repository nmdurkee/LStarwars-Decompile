/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x6957d0; label: FUN_006957d0
 */

undefined4 FUN_006957d0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  int local_4;
  
  iVar3 = in_ECX[5];
  if ((in_ECX[iVar3 + 1] == 0) || (*(int *)(in_ECX[iVar3 + 1] + 0xc + in_ECX[iVar3 + 3] * 4) == -1))
  {
    return 0xfffffffc;
  }
  local_4 = 0x3f800000;
  iVar2 = DAT_02962b8c + *in_ECX * -0x34;
  iVar1 = *(int *)(iVar2 + 0x168 + *(int *)(iVar2 + 0x178) * 4);
  in_ECX[0xc] = in_ECX[0xc] & 0xfffffffe;
  in_ECX[10] = 0;
  if ((*(int *)(in_ECX[iVar3 + 1] + 0x14) != 8) && ((iVar1 == 0 || (*(int *)(iVar1 + 0x14) != 8))))
  {
    if (*(int *)(iVar2 + 0x17c) == 7) {
      *(undefined4 *)(iVar2 + 0x18c) = 0xbf800000;
      in_ECX[10] = 0x3f800000;
      *(uint *)(iVar2 + 0x194) = *(uint *)(iVar2 + 0x194) & 0xfffffffe;
      local_4 = in_ECX[7];
    }
    else if (*(float *)(in_ECX[iVar3 + 1] + 0x24) != 0.0) {
      if ((in_ECX[6] == 6) || (in_ECX[6] == 7)) {
        in_ECX[10] = 0x3f800000;
        local_4 = in_ECX[7];
      }
      else {
        in_ECX[10] = 0x3f800000;
        local_4 = 0;
      }
    }
  }
  in_ECX[7] = local_4;
  iVar3 = FUN_006984c0(*in_ECX * 2);
  if ((iVar3 == 0) && (in_ECX[6] == 3)) {
    in_ECX[6] = 1;
  }
  iVar3 = in_ECX[6];
  if (iVar3 == 3) {
    FUN_00698420(*in_ECX * 2);
  }
  else {
    if (iVar3 == 6) {
      return 1;
    }
    if (iVar3 == 7) {
      return 1;
    }
    iVar3 = in_ECX[in_ECX[5] + 1];
    iVar3 = FUN_006953b0(2,*in_ECX,3,*(undefined4 *)(iVar3 + 0xc + in_ECX[in_ECX[5] + 3] * 4),9,
                         *(undefined4 *)(iVar3 + 0x28),6,0,10,(double)*(float *)(iVar3 + 0x24),1);
    in_ECX[9] = 0;
    FUN_00693e10();
    if (iVar3 == 0) {
      return 0xfffffffa;
    }
  }
  if (in_ECX[6] != 6) {
    in_ECX[6] = 6;
    in_ECX[0xb] = 0;
  }
  return 1;
}

