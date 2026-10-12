/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694240; label: FUN_00694240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00694240(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  uint uVar3;
  
  if ((((in_ECX != (int *)0x0) && (DAT_02962b8c != 0)) && (iVar1 = in_ECX[0x76], iVar1 != 0)) &&
     (uVar2 = FUN_00693e50(param_1), uVar2 < 6)) {
    if (param_2 == 0xffffffff) {
      *(undefined4 *)(iVar1 + 0xc + uVar2 * 4) = 0;
    }
    else {
      uVar3 = param_2 & 0x7ff;
      if ((int)param_2 >> 0xb == (iVar1 - *in_ECX) / 0x24) {
        if ((int)uVar3 < *(int *)(iVar1 + 8)) {
          *(uint *)(iVar1 + 0xc + uVar2 * 4) = *(int *)(iVar1 + 4) + uVar3 * 0x3c;
          return 1;
        }
      }
      else if (((int)param_2 >> 0xb == in_ECX[1]) && ((int)uVar3 < in_ECX[3])) {
        *(uint *)(iVar1 + 0xc + uVar2 * 4) = in_ECX[2] + uVar3 * 0x3c;
        return 1;
      }
    }
  }
  return 0;
}

