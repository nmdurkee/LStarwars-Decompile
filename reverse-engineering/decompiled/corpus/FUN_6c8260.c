/* Ghidra analysis pseudocode, not original source.
 * ev_e0849b30759777b1ea42e04473fa04c4a6f69ff919b3575aa742b133a483e34a
 * Entry: 0x6c8260; label: FUN_006c8260
 */

int FUN_006c8260(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  int extraout_ECX;
  
  iVar4 = FUN_004f6d10(in_ECX[0x66]);
  if (0 < in_ECX[0x20]) {
    iVar5 = in_ECX[0x20];
    if (iVar5 < 1) {
      iVar4 = FUN_006b7c40();
      iVar5 = extraout_ECX;
    }
    if (in_ECX[iVar5 * 3 + 6] + in_ECX[iVar5 * 3 + 5] <= iVar4) {
      FUN_006b7c50(in_ECX[iVar5 * 3 + 7] + 0x84 + (int)in_ECX);
      return 0;
    }
  }
  if (in_ECX[0x65] == 0) {
    in_ECX[0x62] = iVar4;
    in_ECX[100] = in_ECX[0x61];
    pcVar2 = *(code **)(*in_ECX + 8);
    in_ECX[0x65] = 1;
    (*pcVar2)(in_ECX + 99,4,1);
    iVar4 = in_ECX[0x61] + 0x84 + (int)in_ECX;
    (**(code **)(*in_ECX + 0x14))(iVar4,0x100 - in_ECX[0x61]);
    iVar5 = FUN_004f1ff0(iVar4);
    in_ECX[0x61] = in_ECX[0x61] + iVar5 + 1;
  }
  else {
    iVar4 = in_ECX[100] + 0x84 + (int)in_ECX;
  }
  if (param_1 != 0) {
    iVar5 = FUN_004f8b10(param_1,iVar4);
    if (iVar5 != 0) {
      FUN_006b7c50(param_1,iVar4);
      return 0;
    }
  }
  iVar5 = in_ECX[99];
  iVar3 = in_ECX[100];
  if (in_ECX[0x20] < 8) {
    piVar1 = in_ECX + in_ECX[0x20] * 3 + 8;
    *piVar1 = in_ECX[0x62];
    piVar1[1] = iVar5;
    piVar1[2] = iVar3;
    in_ECX[0x20] = in_ECX[0x20] + 1;
    in_ECX[0x65] = 0;
    return iVar4;
  }
  FUN_006b7c40();
  in_ECX[0x65] = 0;
  return iVar4;
}

