/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x443490; label: FUN_00443490
 */

float10 FUN_00443490(undefined4 param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  undefined8 uVar4;
  
  if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
     (*piVar2 != 0)) {
    if (*(char *)(*piVar2 + 0x7b5) == '\x1b') {
      iVar3 = *(int *)(*piVar2 + 0x790);
    }
    else {
      iVar3 = *(int *)(param_3 + 0xe4);
    }
    if (iVar3 != 0) {
      bVar1 = *(byte *)((int)piVar2 + 0x28d);
      uVar4 = __allshl();
      if (((uint)uVar4 & *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 8 + (uint)bVar1 * 8)) != 0
          || ((uint)((ulonglong)uVar4 >> 0x20) &
             *(uint *)(*(int *)(PTR_DAT_00802c54 + 0x298c) + 0xc + (uint)bVar1 * 8)) != 0) {
        return (float10)1;
      }
    }
  }
  return (float10)0;
}

