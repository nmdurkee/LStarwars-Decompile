/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x7444b0; label: FUN_007444b0
 */

uint FUN_007444b0(uint param_1)

{
  uint uVar1;
  uint *in_ECX;
  
  if ((in_ECX[3] == 0) || (uVar1 = *in_ECX, *(char *)(*in_ECX + 0x1b4) != '\0')) {
    uVar1 = param_1;
    switch(param_1) {
    case 0:
      return CONCAT31((int3)((uint)*(int *)(*in_ECX + 4) >> 8),
                      (int)in_ECX[8] < *(int *)(*in_ECX + 4));
    case 1:
      return (uint)((int)in_ECX[8] < *(int *)(*in_ECX + 8));
    case 2:
      return (uint)((int)in_ECX[8] < *(int *)(*in_ECX + 0xc));
    case 3:
      return (uint)((int)in_ECX[8] < *(int *)(*in_ECX + 0x10));
    }
  }
  return uVar1 & 0xffffff00;
}

