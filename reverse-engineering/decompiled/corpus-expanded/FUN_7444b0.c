/* Ghidra pseudocode, not original source.
 * ev_0a8198a66e8ec6a1eea085c3401beb2c994e6aa9b143cc409d97940c91a3eeae
 * Entry: 0x7444b0; label: FUN_007444b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

