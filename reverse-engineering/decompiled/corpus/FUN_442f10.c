/* Ghidra analysis pseudocode, not original source.
 * ev_d688ca7f3627030c52cf7630f0b7e8a4788f53f919e685b69d990e322f7866d3
 * Entry: 0x442f10; label: FUN_00442f10
 */

float10 FUN_00442f10(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined8 uVar3;
  
  if ((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) {
    iVar2 = 0;
    if (*piVar1 != 0) {
      iVar2 = *(int *)(*piVar1 + 0xea4);
    }
    if (((*(int *)(param_1 + 0x138c) != 0) && (iVar2 != 0)) &&
       (uVar3 = __allshl(),
       ((uint)uVar3 & *(uint *)(iVar2 + 0x2b0)) != 0 ||
       ((uint)((ulonglong)uVar3 >> 0x20) & *(uint *)(iVar2 + 0x2b4)) != 0)) {
      return (float10)1;
    }
  }
  return (float10)0;
}

