/* Ghidra analysis pseudocode, not original source.
 * ev_13d7771e08adfe87253cc18d412d7fe4f6ee73edf6a45f685cbf9ffa34285398
 * Entry: 0x694100; label: FUN_00694100
 */

undefined4 FUN_00694100(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  int iVar3;
  undefined4 local_1c;
  int local_18 [6];
  
  iVar3 = 0;
  local_1c = 0;
  if (((in_ECX != 0) && (DAT_02962b8c != 0)) && (*(int *)(in_ECX + 0x1d8) != 0)) {
    iVar1 = FUN_00693ec0(param_1,local_18);
    if (iVar1 != 0) {
      do {
        if ((((local_18[iVar3] != 0) &&
             (piVar2 = (int *)FUN_00693c90(local_18[iVar3]), piVar2 != (int *)0x0)) &&
            ((piVar2[6] == 6 || (piVar2[6] == 7)))) && ((*(byte *)(piVar2 + 0xc) & 2) == 0)) {
          FUN_00698440(*piVar2 * 2);
          piVar2[0xc] = piVar2[0xc] | 2;
          local_1c = 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 6);
    }
    return local_1c;
  }
  return 0;
}

