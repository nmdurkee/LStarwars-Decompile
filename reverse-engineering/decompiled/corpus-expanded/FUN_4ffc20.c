/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ffc20; label: FUN_004ffc20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ffc20(undefined4 param_1)

{
  undefined2 *puVar1;
  int *piVar2;
  undefined2 *puVar3;
  int iVar4;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_104;
  piVar2 = (int *)FUN_004f98c0(param_1);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)PTR_DAT_00800784;
  }
  (*(code *)piVar2[0x8b])(piVar2,local_104,param_1,0x100);
  if (*piVar2 == 2) {
    puVar1 = (undefined2 *)&stack0xfffffefb;
    do {
      puVar3 = puVar1;
      puVar1 = (undefined2 *)((int)puVar3 + 1);
    } while (*(char *)((int)puVar3 + 1) != '\0');
    *(undefined2 *)((int)puVar3 + 1) = 0x313b;
    *(undefined1 *)((int)puVar3 + 3) = 0;
  }
  if (*piVar2 == 1) {
    iVar4 = FUN_006def40(local_104[2] + -0x30,local_104[3] + -0x30,local_104 + piVar2[0x12]);
    if (-1 < iVar4) {
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
  }
  else {
    iVar4 = FUN_004ff570(local_104);
    if (-1 < iVar4) {
      __security_check_cookie(local_4 ^ (uint)local_104);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)local_104);
  return;
}

