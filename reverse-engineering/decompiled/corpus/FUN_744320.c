/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x744320; label: FUN_00744320
 */

void FUN_00744320(int param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  int *in_ECX;
  uint uVar2;
  int iVar3;
  
  in_ECX[8] = param_4;
  uVar1 = param_3 & 3;
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = uVar1;
  if ((((uVar1 == 0) && ((param_3 & 0x10) != 0)) && ((*(uint *)(param_1 + 0x13c) >> 0x12 & 1) == 0))
     && ((uVar2 = *(uint *)(param_2 + 0x40) >> 0xe & 3, uVar2 == 0 || (uVar2 == 2)))) {
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  in_ECX[4] = iVar3;
  if (((uVar1 == 0) && ((param_3 & 0x10) == 0)) ||
     (((*(uint *)(param_1 + 0x13c) >> 0x12 & 1) != 0 ||
      ((uVar2 = *(uint *)(param_2 + 0x40) >> 0xe & 3, uVar2 != 0 && (uVar2 != 2)))))) {
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  in_ECX[6] = iVar3;
  if ((((uVar1 == 0) && ((param_3 & 0x20) != 0)) && ((*(uint *)(param_1 + 0x13c) >> 0x12 & 1) == 0))
     && ((uVar2 = *(uint *)(param_2 + 0x40) >> 0xe & 3, uVar2 == 0 || (uVar2 == 2)))) {
    iVar3 = 1;
  }
  else {
    iVar3 = 0;
  }
  in_ECX[5] = iVar3;
  if (((byte)*(undefined4 *)(param_2 + 0x40) & 0xf) == 2) {
    in_ECX[4] = 0;
    in_ECX[6] = 0;
  }
  in_ECX[7] = (uint)(uVar1 == 0);
  if ((in_ECX[4] != 0) || ((uVar1 == 0 && ((*(byte *)(param_1 + 0x1ba) & 1) != 0)))) {
    in_ECX[7] = (uVar1 == 0) + 1;
  }
  if (in_ECX[6] != 0) {
    in_ECX[7] = in_ECX[7] + 1;
  }
  if (iVar3 != 0) {
    in_ECX[7] = in_ECX[7] + 1;
  }
  return;
}

