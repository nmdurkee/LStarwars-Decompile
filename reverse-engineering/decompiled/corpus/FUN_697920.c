/* Ghidra analysis pseudocode, not original source.
 * ev_7a6f44793a1ae116413d84873b30ec9fe28028ad0afd3b3275dd7a03cd0119e5
 * Entry: 0x697920; label: FUN_00697920
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00697920(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  iVar2 = param_1 * 0x34 + in_ECX;
  piVar1 = *(int **)(iVar2 + 0xc);
  *(undefined4 *)(iVar2 + 0x30) = param_2;
  if (piVar1 != (int *)0x0) {
    iVar2 = FUN_006e6b90();
    uVar3 = iVar2 + _DAT_00810dc0 & (0 < iVar2 + _DAT_00810dc0) - 1;
    if ((int)uVar3 < -10000) {
      uVar3 = 0xffffd8f0;
    }
    iVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,uVar3);
    if (iVar2 < 0) {
      FUN_00696ab0(iVar2);
    }
  }
  return;
}

