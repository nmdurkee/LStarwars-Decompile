/* Ghidra pseudocode, not original source.
 * ev_199d5657b5876f414b53b7573c69de9797f7cece73cdea401b8bd3aabd81c77e
 * Entry: 0x694030; label: FUN_00694030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00694030(undefined4 param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uVar4;
  int local_18 [6];
  
  uVar4 = 0;
  if (((in_ECX == 0) || (DAT_02962b8c == 0)) || (*(int *)(in_ECX + 0x1d8) == 0)) {
    return 0;
  }
  iVar2 = FUN_00693ec0(param_1,local_18);
  if (iVar2 != 0) {
    iVar2 = 0;
    do {
      if ((local_18[iVar2] != 0) &&
         (piVar3 = (int *)FUN_00693c90(local_18[iVar2]), piVar3 != (int *)0x0)) {
        iVar1 = piVar3[6];
        if ((iVar1 == 6) || (iVar1 == 7)) {
          if ((param_2 & 1) == 0) {
            iVar1 = *piVar3;
            goto LAB_006940bf;
          }
          piVar3[0xc] = piVar3[0xc] | 1;
          piVar3[10] = -0x40800000;
        }
        else {
          if ((iVar1 != 2) && (iVar1 != 3)) goto LAB_006940de;
          iVar1 = *piVar3;
LAB_006940bf:
          FUN_00698400(iVar1 * 2);
          if (piVar3[6] != 0) {
            piVar3[6] = 0;
            piVar3[0xb] = 0;
          }
        }
        uVar4 = 1;
      }
LAB_006940de:
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
  }
  return uVar4;
}

