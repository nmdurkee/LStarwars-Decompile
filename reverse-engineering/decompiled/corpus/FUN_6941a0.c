/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x6941a0; label: FUN_006941a0
 */

undefined4 FUN_006941a0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  undefined4 uVar3;
  int local_18 [6];
  
  uVar3 = 0;
  if (((in_ECX != 0) && (DAT_02962b8c != 0)) && (*(int *)(in_ECX + 0x1d8) != 0)) {
    iVar1 = FUN_00693ec0(param_1,local_18);
    if (iVar1 != 0) {
      iVar1 = 0;
      do {
        if ((((local_18[iVar1] != 0) &&
             (piVar2 = (int *)FUN_00693c90(local_18[iVar1]), piVar2 != (int *)0x0)) &&
            ((piVar2[6] == 6 || (piVar2[6] == 7)))) && ((*(byte *)(piVar2 + 0xc) & 2) != 0)) {
          FUN_00698420(*piVar2 * 2);
          piVar2[0xc] = piVar2[0xc] & 0xfffffffd;
          uVar3 = 1;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 6);
    }
    return uVar3;
  }
  return 0;
}

