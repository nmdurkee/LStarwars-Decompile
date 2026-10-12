/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c6700; label: FUN_006c6700
 */

void FUN_006c6700(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_108;
  undefined1 auStack_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  local_108 = param_2;
  for (piVar1 = *(int **)(in_ECX + 8); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    if ((piVar1[7] & 0x1800000U) == 0) {
      if (piVar1[7] < 0) {
        uVar2 = (**(code **)*piVar1)(param_2);
        uVar3 = (**(code **)*piVar1)(param_1);
        FUN_006c6700(uVar3,uVar2);
        param_2 = local_108;
      }
      else {
        (**(code **)(*piVar1 + 4))(param_2,piVar1[3],auStack_104,0x100);
        (**(code **)(*piVar1 + 8))(param_1,piVar1[3],&stack0xfffffeec,0x100,0);
      }
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

