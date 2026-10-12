/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46cb50; label: FUN_0046cb50
 */

void FUN_0046cb50(int param_1)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined1 local_30 [22];
  undefined1 local_1a;
  undefined1 local_b;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_30;
  if ((DAT_00951b50 == 0) && ((*(uint *)(param_1 + 0x144) & 0x200) != 0)) {
    if ((DAT_0093d7f0 == 0) || ((*(byte *)(DAT_0093d7f0 + 0x1fc) & 0x80) == 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if ((DAT_0093d7f4 == 0) || ((*(byte *)(DAT_0093d7f4 + 0x1fc) & 0x80) == 0)) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if (bVar1) {
      iVar3 = DAT_0093d7f0;
      if (bVar2) {
        iVar3 = FUN_0054fa60();
        iVar3 = (&DAT_0093d7f0)[(int)(iVar3 + (iVar3 >> 0x1f & 0x7fffU)) >> 0xf];
      }
    }
    else {
      iVar3 = DAT_0093d7f4;
      if (!bVar2) goto LAB_0046cc1a;
    }
    if (iVar3 != 0) {
      FUN_0046c610((int)*(short *)(param_1 + 0x13e),local_30);
      FUN_0046b1d0(PTR_DAT_00802c54,param_1 + 0x30,local_b,local_1a,iVar3,1);
    }
  }
LAB_0046cc1a:
  __security_check_cookie(local_4 ^ (uint)local_30);
  return;
}

